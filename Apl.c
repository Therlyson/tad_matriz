#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "matriz.h"

//Aluno: Therlyson Ryan De Souza Santos

void inserir(Matriz *mat, int linha, int coluna);
void imprimir(Matriz *mat, int linha, int coluna);

int main(){
    setlocale(LC_ALL, "Portuguese");
    Matriz *matrizA, *matrizB;
    int linhaA, colunaA;
    int linhaB, colunaB;

    printf("Digite o numero de linhas da 1 matriz: ");
    scanf("%d", &linhaA);
    printf("Digite o numero de colunas da 1 matriz: ");
    scanf("%d", &colunaA);
    printf("\n");
    printf("Digite o numero de linhas da 2 matriz: ");
    scanf("%d", &linhaB);
    printf("Digite o numero de colunas da 2 matriz: ");
    scanf("%d", &colunaB);
    printf("\n");

    matrizA = criarMatriz(linhaA, colunaA);
    matrizB = criarMatriz(linhaB, colunaB);
    
    if (matrizA != NULL && matrizB != NULL) { // Verificar se a alocação da matriz foi bem sucedida
        //Inserindo dados da matrizA
        inserir(matrizA, linhaA, colunaA);

        //inserindo dados da matrizB
        inserir(matrizB, linhaB, colunaB);

        printf("\n1 MATRIZ:\n");
        imprimir(matrizA, linhaA, colunaA);

        printf("\n2 MATRIZ:\n");
        imprimir(matrizB, linhaB, colunaB);

        Matriz *transpostaA = CalcularTransposta(matrizA, linhaA, colunaA);
        printf("\n TRANSPOSTA DA 1 MATRIZ: \n");
        imprimir(transpostaA, colunaA, linhaA);

        Matriz *transpostaB = CalcularTransposta(matrizB, linhaB, colunaB);
        printf("\n TRANSPOSTA DA 2 MATRIZ: \n");
        imprimir(transpostaB, colunaB, linhaB);

        Matriz *matrizMultiplicada = multiMatriz(matrizA, matrizB, linhaA, colunaA, linhaB, colunaB);
        if(matrizMultiplicada!=NULL){
            printf("\nMATRIZ MULTIPLICADA:\n");
            for (int i=0; i<linhaA; i++) {   
                for(int j=0; j<colunaB; j++){
                    float elemMatriz = getMatrizIJ(matrizMultiplicada, i, j); //utilizando a função get para imprimir a matriz multiplicação 
                    if (elemMatriz != ERRO_FLOAT) {
                        printf("[%.1f]  ", elemMatriz);
                    }
                }
                printf("\n");
            }
        }
        else{
            printf("\nErro na multiplicacao de matrizes.");
        }

        destruirMatriz(matrizA);
        destruirMatriz(matrizB);
        destruirMatriz(matrizMultiplicada);
        destruirMatriz(transpostaA);
        destruirMatriz(transpostaB);
        return 0;
    }

    else {
        printf("ERRO AO CRIAR MATRIZ!\n");
        return 1;
    }
}


void inserir(Matriz *mat, int linha, int coluna){
    float numero;
    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            printf("Digite o numero para a posicao [%d][%d] da matrizA : ", i, j);
            scanf("%f", &numero);
            int inserir = setMatrizIJ(mat, i, j, numero);
            if(inserir == 0){
                printf("ERRO AO INSERIR NUMERO!\n");
            }
        }
    }
    printf("\n");
}

void imprimir(Matriz *mat, int linha, int coluna){
    for (int i=0; i<linha; i++) {   
        for(int j=0; j<coluna; j++){
            float elemMatriz = getMatrizIJ(mat, i, j); 
            if (elemMatriz != ERRO_FLOAT) { //testando se ocorreu tudo bem, devolvendo um erro criando em matriz.h
                printf("[%.1f]  ", elemMatriz);
            }
        }
        printf("\n");
    }
}