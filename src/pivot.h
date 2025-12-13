#ifndef _PIVOT_H
#define _PIVOT_H

#include "mat_io.h"

/*
 * Funkcja wybiera pivot - element wzgledem ktorego wykonana bedzie eliminacja
 * W razie potrzeby zamienia wiersze w A i b tak aby pivotem byl element A[c][c]
 * Zwraca 1 - macierz osobliwa
 * Zwraca 0 - pivot wybrany poprawnie
 */

int pivot(Matrix *A, Matrix *b, int c);

#endif