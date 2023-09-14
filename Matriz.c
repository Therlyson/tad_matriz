#ifndef __MATRIZ_C
#define __MATRIZ_C
#include <stdlib.h> 
#include <stdio.h>
#include "matriz.h"

//Aluno: Therlyson Ryan De Souza Santos

typedef struct matriz{
    int linha;
    int coluna;
    float *vetor;
}Matriz;

Matriz *criarMatriz(int n, int m){    //retorna um ponteiro para uma estrutura do tipo Matriz
    Matriz *mat;

    if(n>0 && m>0){
        mat = (Matriz*)malloc(sizeof(Matriz));  //alocando uma estrutura do tipo Matriz
        if(mat == NULL){
            return NULL;
        }

        mat->linha = n;
        mat->coluna = m;
        mat->vetor = (float*)malloc(sizeof(float)*n*m); //alocando um vetor dentro da estrutura que vai ter a matriz.
        if(mat->vetor == NULL){
            free(mat);
            return NULL;
        }
        return mat;
    }
    return NULL;
}


int setMatrizIJ(Matriz* mat, int i, int j, float num){
    int k;
    if(mat == NULL){
        return 0;
    }
    if(i>=0 && i < mat->linha && j>=0 && j < mat->coluna){   /*i < mat->linha, esse comando pergunta se i é menor que o número máximo de linhas que é representado por mat->linha.*/
        k = i * mat->coluna + j;
        mat->vetor[k] = num;
        return 1;  //TRUE
    }
    return 0; //FALSE
}


float getMatrizIJ(Matriz* mat, int i, int j){
    int k;
    if(mat == NULL){
        return ERRO_FLOAT; 
    }
    if(i>=0 && i < mat->linha && j>=0 && j < mat->coluna){   
        k = i * mat->coluna + j;
        return mat->vetor[k];
        
    }
    return ERRO_FLOAT;  //FALSE
}


Matriz *CalcularTransposta(Matriz* mat, int linha, int coluna){
    Matriz *transposta;
    if(mat == NULL){
        return NULL;
    }
    if(linha > 0 && coluna > 0){
        transposta = criarMatriz(coluna, linha); // utilizando a função criarMatriz para alocar uma nova matriz transposta
        if (transposta == NULL) {
            return NULL;
        }

        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                float elemento = getMatrizIJ(mat, i, j); // Obtendo elemento de mat
                if (elemento != ERRO_FLOAT) {
                    setMatrizIJ(transposta, j, i, elemento); // inserindo o elemento de mat na matriz transposta
                }
            }
        }
        return transposta;
    }
    return NULL;
}


Matriz *multiMatriz(Matriz *ma, Matriz *mb, int n, int m, int p, int q){
    int produto = 0;
    int somatorio = 0;
    Matriz *matrizAux;

    if(ma == NULL || mb == NULL){
        return NULL;
    }

    if(n>0 && m>0 && p>0 && q>0){
        if(m==p){   /*Testando se o número de colunas da primeira é igual ao número de linhas da segunda*/
            matrizAux = (Matriz *)malloc(sizeof(Matriz));
            if(matrizAux == NULL){
                return NULL;
            }

            matrizAux->linha = n; 
            matrizAux->coluna = q; 
            matrizAux->vetor = (float*)malloc(sizeof(float)*n*q); //A matriz multiplicação tem o num de linhas da primeira e o num de colunas da segunda.
            if(matrizAux->vetor == NULL){
                free(matrizAux);
                return NULL;
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<q;j++){
                    for(int k=0;k<m; k++){
                        produto = ma->vetor[i*m+k] * mb->vetor[k*q+j];
                        somatorio += produto;  
                    }
                    int r = i * q + j;
                    matrizAux->vetor[r] = somatorio;
                    somatorio = 0;
                }
            }

            return matrizAux;
        }
        return NULL;  
    }
    return NULL;	
}


int destruirMatriz(Matriz* mat){
    if(mat == NULL){
        return 0;
    }
    free(mat->vetor);
    free(mat);
    return 1;
}

#endif