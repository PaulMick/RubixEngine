#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "solver.h"

int is_solved(cube_3_state_t state) {
    return state.corners == CORNERS_SOLVED && state.edges == EDGEDS_SOLVED;
}

char corner_to_color(uint8_t corner, uint8_t face) {

}

char edge_to_color(uint8_t edge, uint8_t face) {

}

void print_cube_3_state(cube_3_state_t state) {
    printf("   %c%c%c   \n", '-', '-', '-');
    printf("   %c%c%c   \n", '-', 'O', '-');
    printf("   %c%c%c   \n", '-', '-', '-');
    printf("%c%c%c%c%c%c%c%c%c\n", '-', '-', '-', '-', '-', '-', '-', '-', '-');
    printf("%c%c%c%c%c%c%c%c%c\n", '-', 'G', '-', '-', 'W', '-', '-', 'B', '-');
    printf("%c%c%c%c%c%c%c%c%c\n", '-', '-', '-', '-', '-', '-', '-', '-', '-');
    printf("   %c%c%c   \n", '-', '-', '-');
    printf("   %c%c%c   \n", '-', 'R', '-');
    printf("   %c%c%c   \n", '-', '-', '-');
    printf("   %c%c%c   \n", '-', '-', '-');
    printf("   %c%c%c   \n", '-', 'Y', '-');
    printf("   %c%c%c   \n", '-', '-', '-');
}