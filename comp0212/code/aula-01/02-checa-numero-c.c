#include <stdio.h>
#include <stdlib.h>

# define QTNUMEROS 10000000

int lendoArquivo(int *v){

    FILE *f;
	//Abre o arquivo binário no modo de leitura
	f = fopen("numeros2.txt", "r");
	if(f == NULL){
		printf("Erro na abertura \n");
		exit(1);
	}

    int i, numero;
    for(i = 0; i < 10; i++){
        fscanf(f, "%d", numero);
        v[i] = numero;
        printf("%d", numero);
        printf("%d", v[i]);
    }

    fclose(f);
}

int contaOcorrencias(int *v, int numero){
    int i, contador = 0;
    for(i = 0; i < 100; i++){
        if(v[i] == numero){
            contador++;
        }
    }
    return contador;
}

int main(){

    int *vetor;
    vetor = malloc(sizeof(int) * QTNUMEROS); 

    vetor[0] = 100;
    printf("%d", vetor[0]);

    lendoArquivo(vetor);

    printf("%d", vetor[1]);
    
    //int ocorrencias = contaOcorrencias(vetor, 10);
    //printf("Ocorrencias: %d", ocorrencias);

    return 0;  
}
