#include <unity.h>
#include <safeavr/gpio.h>

#define NUMBER_OF_PINS 8
#define NUMBER_OF_MODES 2
#define NUMBER_OF_LEVELS 2

enum gpio_pin pins[NUMBER_OF_PINS] = { PIN0, PIN1, PIN2, PIN3,
                                       PIN4, PIN5, PIN6, PIN7 };
enum gpio_mode modes[NUMBER_OF_MODES] = { GPIO_INPUT, GPIO_OUTPUT };
enum gpio_logic_level levels[NUMBER_OF_LEVELS] = { GPIO_LOW, GPIO_HIGH };

/* Iterator for collections of pins, modes and levels */
#define FORALL(var, type, in, count)                                           \
    enum type var = in[0];                                                     \
    for (u8 var##_index = 0; var##_index < count;                              \
         var##_index++, var = in[var##_index])

#define FORALL_PINS(var) FORALL(var, gpio_pin, pins, NUMBER_OF_PINS)
#define FORALL_MODES(var) FORALL(var, gpio_mode, modes, NUMBER_OF_MODES)
#define FORALL_LEVELS(var)                                                     \
    FORALL(var, gpio_logic_level, levels, NUMBER_OF_LEVELS)

void clear_registers()
{
    GPIOB->direction_register = 0;
    GPIOB->input_register = 0;
    GPIOB->output_register = 0;
    GPIOC->direction_register = 0;
    GPIOC->input_register = 0;
    GPIOC->output_register = 0;
    GPIOD->direction_register = 0;
    GPIOD->input_register = 0;
    GPIOD->output_register = 0;
}

void panic(void)
{
    TEST_FAIL_MESSAGE("PANIC");
}

void blackbox_gpio_init_all_pins_all_modes(void)
{
    FORALL_PINS(pin)
    {
        FORALL_MODES(mode)
        {
            const struct gpio_init_config config = { .mode = mode, .pin = pin };

            const enum gpio_status status = gpio_init(GPIOB, &config);

            TEST_ASSERT_EQUAL(status, GPIO_SUCCESS);
        }
    }
}

void blackbox_gpio_init_invalid_gpio(void)
{
    const struct gpio_init_config config = { .mode = GPIO_OUTPUT, .pin = PIN0 };

    const enum gpio_status status = gpio_init(NULL, &config);

    TEST_ASSERT_EQUAL(status, GPIO_INVALID_DEFINITION);
}

void blackbox_gpio_write_all_pins_all_levels(void)
{
    FORALL_PINS(pin)
    {
        FORALL_LEVELS(level)
        {
            const struct gpio_init_config config = { .mode = GPIO_OUTPUT,
                                                     .pin = pin };
            (void)gpio_init(GPIOB, &config);

            const enum gpio_status status = gpio_write(GPIOB, pin, level);

            TEST_ASSERT_EQUAL(status, GPIO_SUCCESS);
        }
    }
}

void blackbox_gpio_write_invalid_gpio(void)
{
    const struct gpio_init_config config = { .mode = GPIO_OUTPUT, .pin = PIN0 };
    (void)gpio_init(GPIOB, &config);

    const enum gpio_status status = gpio_write(NULL, PIN0, GPIO_HIGH);

    TEST_ASSERT_EQUAL(status, GPIO_INVALID_DEFINITION);
}

void blackbox_gpio_write_invalid_mode(void)
{
    const struct gpio_init_config config = { .mode = GPIO_INPUT, .pin = PIN0 };
    (void)gpio_init(GPIOB, &config);

    const enum gpio_status status = gpio_write(GPIOB, PIN0, GPIO_HIGH);

    TEST_ASSERT_EQUAL(status, GPIO_INVALID_MODE);
}

void blackbox_gpio_read_all_pins(void)
{
    FORALL_PINS(pin)
    {
        enum gpio_logic_level level = GPIO_HIGH;
        const struct gpio_init_config config = { .mode = GPIO_INPUT,
                                                 .pin = pin };
        (void)gpio_init(GPIOB, &config);

        const enum gpio_status status = gpio_read(GPIOB, pin, &level);

        TEST_ASSERT_EQUAL(status, GPIO_SUCCESS);
        TEST_ASSERT_EQUAL(level, GPIO_LOW);
    }
}

void blackbox_gpio_read_invalid_gpio(void)
{
    enum gpio_logic_level level = GPIO_HIGH;
    const struct gpio_init_config config = { .mode = GPIO_INPUT, .pin = PIN0 };
    (void)gpio_init(GPIOB, &config);

    const enum gpio_status status = gpio_read(NULL, PIN0, &level);

    TEST_ASSERT_EQUAL(status, GPIO_INVALID_DEFINITION);
    TEST_ASSERT_EQUAL(level, GPIO_HIGH);
}

void blackbox_gpio_read_invalid_mode(void)
{
    enum gpio_logic_level level = GPIO_HIGH;
    const struct gpio_init_config config = { .mode = GPIO_OUTPUT, .pin = PIN0 };
    (void)gpio_init(GPIOB, &config);

    const enum gpio_status status = gpio_read(GPIOB, PIN0, &level);

    TEST_ASSERT_EQUAL(status, GPIO_INVALID_MODE);
    TEST_ASSERT_EQUAL(level, GPIO_HIGH);
}

void setUp(void)
{
    clear_registers();
}

void tearDown(void)
{
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(blackbox_gpio_init_all_pins_all_modes);
    RUN_TEST(blackbox_gpio_init_invalid_gpio);
    RUN_TEST(blackbox_gpio_write_all_pins_all_levels);
    RUN_TEST(blackbox_gpio_write_invalid_gpio);
    RUN_TEST(blackbox_gpio_write_invalid_mode);
    RUN_TEST(blackbox_gpio_read_all_pins);
    RUN_TEST(blackbox_gpio_read_invalid_gpio);
    RUN_TEST(blackbox_gpio_read_invalid_mode);

    return UNITY_END();
}

