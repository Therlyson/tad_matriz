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
    int linhaA, colunaA, linhaB, colunaB;
    int key1 = 0, key2 = 0, key3 = 0, key4 = 0;   //chaves criadas para que no código o usuário não tente por exemplo inserir elementos em uma matriz que ele não criou.
    int opcao;
    
    while(opcao!=0){
        printf("\n\t========= Menu =========\n");
        printf("1 - Criar a matriz A\n");
        printf("2 - Criar a matriz B\n");
        printf("3 - Ler e inserir os dados da matriz A\n");
        printf("4 - Ler e inserir os dados da matriz B\n");
        printf("5 - Calcular a multiplicacao de A por B e imprimir o resultado\n");
        printf("6 - Calcular a transposta de A e imprimir o resultado\n");
        printf("7 - Calcular a transposta de B e imprimir o resultado\n");
        printf("8 - Destruir a matriz A\n");
        printf("9 - Destruir a matriz B\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if(opcao == 1){
            printf("Digite o numero de linhas da 1 matriz: ");
            scanf("%d", &linhaA);
            printf("Digite o numero de colunas da 1 matriz: ");
            scanf("%d", &colunaA);
            matrizA = criarMatriz(linhaA, colunaA);
            if(matrizA == NULL){
                printf("ERRO AO CRIAR MATRIZ");
            }
            else{
                printf("Matriz criada com sucesso!\n");
                key1 = 1;
            }
        }

        else if(opcao == 2){
            printf("Digite o numero de linhas da 2 matriz: ");
            scanf("%d", &linhaB);
            printf("Digite o numero de colunas da 2 matriz: ");
            scanf("%d", &colunaB);
            matrizB = criarMatriz(linhaB, colunaB);
            if(matrizB == NULL){
                printf("ERRO AO CRIAR MATRIZ");
            }
            else{
                printf("Matriz criada com sucesso!\n");
                key2 = 1;
            }
        }

        else if(opcao == 3){
            if(key1 == 1){
                inserir(matrizA, linhaA, colunaA);
                printf("1 MATRIZ:\n");
                imprimir(matrizA, linhaA, colunaA);
                printf("\n");
                key3 = 1;
            }
            else{
                printf("ERRO!!! Primeiro crie a matriz.\n");
            }
            
        }

        else if(opcao == 4){
            if(key2 == 1){
                inserir(matrizB, linhaB, colunaB);
                printf("2 MATRIZ:\n");
                imprimir(matrizB, linhaB, colunaB);
                printf("\n");
                key4 = 1;
            }
            else{
                printf("ERRO!!! Primeiro crie a matriz.\n");
            }
            
        }

        else if(opcao == 5){
            if(key3 == 1 && key4 == 1){
                Matriz *matrizMultiplicada = multiMatriz(matrizA, matrizB, linhaA, colunaA, linhaB, colunaB);
                if(matrizMultiplicada!=NULL){
                    printf("MATRIZ MULTIPLICADA:\n");
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
                    printf("Erro na multiplicacao de matrizes.");
                }
                destruirMatriz(matrizMultiplicada);
                printf("\n");
            }
            else{
                printf("ERRO!!! Primeiro crie e insira os elementos nas matrizes!\n");
            }   
        }

        else if(opcao == 6){
            if(key3==1){
                Matriz *transpostaA = CalcularTransposta(matrizA, linhaA, colunaA);
                printf("TRANSPOSTA DA 1 MATRIZ: \n");
                imprimir(transpostaA, colunaA, linhaA);
                destruirMatriz(transpostaA);
                printf("\n");
            }
            else{
               printf("ERRO!!! Primeiro crie e insira os elementos na matriz!\n");
            }
        }

        else if(opcao == 7){
            if(key4 == 1){
                Matriz *transpostaB = CalcularTransposta(matrizB, linhaB, colunaB);
                printf("TRANSPOSTA DA 2 MATRIZ: \n");
                imprimir(transpostaB, colunaB, linhaB);
                destruirMatriz(transpostaB);
                printf("\n");
            }
            else{
                printf("ERRO!!! Primeiro crie e insira os elementos na matriz!\n");
            }
            
        }

        else if(opcao == 8){
            if(key1 == 1){
                int destruindo = destruirMatriz(matrizA);
                if(destruindo!=0){
                    printf("Matriz destruida com sucesso\n");
                }
            }
            else{
                printf("impossivel destruir matriz sem criar primeiro\n");
            }
            
        }

        else if(opcao == 9){
            if(key2 == 1){
                int destruindo = destruirMatriz(matrizB);
                if(destruindo!=0){
                    printf("Matriz destruida com sucesso\n");
                }
            }
            else{
                printf("impossivel destruir matriz sem criar primeiro\n");
            }
        }

        else if(opcao == 0){
            printf("PROGRAMA ENCERRADO COM SUCESSO!\n");
            break;
        }
        
        else{
            printf("Voce digitou uma opcaoo invalida!\n");
        }
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