#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "hello_world.h"

#define printf mock_printf

static size_t mock_printf_calls = 0;
static const char* mock_printf_args1 = NULL;
static int mock_printf_return = 0;

void mock_printf_reset() {
    mock_printf_calls = 0;
    mock_printf_args1 = NULL;
    mock_printf_return = 0;
}

int mock_printf(const char *__restrict text, ...) {
    ++mock_printf_calls;
    mock_printf_args1 = text;
    return mock_printf_return;
}

int main(void) {
    mock_printf_reset();
    int ret = hello_world();
    assert(ret == 0);
    assert(mock_printf_calls == 1);
    assert(strcmp(mock_printf_args1, "hello, world\n") == 0);
}
