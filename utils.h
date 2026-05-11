#ifndef UTILS_H
#define UTILS_H

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
static char color_codes[6][4] = {
    "037", "033", "031", "093", "032", "034"
};

typedef struct _cube_3_state_t {
    uint64_t corners;
    uint64_t edges;
} cube_3_state_t;

typedef enum move_t {
    U = 0, UP = 1, U2 = 2,
    D = 3, DP = 4, D2 = 5,
    F = 6, FP = 7, F2 = 8,
    B = 9, BP = 10, B2 = 11,
    L = 12, LP = 13, L2 = 14,
    R = 15, RP = 16, R2 = 17,
};

int is_solved(cube_3_state_t st);
char *ctc(cube_3_state_t st, uint8_t pos_num, uint8_t face);
char *etc(cube_3_state_t st, uint8_t pos_num, uint8_t face);
uint8_t get_corner(cube_3_state_t st, uint8_t pos_num);
uint8_t get_edge(cube_3_state_t st, uint8_t pos_num);
void print_cube_3_state(cube_3_state_t st);
void print_binary64(uint64_t n);
void print_binary8(uint8_t n);
uint8_t color_to_ind(char color);

// cube_3_state_t make_move(cube_3_state_t st, enum move_t mv);
// uint64_t get_masked(uint64_t n, uint8_t start_bit);

#endif