#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "solver.h"

int main(int argc, char **argv) {
    print_cube_3_state((cube_3_state_t) {0});
    if (argc != 3 && argc != 4) {
        fprintf(stderr, "Error: Invalid number of arguments, requires 2 or 3, got %d\n", argc - 1);
    }
    if (strcmp(argv[1], "solve") == 0) {

    } else if (strcmp(argv[1], "test") == 0) {

    }

    return EXIT_SUCCESS;
}