#include "gauss.h"
#include "pivot.h"
#include <math.h>
#define ZERO_TOLERANCE 1e-12
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int rows = mat->r;
	int cols = mat->c;

	for (int c = 0; c < cols - 1; c++){
		
		if (pivot(mat, b, c)){
			return 1;
		}
		double pivot_element = mat->data[c][c];
		for (int r = c + 1; r < rows; r++){
			double m = mat->data[r][c] / pivot_element;
			for (int i = c; i < cols; i++){
				mat->data[r][i] -= m * mat->data[c][i];
			}

			b->data[r][0] -= m * b->data[c][0];
		}
		
	}

	for (int k = 0; k < cols && k < rows; k++){
		if (fabs(mat->data[k][k]) < ZERO_TOLERANCE)
			return 1;
	}
	
	return 0;
}

