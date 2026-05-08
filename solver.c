#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "solver.h"

int is_solved(cube_3_state_t state) {
    return state.corners == CORNERS_SOLVED && state.edges == EDGEDS_SOLVED;
}

void print_cube_3_state(cube_3_state_t state) {
    
}