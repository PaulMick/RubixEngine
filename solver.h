#ifndef SOLVER_H
#define SOLVER_H

#include <stdint.h>

#define CORNERS_SOLVED 0b001010010000011000100000100000
#define EDGEDS_SOLVED 0b010110101001001010000011100110001010010000011000100000100000

typedef struct _cube_3_state_t {
    uint64_t corners;
    uint64_t edges;
} cube_3_state_t;

int is_solved(cube_3_state_t state);
void print_cube_3_state(cube_3_state_t state);

#endif