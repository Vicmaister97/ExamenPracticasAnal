#ifndef EXAMEN_H
#define EXAMEN_H

/* constantes */

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

/* definiciones de tipos */
typedef int (* pfunc_ordena)(int*, int, int);
/* Funciones */

int InsertQuickSort(int* tabla, int ip, int iu, int L);
int InsertQuickSort100(int* tabla, int ip, int iu);
int InsertQuickSort200(int* tabla, int ip, int iu);
int InsertQuickSort300(int* tabla, int ip, int iu);
int InsertQuickSort400(int* tabla, int ip, int iu);
int quicksort(int* tabla, int ip, int iu);
int partir(int* tabla, int ip, int iu, int *pos);
int medio(int *tabla, int ip, int iu,int *pos);
int InsertSort(int* tabla, int ip, int iu);

#endif