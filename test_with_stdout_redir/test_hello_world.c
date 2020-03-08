#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "hello_world.h"

static int file_content_matches_string(const char* file_name, const char* string) {
    FILE* file = fopen(file_name, "r");
    assert(file != NULL);
    char buffer[strlen(string) + 1];
    buffer[0] = '\0';
    fgets(buffer, sizeof(buffer), file);
    return (strlen(string) == strlen(buffer)) && (strcmp(string, buffer) == 0);
}

int main(void) {
    const char* const TEST_FILE = "/tmp/_test_hello_world.txt";
    if (freopen(TEST_FILE, "w", stdout) != NULL) {
        int exit_code = hello_world();
        fclose(stdout);

        assert(exit_code == 0);
        assert(file_content_matches_string(TEST_FILE, "Hello, World!"));
    }
    else
    {
        assert(0);
    }
}
