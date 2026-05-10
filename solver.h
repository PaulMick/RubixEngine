#ifndef SOLVER_H
#define SOLVER_H

#include <stdint.h>

#define CORNERS_SOLVED 0b0011100110001010010000011000100000100000
#define EDGEDS_SOLVED 0b010110101001001010000011100110001010010000011000100000100000

static char colors[] = {'W', 'Y', 'R', 'O', 'G', 'B'};
static uint8_t corner_color[8][3] = {
    {'W', 'G', 'R'}, {'W', 'R', 'B'}, {'W', 'O', 'G'}, {'W', 'B', 'O'}, {'Y', 'R', 'G'}, {'Y', 'B', 'R'}, {'Y', 'G', 'O'}, {'Y', 'O', 'B'}
};
static uint8_t edge_color[12][2] = {
    {'W', 'R'}, {'W', 'G'}, {'W', 'B'}, {'W', 'O'}, {'R', 'G'}, {'R', 'B'}, {'O', 'G'}, {'O', 'B'}, {'Y', 'R'}, {'Y', 'G'}, {'Y', 'B'}, {'Y', 'O'} 
};

typedef struct _cube_3_state_t {
    uint64_t corners;
    uint64_t edges;
} cube_3_state_t;

int is_solved(cube_3_state_t state);
char ctc(cube_3_state_t state, uint8_t pos_num, uint8_t face);
char etc(cube_3_state_t state, uint8_t pos_num, uint8_t face);
uint8_t get_corner(cube_3_state_t state, uint8_t pos_num);
uint8_t get_edge(cube_3_state_t state, uint8_t pos_num);
void print_cube_3_state(cube_3_state_t state);
void print_binary64(uint64_t n);
void print_binary8(uint8_t n);

#endif