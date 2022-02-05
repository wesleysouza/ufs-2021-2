# Complexidade de Algoritmos

Analisar um algoritmo é prever a quantidade de recursos que esse algoritmos irá demandar a medida que o tamanho do problema que o algoritma trata cresce.

Esses recursos podem ser:
- Largura de banda;
- Memória;
- Tempo de execução (geralmente estamos mais interessados nesse fator).

O Objetivo dessa disciplina é fornecer ferramentas para que seja possível fazer essa comparação.

Em geral a primeira coisa que pensamos para analisar algoritmos são os **Benchmarks**, fazemos uma séries de execuções com entradas diferentes Problema dessa abordagem: Os dois programas tem que executar sobre as mesmas condições (sistema operacional, processador, linguagem de programação, compilador e etc). Qualquer variação nessas condições pode alterar o resultado. Por esse e outros motivos esse método não é adequado!

Para contornar esse problema utilizamos uma notação matemática que ignora as contantes e se concentra apenas no comportamento da função que modela o tempo de execução ou consumo de recursos do algoritmo.

Observamos como a curva se comporta: linear, cúbica, expoencial e etc.

## Notação Assintotica Big-O

```cpp
int pesquisa(Estrutura *v, int n, int chave){
    int i;
    for(i = 0; i < n; i++){
        if(v[i].chave == chave){
            return i;
        }
    }
    return -1;
}
```

Situações possíveis:
- **Melhor caso**: Quando o algoritmo gasta o menor tempo de execução possível para realizar a tarefa.
    - Primeira posição do vetor (uma única comparação).
    - Complexidade constante (não depende da entrada para o melhor caso).
- **Pior Caso**: Ocorre quando o elemento procurado está na última posição do vetor ou não está no vetor.
    - N comparações.
    - Complexidade linear.
- **Caso Médio**: ...

Obs.: Caso utilizasse-mos um computador mais rápido ou lento para executar essa tarefa teriamos outra reta, a diferença entre essas retas é o coeficiênte angular, uma constante que múltiplica o número de elementos do vetor. Se nossa intenção é comparar algoritmos independentemente do hardware, sistema operacional e etc temos que ignorar essa constante que multiplica (ideia centrak da notação assintótica).

Declarações de variáveis -> Complexidade constante O(1).

### Complexidade em lops

#### Caso 1:

```cpp
for (i = 0; i < n; i++){
    //O(1);
}
```

Complexidade O(n): n*1.

#### Caso 2:

```cpp
for (i = 0; i < n; i++){
    //O(n);
}
```

Complexidade O(n^2): n*n.

#### Caso 3:

```cpp
for (i = 0; i < n; i++){
    //O(n^2);
}
```

Complexidade O($n^3$): $n*n^2$.

#### Caso 4: Algoritmo com mais de uma entrada (m e n):

```cpp
for (i = 0; i < m; i++){
    //O(n);
}
```

Complexidade O($m*n$): $m*n$.

#### Caso 5: Um loop seguido do outro

```cpp
for (i = 0; i < n; i++){
    //O(n);
}

for (i = 0; i < n; i++){
    //O(n^2);
}
```

O primeiro loop tem complexidade O($n^2$) e o segundo O($n^3$). Sendo assim, a complexidade será a soma $n^2 + n^3$. A função que donima é o termo de maior grau, logo a complexidade é **O($n^3$)**.

Complexidade O($m*n$): $m*n$.

### Monônios e Polinômios

- **Monônios**: (ou termo algébrico) são expressões algébricas formadas por apenas um número ou uma variável ou pelo produto de número e variáveis (e.g. $ 5, n^2, 2n^3, 3n^4m$).
- **Polinômios**: são expressões algébricas formadas pela adição de monômios (e.g. $ n^2 + 4n, 2n^3 + m + 3, 2n^2m^2 + n^2m + 5m $).

Obs.: Soluções com complexidade maior que a polinomial não são consideradas viáveis.

### Analisando a pesquisa sequencial

#### Analisando no **melhor caso**:

```cpp
int pesquisa(Estrutura *v, int n, int chave){
    int i; //O(1)
    i = 0; //O(1)
    while(i < n){ //O(1)
        if(v[i].chave == chave){ //O(1)
            return i; //O(1)
        }
        i++;
    }
    return -1;
}
```

Resultado, a sequencia de operações com custo O(1) tem complexidade O(1).

#### Analisando no **pior caso**:

```cpp
int pesquisa(Estrutura *v, int n, int chave){
    int i; //O(1)
    i = 0; //O(1)
    while(i < n){ //O(1)
        if(v[i].chave == chave){ //O(1)
            return i; //O(1)
        }
        i++; //O(1)
    }
    return -1; //O(1)
}
```

O loop executa n vezes, por isso a complexidade é O(n).

#### Analisando no **pior caso**:

```cpp
int pesquisa(Estrutura *v, int n, int chave){
    int i; //O(1)
    i = 0; //O(1)
    while(i < n){ //O(1)
        if(v[i].chave == chave){ //O(1)
            return i; //O(1)
        }
        i++; //O(1)
    }
    return -1; //O(1)
}
```

Obs.: Para calcular o caso médio é necessário saber  ou assumir a distribuição de probabilidade da entrada.

No geral o pior e melhor caso já dão uma ideia geral do desempenho do algoritmo.

No caso do algoritmo acima, para calcular o caso médio precisamos saber a probailidade de o elemento procurado estar em cada posição do vetor. Assumindo que a probabilidade é a mesma (uma ditribuição uniforme), temos:

$$\sum_{n=1}^{10}cipi$$

- ci: número de comparações.
- pi: probabilidade.

Se o elemento procurado está na primaira posição do vetor a probabilidade disso é $\frac{1*1}{n}$. Na segunda, 2*1/n. na terceira 1*1/n + ... + penúltima (n-1)*1/n + n*1/n. O resultado é um somatório de 1 até n.

$\frac{a}{b}$

Número médio de comparações: n + 1/2.

No caso médio a complexidade é O(n).

# Referências:

[Introdução a Complexidade de Algoritmos](https://medium.com/nagoya-foundation/introdu%C3%A7%C3%A3o-%C3%A0-complexidade-de-algoritmos-4a9c237e4ecc)

[Playlist Sobre Complexidade de Algoritmos](https://youtube.com/playlist?list=PLTcoKFH1s7tGbKN-Lrrf7jSlwBPD3DfxD)


[Data Structures - Full Course Using C and C++](https://www.youtube.com/watch?v=B31LgI4Y4DQ)