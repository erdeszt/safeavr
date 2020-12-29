# Misra check addon from  cppcheck

Copied from the 1.83 tag.

Running for a TARGET c file:

```
cppcheck --dump --enable=all --std=c99 -ISafeAvr/include TARGET.c
python check/misra.py TARGET.c.dump
```

