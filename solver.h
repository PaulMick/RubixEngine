#ifndef SOLVER_H
#define SOLVER_H

#include "utils.h"

void solve_file(char *fin, char *fout);
void solve_input(cube_3_state_t st, char *fout);
void benchmark(int n, char *fout);

#endif