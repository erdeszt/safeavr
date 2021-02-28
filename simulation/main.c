#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// TODO: In build:
// #define CONFIG_MEGA328 1

#include "avr_ioport.h"
#include "sim_elf.h"
#include "sim_avr.h"
#include "sim_vcd_file.h"

int main(void)
{
    avr_t *avr = NULL;
    avr_vcd_t vcd_file;
    /* TODO: Use args */
    char should_debug_input[5] = { 0 };

    printf("Should debug? ");
    scanf("%s", should_debug_input);
    getchar();

    const bool should_debug = strcmp(should_debug_input, "yes") == 0;

    elf_firmware_t f;

    const int32_t elf_read_result =
        elf_read_firmware("../examples/serial.elf", &f);

    if (elf_read_result == 0) {
        printf("MMCU: `%s`, symbol count: %d\n", f.mmcu, f.symbolcount);
    } else {
        printf("Not good: %d\n", elf_read_result);

        return EXIT_FAILURE;
    }

    avr = avr_make_mcu_by_name("atmega328p");

    avr_init(avr);
    avr_load_firmware(avr, &f);

    if (should_debug) {
        avr->gdb_port = 1234;
        avr->state = cpu_Stopped;
        avr_gdb_init(avr);

        printf("Enter a char to start\n");
        getchar();
        printf("Starting\n");
    } else {
        avr_vcd_init(avr, "portb_output.vcd", &vcd_file, 1000 /* usec */);
        avr_vcd_add_signal(&vcd_file,
                           avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('B'),
                                         IOPORT_IRQ_PIN0),
                           1 /* bits */, "portb");
        avr_vcd_start(&vcd_file);
    }

    int32_t state = cpu_Running;

    uint64_t cycle = 0;

    while ((state != cpu_Done) && (state != cpu_Crashed)) {
        cycle++;
        state = avr_run(avr);

        if (!should_debug && cycle > 20000000) {
            break;
        }
    }

    if (!should_debug) {
        avr_vcd_stop(&vcd_file);
    }

    return EXIT_SUCCESS;
}
