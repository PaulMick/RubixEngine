#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "utils.h"

cube_3_state_t make_move(cube_3_state_t st, enum move_t mv) {
    uint64_t new_corners = st.corners;
    uint64_t new_edges = st.edges;
    switch (mv) {
        case U:
            set_masked(&new_corners, get_masked(st.corners, 0), 2);
            set_masked(&new_corners, get_masked(st.corners, 1), 0);
            set_masked(&new_corners, get_masked(st.corners, 2), 3);
            set_masked(&new_corners, get_masked(st.corners, 3), 1);
        default: return st;
    }
}

uint64_t get_masked(uint64_t n, uint8_t ind) {
    return n & (0b11111 << ind * 5);
}

void set_masked(uint64_t *dest, uint64_t val, uint8_t ind) {
    *dest = (*dest & (~(0b11111 << ind * 5))) | val;
}

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
    char *s;
    if (color == 'O') {
        s = malloc(sizeof(char) * 18);
        sprintf(s, "%sm%c", color_codes[color_to_ind(color)], color);
        s[17] = '\0';
    } else {
        s = malloc(sizeof(char) * 8);
        sprintf(s, "%sm%c", color_codes[color_to_ind(color)], color);
        s[7] = '\0';
    }
    return s;
}

char *etc(cube_3_state_t state, uint8_t pos_num, uint8_t face) {
    uint8_t edge = get_edge(state, pos_num);
    uint8_t rot = edge >> 4;
    char color = edge_color[edge & 0b1111][(rot + face) % 2];
    // printf("pos_num: %d, face: %d, rot: %d, color: %c\n", pos_num, face, rot, color);
    // printf("%d, %d\n", edge & 0b1111, (rot + face) % 2);
    char *s;
    if (color == 'O') {
        s = malloc(sizeof(char) * 18);
        sprintf(s, "%sm%c", color_codes[color_to_ind(color)], color);
        s[17] = '\0';
    } else {
        s = malloc(sizeof(char) * 8);
        sprintf(s, "%sm%c", color_codes[color_to_ind(color)], color);
        s[7] = '\0';
    }
    return s;
}

uint8_t get_corner(cube_3_state_t state, uint8_t pos_num) {
    return (state.corners >> (5 * pos_num)) & 0b11111;
}

uint8_t get_edge(cube_3_state_t state, uint8_t pos_num) {
    return (state.edges >> (5 * pos_num)) & 0b11111;
}

void print_cube_3_state(cube_3_state_t st) {
    char *cs[48];
    cs[0] =  ctc(st, 6, 2);
    cs[1] = etc(st, 3, 1);
    cs[2] = ctc(st, 7, 1);
    cs[3] = etc(st, 6, 0);
    cs[4] = etc(st, 7, 0);
    cs[5] = ctc(st, 2, 1);
    cs[6] = etc(st, 11, 1);
    cs[7] = ctc(st, 3, 2);
    cs[8] = ctc(st, 6, 1); 
    cs[9] = etc(st, 1, 1);
    cs[10] = ctc(st, 2, 2);
    cs[11] = ctc(st, 2, 0);
    cs[12] = etc(st, 3, 0);
    cs[13] = ctc(st, 3, 0);
    cs[14] = ctc(st, 3, 1);
    cs[15] = etc(st, 2, 1);
    cs[16] = ctc(st, 7, 2);
    cs[17] = etc(st, 6, 1);
    cs[18] = etc(st, 4, 1);
    cs[19] = etc(st, 1, 0);
    cs[20] = etc(st, 2, 0);
    cs[21] = etc(st, 5, 1);
    cs[22] = etc(st, 7, 1);
    cs[23] = ctc(st, 4, 2); 
    cs[24] = etc(st, 9, 1);
    cs[25] = ctc(st, 0, 1);
    cs[26] = ctc(st, 0, 0);
    cs[27] = etc(st, 0, 0);
    cs[28] = ctc(st, 1, 0);
    cs[29] = ctc(st, 1, 2);
    cs[30] = etc(st, 10, 1);
    cs[31] = ctc(st, 5, 1);
    cs[32] = ctc(st, 0, 2);
    cs[33] = etc(st, 0, 1);
    cs[34] = ctc(st, 1, 1);
    cs[35] = etc(st, 4, 0);
    cs[36] = etc(st, 5, 0);
    cs[37] = ctc(st, 4, 1);
    cs[38] = etc(st, 8, 1);
    cs[39] = ctc(st, 5, 2);
    cs[40] = ctc(st, 4, 0);
    cs[41] = etc(st, 8, 0);
    cs[42] = ctc(st, 5, 0);
    cs[43] = etc(st, 9, 0);
    cs[44] = etc(st, 10, 0);
    cs[45] = ctc(st, 6, 0);
    cs[46] = etc(st, 11, 0);
    cs[47] = ctc(st, 7, 0);
    printf("   \033[%s\033[0m\033[%s\033[0m\033[%s\033[0m   \n", cs[0], cs[1], cs[2]);
    printf("   \033[%s\033[0m\033[%s\033[0m\033[%s\033[0m   \n", cs[3], "38;2;255;165;0mO", cs[4]);
    printf("   \033[%s\033[0m\033[%s\033[0m\033[%s\033[0m   \n", cs[5], cs[6], cs[7]);
    printf("\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\n", cs[8], cs[9], cs[10], cs[11], cs[12], cs[13], cs[14], cs[15], cs[16]);
    printf("\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\n", cs[17], "0;032mG", cs[18], cs[19], "0;037mW", cs[20], cs[21], "0;034mB", cs[22]);
    printf("\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\033[%s\033[0m\n", cs[23], cs[24], cs[25], cs[26], cs[27], cs[28], cs[29], cs[30], cs[31]);
    printf("   \033[%s\033[0m\033[%s\033[0m\033[%s\033[0m   \n", cs[32], cs[33], cs[34]);
    printf("   \033[%s\033[0m\033[%s\033[0m\033[%s\033[0m   \n", cs[35], "0;031mR", cs[36]);
    printf("   \033[%s\033[0m\033[%s\033[0m\033[%s\033[0m   \n", cs[37], cs[38], cs[39]);
    printf("   \033[%s\033[0m\033[%s\033[0m\033[%s\033[0m   \n", cs[40], cs[41], cs[42]);
    printf("   \033[%s\033[0m\033[%s\033[0m\033[%s\033[0m   \n", cs[43], "0;033mY", cs[44]);
    printf("   \033[%s\033[0m\033[%s\033[0m\033[%s\033[0m   \n", cs[45], cs[46], cs[47]);
    for (int i = 0; i < 48; i ++) {
        free(cs[i]);
    }
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