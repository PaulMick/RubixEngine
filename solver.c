#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define DEPTH 7

void solve_input(cube_3_state_t st, char *fout) {
    
}

void solve_file(char *fin, char *fout) {
    FILE *fpin = fopen(fin, "r");
    if (fpin == NULL) {
        return NULL;
    }
    cube_3_state_t st;
    fread(&(st.corners), sizeof(uint64_t), 1, fpin);
    fread(&(st.edges), sizeof(uint64_t), 1, fpin);
    fclose(fpin);
    solve_input(st, fout);
}

void benchmark(int n, char *fout) {
    
}