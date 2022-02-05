from random import randint

arquivo = open("numeros.txt", "w")

qtNumeros = 1000000
limiteSuperior = 100
contador = 0

while (contador < qtNumeros):
    arquivo.write(str(randint(0, limiteSuperior)) + "\n")
    contador = contador + 1

arquivo.close()