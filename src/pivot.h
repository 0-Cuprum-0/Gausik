#ifndef _PIVOT_H
#define _PIVOT_H

#include "mat_io.h"

void swap_rows(int row1, int row2, Matrix *mat);
int pivot(Matrix *mat, Matrix *b, int c);