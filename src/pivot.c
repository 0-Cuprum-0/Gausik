#include "pivot.h"
#include <math.h>
#define ZERO_TOLERANCE 1e-12


void swap_rows(int r1, int r2, Matrix *m){
    if (r1 == r2)
        return;
    int cols = m->c;
    for (int c = 0; c < cols; c++){
        double tmp = m->data[r1][c];
        m->data[r1][c] = m->data[r2][c];
        m->data[r2][c] = tmp;
    }
    
}

int pivot(Matrix *mat, Matrix *b, int c){
    int rows = mat->r;
    int max_r = c;

    for (int r = c; r < rows; r++){
        if (fabs(mat->data[r][c]) > fabs(mat->data[max_r][c]))
            max_r = r;
    }

    if (fabs(mat->data[max_r][c]) <  ZERO_TOLERANCE)
        return 1;

    swap_rows(max_r, c, mat);
    swap_rows(max_r, c, b);

    return 0;
}
