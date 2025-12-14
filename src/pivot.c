#include "pivot.h"

#include <math.h>
#define CLOSE_TO_ZERO 1e-12


void swap_rows(int row1, int row2, Matrix *mat){
    int colum = mat->c;
    if (r1 == r2)
        return;
    for (int i = 0; i < cols; i++){
        double tmp = mat->data[row1][c];
        mat->data[row1][i] = m->data[row2][i];
        mat->data[row2][i] = tmp;
    }
    
}

int pivot(Matrix *mat, Matrix *b, int c){
    int rows = mat->r;
    int pivot = c;
    for (int r = c; r < rows; r++){
        if (fabs(mat->data[r][c]) > fabs(mat->data[pivot][c]))
            pivot = r;
    }

    if (fabs(mat->data[pivot][c]) <CLOSE_TO_ZERO)
        return 1;

    swap_rows(pivot, c, mat);
    swap_rows(pivot, c, b);

    return 0;
}