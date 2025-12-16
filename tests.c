#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "mat_io.h"
#include "pivot.h"
#include "gauss.h"
#define ZERO_TOLERANCE 1e-12


int are_matrices_equal(Matrix *A, Matrix *B){
    if (A->r != B->r || A->c != B->c)
        return 0;

    for (int i = 0; i < A->r; i++){
        for (int j = 0; j < A->c; j++){
            if (fabs(A->data[i][j] - B->data[i][j]) > ZERO_TOLERANCE)
                return 0;
        }
    }
    return 1;
}

void test_pivot_swap(void){
    Matrix *A = createMatrix(2, 2);
    Matrix *b = createMatrix(2, 1);

    A->data[0][0] = 0;  A->data[0][1] = 1;
    A->data[1][0] = 2;  A->data[1][1] = 3;

    b->data[0][0] = 1;
    b->data[1][0] = 2;

    Matrix *A_expected = createMatrix(2, 2);
    Matrix *b_expected = createMatrix(2, 1);

    A_expected->data[0][0] = 2;  A_expected->data[0][1] = 3;
    A_expected->data[1][0] = 0;  A_expected->data[1][1] = 1;

    b_expected->data[0][0] = 2;
    b_expected->data[1][0] = 1;

    int res = pivot(A, b, 0);

    assert(res == 0);
    assert(are_matrices_equal(A, A_expected));
    assert(are_matrices_equal(b, b_expected));

    freeMatrix(A);
    freeMatrix(b);
    freeMatrix(A_expected);
    freeMatrix(b_expected);

    printf("test_pivot_swap OK\n");
}

void test_pivot_singular(void){
    Matrix *A = createMatrix(2, 2);
    Matrix *b = createMatrix(2, 1);

    A->data[0][0] = 0;  A->data[0][1] = 1;
    A->data[1][0] = 0;  A->data[1][1] = 2;

    b->data[0][0] = 1;
    b->data[1][0] = 2;

    int res = pivot(A, b, 0);

    assert(res == 1);

    freeMatrix(A);
    freeMatrix(b);

    printf("test_pivot_singular OK\n");
}

void test_eliminate_simple(void){
    Matrix *A = createMatrix(2, 2);
    Matrix *b = createMatrix(2, 1);

    A->data[0][0] = 2;  A->data[0][1] = 1;
    A->data[1][0] = 1;  A->data[1][1] = 1;

    b->data[0][0] = 5;
    b->data[1][0] = 3;

    Matrix *A_expected = createMatrix(2, 2);
    Matrix *b_expected = createMatrix(2, 1);

    A_expected->data[0][0] = 2;   A_expected->data[0][1] = 1;
    A_expected->data[1][0] = 0;   A_expected->data[1][1] = 0.5;

    b_expected->data[0][0] = 5;
    b_expected->data[1][0] = 0.5;

    int res = eliminate(A, b);

    assert(res == 0);
    assert(are_matrices_equal(A, A_expected));
    assert(are_matrices_equal(b, b_expected));

    freeMatrix(A);
    freeMatrix(b);
    freeMatrix(A_expected);
    freeMatrix(b_expected);

    printf("test_eliminate_simple OK\n");
}

void test_eliminate_singular(void){
    Matrix *A = createMatrix(2, 2);
    Matrix *b = createMatrix(2, 1);

    A->data[0][0] = 1;  A->data[0][1] = 2;
    A->data[1][0] = 2;  A->data[1][1] = 4;

    b->data[0][0] = 3;
    b->data[1][0] = 6;

    int res = eliminate(A, b);

    assert(res == 1);

    freeMatrix(A);
    freeMatrix(b);

    printf("test_eliminate_singular OK\n");
}

int main(void){
    test_pivot_swap();
    test_pivot_singular();
    test_eliminate_simple();
    test_eliminate_singular();

    printf("Wszystkie testy OK\n");
    return 0;
}
