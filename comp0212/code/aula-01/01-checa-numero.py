import time

def ler_arquivo():
    arquivo = open("numeros.txt", "r")
    dados = arquivo.readlines()
    arquivo.close()
    return dados

def conta_ocorrencias(lista, numero):
    contador = 0
    for i in lista:
        if int(i) == numero:
            contador = contador + 1
    return contador

import time

inicio = time.time()

dados = ler_arquivo()
contador = conta_ocorrencias(dados, 10)
print("Numero de ocorrencias: " + str(contador))

fim = time.time()

print("Tempo total: " + str(fim - inicio) + "  s")
