#include "hello_world.h"

#define DELIBERATE_BUG

#include <stdio.h>

int hello_world() {
#ifdef DELIBERATE_BUG
    // Deliberate mistake: use '1' characters instead of 'l' to force unit test
    // to fail.
    printf("he11o, wor1d\n");
#else
    printf("hello, world\n");
#endif

    return 0;
}
