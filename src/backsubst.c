#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	

	int n = mat->r;
	
		for(int i = mat->c-1; i >=0; i--){
			x->data[i][0]= b->data[0][i];
			for (int j = i+1; j<n; j++){
				x->data[i][0] -= mat->data[i][j] * x->data[j][0];
			}
		}
		for (int a = 0; a <=x->r;a++){

			
			printf("%f",x->data[a][0]);
		}

				/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */

				int i;
				for (i =0; i < x->r; i++) {
								x->data[i][0] = b->data[i][0];
				}

				return 0;
}


