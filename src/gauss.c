#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int rows = mat->r;
	int cols = mat->c;

	for (int c = 0; c < cols - 1; c++){
		//uproszczona wersja gdzie zakladamy pivot rozny od zera
		double pivot = mat->data[c][c];

		for (int r = c + 1; r < rows; r++){
			double m = mat->data[r][c] / pivot;
			for (int i = c; i < cols; i++){
				mat->data[r][i] -= m * mat->data[c][i];
			}

			b->data[r][0] -= m * b->data[c][0];
		}
		
	}
	return 0;
}

