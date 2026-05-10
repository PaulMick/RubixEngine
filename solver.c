#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "solver.h"

int is_solved(cube_3_state_t state) {
    return state.corners == CORNERS_SOLVED && state.edges == EDGEDS_SOLVED;
}

char ctc(cube_3_state_t state, uint8_t pos_num, uint8_t face) {
    uint8_t corner = get_corner(state, pos_num);
    uint8_t rot = corner >> 3;
    char color = corner_color[corner & 0b111][(rot + face) % 3];
    // printf("state: ");
    // print_binary64(state.corners);
    // printf("\n");
    // printf("pos_num: %d, color: %c, corner: %d, rot: %d, face: %d\n", pos_num, color, corner, rot, face);
    // printf("ind2: %d\n", (rot + face) % 3);
    return color;
}

char etc(cube_3_state_t state, uint8_t pos_num, uint8_t face) {
    uint8_t edge = get_edge(state, pos_num);
    uint8_t rot = edge >> 4;
    char color = edge_color[edge & 0b1111][(rot + face) % 2];
    // printf("pos_num: %d, face: %d, rot: %d, color: %c\n", pos_num, face, rot, color);
    // printf("%d, %d\n", edge & 0b1111, (rot + face) % 2);
    return color;
}

uint8_t get_corner(cube_3_state_t state, uint8_t pos_num) {
    return (state.corners >> (5 * pos_num)) & 0b11111;
}

uint8_t get_edge(cube_3_state_t state, uint8_t pos_num) {
    return (state.edges >> (5 * pos_num)) & 0b11111;
}

void print_cube_3_state(cube_3_state_t st) {
    printf("   %c%c%c   \n", ctc(st, 6, 2), '-', ctc(st, 7, 1));
    printf("   %c%c%c   \n", '-', 'O', '-');
    printf("   %c%c%c   \n", ctc(st, 2, 1), '-', ctc(st, 3, 2));
    printf("%c%c%c%c%c%c%c%c%c\n", ctc(st, 6, 1), '-', ctc(st, 2, 2), ctc(st, 2, 0), etc(st, 3, 0), ctc(st, 3, 0), ctc(st, 3, 1), '-', ctc(st, 7, 2));
    printf("%c%c%c%c%c%c%c%c%c\n", '-', 'G', '-', etc(st, 1, 0), 'W', etc(st, 2, 0), '-', 'B', '-');
    printf("%c%c%c%c%c%c%c%c%c\n", ctc(st, 4, 2), '-', ctc(st, 0, 1), ctc(st, 0, 0), etc(st, 0, 0), ctc(st, 1, 0), ctc(st, 1, 2), '-', ctc(st, 5, 1));
    printf("   %c%c%c   \n", ctc(st, 0, 2), etc(st, 0, 1), ctc(st, 1, 1));
    printf("   %c%c%c   \n", '-', 'R', '-');
    printf("   %c%c%c   \n", ctc(st, 4, 1), '-', ctc(st, 5, 2));
    printf("   %c%c%c   \n", ctc(st, 4, 0), '-', ctc(st, 5, 0));
    printf("   %c%c%c   \n", '-', 'Y', '-');
    printf("   %c%c%c   \n", ctc(st, 6, 0), '-', ctc(st, 7, 0));
}

void print_binary64(uint64_t n) {
    for (int i = 0; i < 64; i ++) {
        printf("%d", (int) (n >> 63 - i) & 1);
    }
}

void print_binary8(uint8_t n) {
    for (int i = 0; i < 8; i ++) {
        printf("%d", (n >> 7 - i) & 1);
    }
}