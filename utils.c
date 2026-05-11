#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "utils.h"

// cube_3_state_t make_move(cube_3_state_t st, enum move_t mv) {
//     uint64_t new_corners;
//     uint64_t new_edges;
//     switch (mv) {
//         case U:
            
//         default: return st;
//     }
// }

// uint64_t get_masked(uint64_t n, uint8_t start_bit) {
    
// }

int is_solved(cube_3_state_t state) {
    return state.corners == CORNERS_SOLVED && state.edges == EDGEDS_SOLVED;
}

char *ctc(cube_3_state_t state, uint8_t pos_num, uint8_t face) {
    uint8_t corner = get_corner(state, pos_num);
    uint8_t rot = corner >> 3;
    char color = corner_color[corner & 0b111][(rot + face) % 3];
    // printf("state: ");
    // print_binary64(state.corners);
    // printf("\n");
    // printf("pos_num: %d, color: %c, corner: %d, rot: %d, face: %d\n", pos_num, color, corner, rot, face);
    // printf("ind2: %d\n", (rot + face) % 3);
    char *s = malloc(sizeof(char) * 6);
    sprintf(s, "%sm%c", color_codes[color_to_ind(color)], color);
    // printf("%s\n", s);
    s[5] = '\0';
    return s;
}

char *etc(cube_3_state_t state, uint8_t pos_num, uint8_t face) {
    uint8_t edge = get_edge(state, pos_num);
    uint8_t rot = edge >> 4;
    char color = edge_color[edge & 0b1111][(rot + face) % 2];
    // printf("pos_num: %d, face: %d, rot: %d, color: %c\n", pos_num, face, rot, color);
    // printf("%d, %d\n", edge & 0b1111, (rot + face) % 2);
    char *s = malloc(sizeof(char) * 6);
    sprintf(s, "%sm%c", color_codes[color_to_ind(color)], color);
    s[5] = '\0';
    return s;
}

uint8_t get_corner(cube_3_state_t state, uint8_t pos_num) {
    return (state.corners >> (5 * pos_num)) & 0b11111;
}

uint8_t get_edge(cube_3_state_t state, uint8_t pos_num) {
    return (state.edges >> (5 * pos_num)) & 0b11111;
}

void print_cube_3_state(cube_3_state_t st) {
    printf("   \033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m   \n", ctc(st, 6, 2), etc(st, 3, 1), ctc(st, 7, 1));
    printf("   \033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m   \n", etc(st, 6, 0), "202mO", etc(st, 7, 0));
    printf("   \033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m   \n", ctc(st, 2, 1), etc(st, 11, 1), ctc(st, 3, 2));
    printf("\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\n", ctc(st, 6, 1), etc(st, 1, 1), ctc(st, 2, 2), ctc(st, 2, 0), etc(st, 3, 0), ctc(st, 3, 0), ctc(st, 3, 1), etc(st, 2, 1), ctc(st, 7, 2));
    printf("\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\n", etc(st, 6, 1), "032mG", etc(st, 4, 1), etc(st, 1, 0), "037mW", etc(st, 2, 0), etc(st, 5, 1), "034mB", etc(st, 7, 1));
    printf("\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m\n", ctc(st, 4, 2), etc(st, 9, 1), ctc(st, 0, 1), ctc(st, 0, 0), etc(st, 0, 0), ctc(st, 1, 0), ctc(st, 1, 2), etc(st, 10, 1), ctc(st, 5, 1));
    printf("   \033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m   \n", ctc(st, 0, 2), etc(st, 0, 1), ctc(st, 1, 1));
    printf("   \033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m   \n", etc(st, 4, 0), "031mR", etc(st, 5, 0));
    printf("   \033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m   \n", ctc(st, 4, 1), etc(st, 8, 1), ctc(st, 5, 2));
    printf("   \033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m   \n", ctc(st, 4, 0), etc(st, 8, 0), ctc(st, 5, 0));
    printf("   \033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m   \n", etc(st, 9, 0), "033mY", etc(st, 10, 0));
    printf("   \033[0;%s\033[0m\033[0;%s\033[0m\033[0;%s\033[0m   \n", ctc(st, 6, 0), etc(st, 11, 0), ctc(st, 7, 0));
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

uint8_t color_to_ind(char color) {
    switch (color) {
        case 'W': return 0;
        case 'Y': return 1;
        case 'R': return 2;
        case 'O': return 3;
        case 'G': return 4;
        case 'B': return 5;
        default: return -1;
    }
}