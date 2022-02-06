#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define QTNUMEROS 10000000

int lendoArquivo(int *v){

    FILE *f;
	//Abre o arquivo binário no modo de leitura
	f = fopen("numeros.txt", "r");
	if(f == NULL){
		printf("Erro na abertura \n");
		exit(1);
	}

    int i, numero;
    for(i = 0; i < QTNUMEROS; i++){
        fscanf(f, "%d", &numero);
        v[i] = numero;
    }

    fclose(f);
}

int contaOcorrencias(int *v, int numero){
    int i, contador = 0;
    for(i = 0; i < QTNUMEROS; i++){
        if(v[i] == numero){
            contador++;
        }
    }
    return contador;
}

int main(){

    clock_t t;
    t = clock(); //armazena tempo

    int *vetor;
    vetor = malloc(sizeof(int) * QTNUMEROS); 

    vetor[0] = 100;

    lendoArquivo(vetor);
    
    int ocorrencias = contaOcorrencias(vetor, 10);
    printf("Numero de ocorrencias: %d \n", ocorrencias);

    t = clock() - t; //tempo final - tempo inicial
    printf("Tempo de execucao: %lf s", ((double)t)/((CLOCKS_PER_SEC)));

    return 0;  
}
