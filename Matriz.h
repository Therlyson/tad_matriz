#ifndef __MATRIZ_H   //Verifica se o identificador __MATRIX_H não está definido.
#define __MATRIZ_H
#define ERRO_FLOAT -1e-37

//Aluno: Therlyson Ryan De Souza Santos

typedef struct matriz Matriz;


Matriz *criarMatriz (int n, int m);   

int setMatrizIJ(Matriz* mat, int i, int j, float v);   

float getMatrizIJ(Matriz* mat, int i, int j);   
Matriz *multiMatriz(Matriz *ma, Matriz *mb, int n, int m, int p, int q); 

Matriz *CalcularTransposta(Matriz* mat, int n, int m); 

int destruirMatriz(Matriz* mat); 


#endif