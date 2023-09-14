# Trabalho de Implementação 01 - TAD matriz - Estrutura de Dados 1

## IDE UTILIZADA: Visual Studio Code

## TAD - Introdução

Este código em C tem o objetivo criar duas matrizes, calcular a transposta de cada uma, e depois multiplicar a primeira matriz com a segunda matriz e imprimir tudo na tela.
Tudo isso é feito usando conceitos de Tipos Abstratos de Dados em linguagem C, criando três arquivos principais(matriz.h, matriz.c, apl.c):<br><br>
matriz.h: É um arquivo de cabeçalho contendo apenas os protótipos das funções.<br><br>
matriz.c: Esse arquivo contém a implementação de cada função(mas contém apenas as operações e o que deve ser retornado), utilizando os protótipos criado em matriz.h.<br><br>
apl.c: esse arquivo é a main, onde fica a interface do programa conténdo todas as entradas e saidas de dados.<br><br>
matriz.o e executave.exe : são arquivos necessários para que o TAD funcione ao ser executado


## Funcionalidades:
1. *criarMatriz* : Recebe o número de linhas e colunas da matriz, e retorna um ponteiro para uma estrutura do tipo Matriz.

2. *setMatrizIJ*: Recebe uma matriz, a posição da linha e da coluna atual e o número que deseja colocar nessa posição. Retornando 1 se o número foi adicionado na matriz com sucesso e 0 caso contrário.

3. *getMatrizIJ*: Responsável por retornar uma posição desejada pelo usuário, no programa atual ela é responsável por retornar cada elemento de cada posição da matriz. Recebe uma matriz, a posição da linha e da coluna atual.

4. *CalcularTransposta*: Recebe a matriz que deseja retornar sua transposta, a linha dessa matriz e coluna. Ela cria uma matriz transposta invertendo colunas e linhas e utilizando a função criarMatriz pra isso. Logo após utiliza a função getMatrizIJ para obter o elemento da matriz que foi recebida como parâmetro e depois utiliza setMatrizIJ para adicionar esse elemento na matriz transposta. Por fim retorna a transposta.

5. *multiMatriz*: Recebe duas matrizes, suas linha e colunas. Responsável por fazer a multiplicação dessas matrizes e retornar a matriz contendo resultado.

6. *destruirMatriz*: recebe a matriz que deseja liberar memória e retorna 1 caso a liberação tenha ocorrido com sucesso.


## Como executar o programa no Visual Studio Code:

1. Para o programa ser executado, basta criar uma pasta no PC e adicionar todos os arquivos na mesma pasta (`apl.c`, `matriz.c`, `matriz.h`, `matriz.o`, `executavel.exe`)

2. Após isso abre o Visual Studio Code -> File -> open Folder, abri a pasta que tá os arquivos.

3. Logo após basta ir no Terminal -> new terminal, no terminal digite: `./executavel`

4. Pronto, agora o programa está funcionando corretamente.