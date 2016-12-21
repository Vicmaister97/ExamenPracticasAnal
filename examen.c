#include <stdio.h>
#include <stdlib.h>
#include "examen.h"

int InsertQuickSort(int* tabla, int ip, int iu, int L){
	int m;
	int *pos = NULL;
	int ob = 0;
	int tamanio = 0;

	if(tabla == NULL) return ERR;

	pos = (int *)malloc(sizeof(pos[0]));
	if (pos == NULL)
		return ERR;

	tamanio = (iu-ip)+1;
	if (tamanio < L)
		ob += InsertSort(tabla, ip, iu); /*No comprobamos lo que devuelve InsertSort porque sólo da error si tabla == NULL*/
	
	else{
		if (ip > iu){
			free (pos);
			return ERR;
		}

		if (ip == iu){
			free (pos);
			return ob;
		}

		else{
			ob = partir(tabla, ip, iu, pos);
			if (ob == ERR){
				free (pos);
				return ERR;
			}

			m = *pos;

			if (ip < m){
				ob += InsertQuickSort (tabla, ip, m-1, L);
				if (ob == ERR){
					free (pos);
					return ERR;
				}
			}
			if (m+1 < iu){
				ob += InsertQuickSort (tabla, m+1, iu, L);
				if (ob == ERR){
					free (pos);
					return ERR;
				}
			}

		}
	}
		
	free (pos);
	return ob;
}

int InsertQuickSort100(int* tabla, int ip, int iu){
	return InsertQuickSort(tabla, ip, iu, 100);
}

int InsertQuickSort200(int* tabla, int ip, int iu){
	return InsertQuickSort(tabla, ip, iu, 200);
}

int InsertQuickSort300(int* tabla, int ip, int iu){
	return InsertQuickSort(tabla, ip, iu, 300);
}

int InsertQuickSort400(int* tabla, int ip, int iu){
	return InsertQuickSort(tabla, ip, iu, 400);
}

int quicksort(int* tabla, int ip, int iu){
	int m;
	int *pos = NULL;
	int ob = 0;

	pos = (int *)malloc(sizeof(pos[0]));
	if (pos == NULL)
		return ERR;
	
	if (ip > iu){
		free (pos);
		return ERR;
	}

	if (ip == iu){
		free (pos);
		return ob;
	}

	else{
		ob = partir(tabla, ip, iu, pos);
		if (ob == ERR){
			free (pos);
			return ERR;
		}

		m = *pos;

		if (ip < m){
			ob += quicksort (tabla, ip, m-1);
			if (ob == ERR){
				free (pos);
				return ERR;
			}
		}
		if (m+1 < iu){
			ob += quicksort (tabla, m+1, iu);
			if (ob == ERR){
				free (pos);
				return ERR;
			}
		}

	}
	free (pos);
	return ob;
}

int partir(int* tabla, int ip, int iu,int *pos){
	int m;
	int k;
	int aux;
	int i;
	int ob;

	ob = medio (tabla, ip, iu, pos);
	if (ob == ERR)
		return ERR;

	m = *pos;
	k = tabla[m];

	aux = tabla[ip];
	tabla[ip] = tabla[m];
	tabla[m] = aux;

	m = ip;

	for (i = ip +1; i <= iu; i++){
		if (tabla[i] < k){
			m++;
			aux = tabla[i];
	        tabla[i] = tabla[m];
	        tabla[m] = aux;
		}
		ob ++;
	}

	
	aux = tabla[ip];
	tabla[ip] = tabla[m];
	tabla[m] = aux;

	*pos = m;

	return ob;
}

int medio(int *tabla, int ip, int iu,int *pos){
	*pos = ip;
	return 0;
}

int InsertSort(int* tabla, int ip, int iu)
{
	int cont = 0;
	int i;
	if (tabla == NULL) return ERR;
		for (i = ip + 1; i <= iu; i++){ 
			int j = i-1;
			int aux = tabla[i];
			while (j >= ip && tabla[j] > aux){
		    		tabla[j+1] = tabla[j];
		    		j--;
		    		cont++;
		    		}
			cont++;
			tabla[j+1] = aux;
		}
	return cont;
}