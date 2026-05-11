#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "utils.h"

int main(int argc, char **argv) {
    cube_3_state_t cst = {.corners = CORNERS_SOLVED, .edges = EDGEDS_SOLVED};
    print_cube_3_state(cst);
    if (argc != 3 && argc != 4) {
        printf("Error: Invalid number of arguments, requires 2 or 3, got %d\n", argc - 1);
        return EXIT_FAILURE;
    }
    if (strcmp(argv[1], "solve") == 0) {

    } else if (strcmp(argv[1], "test") == 0) {

    }

    return EXIT_SUCCESS;
}