#include "backsubst.h"
#include <math.h>

#define ZERO_TOLERANCE 1e-12

int backsubst(Matrix *x, Matrix *mat, Matrix *b) {

    if (mat->r != mat->c || b->r != mat->r || b->c != 1 || x->r != mat->r || x->c != 1)
        return 2;

    int n = mat->r;

    for (int i = n - 1; i >= 0; i--) {

        if (fabs(mat->data[i][i]) < ZERO_TOLERANCE)
            return 1;

        double sum = b->data[i][0];

        for (int j = i + 1; j < n; j++) {
            sum -= mat->data[i][j] * x->data[j][0];
        }

        x->data[i][0] = sum / mat->data[i][i];
    }

    return 0;
}
