
dados = []

def ler_arquivo():
    arquivo = open("numbers.txt", "r")
    dados = arquivo.readlines()
    print(arquivo.readline(3))
    print(arquivo.readlines())
    arquivo.close()

ler_arquivo()
print(dados)