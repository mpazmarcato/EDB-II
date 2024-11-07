# EDB-II
## Estrutura do repositório
* `docs`: neste diretório estão localizados o relatório das análises teóricas e os arquivos `.tex` que compõem este documento. 
* `src`: neste diretório estão localizadas as implementações dos pseudocódigos mencionados no relatório, incluind`buscaBinaria`, `bBinRep`, `idadeRep` e os algoritmos de ordenação. 

## Como compilar o documento
Para compilar você precisa ter o LaTex instalado no computador. Caso não tenha, verifique [aqui](https://www.latex-project.org/get/).

Dentro do diretório `docs`, basta inserir o comando:

```bash
pdflatex main.tex
```
e um arquivo chamado "main.tex" será gerado, sendo este o relatório das análises teóricas que o grupo realizou.

O relatório é dividido em 7 seções, sendo 6 numeradas:
* Descrição inicial dos algoritmos;
* 1. Bubble Sort, seus diferentes algoritmos e análises de complexidades;
* 2. Merge Sort, seus diferentes algoritmos e análises de complexidades;
* 3. Quick Sort, seus diferentes algoritmos e análises de complexidades;
* 4. Resultados de execução de `idadeRep`/`idadeRep2`;
* 5. Resultados de execução de `buscaBinaria`/`bBinRec`;
* 6. Análise dos algoritmos de ordenação.

## Implementação dos algoritmos
No diretório `src` estão todos os algoritmos implementados, como mencionado na seção de estrutura. Os códigos foram feitos na linguagem C++, logo, para compila-los, é necessário o compilador `gcc`. Com o `gcc` instalado, basta adentrar no diretório do algoritmo desejado e compila-lo com:
```bash
g++ nome_do_arquivo.cpp -o nome_da_saida
```
e executá-lo com:
```bash
./nome_da_saida
```

## Lista de tarefas desenvolvidas
### Análise Teórica
* Bubble Sort:
    - Pseudocódigo iterativo: Andriel
    - Pseudocódigo recursivo: Victor 
    - Implementação do código iterativo: Andriel
    - Implementação do código recursivo: Victor 
    - Análise do pseudocódigo iterativo: Andriel
    - Análise do pseudocódigo recursivo por substituição: Cauã 
    - Análise do pseudocódigo recursivo por iteração: Cauã 
    - Análise do pseudocódigo recursivo por árvore de recursão: Paz 
    - Análise do pseudocódigo recursivo por método mestre: Andriel 

* Merge Sort
    - Pseudocódigo iterativo: Paz 
    - Pseudocódigo recursivo: Paz 
    - Implementação do código iterativo: Paz 
    - Implementação do código recursivo: Paz 
    - Análise do pseudocódigo iterativo: Andriel
    - Análise do pseudocódigo recursivo por substituição: Victor 
    - Análise do pseudocódigo recursivo por iteração: Cauã 
    - Análise do pseudocódigo recursivo por árvore de recursão: Cauã 
    - Análise do pseudocódigo recursivo por método mestre: Cauã 

* Quick Sort 
    - Pseudocódigo iterativo: Victor 
    - Pseudocódigo recursivo: Andriel 
    - Implementação do código iterativo: Victor
    - Implementação do código recursivo: Paz 
    - Análise do pseudocódigo iterativo: Paz 
    - Análise do pseudocódigo recursivo por substituição: Andriel 
    - Análise do pseudocódigo recursivo por iteração: Cauã 
    - Análise do pseudocódigo recursivo por árvore de recursão: Cauã 
    - Análise do pseudocódigo recursivo por método mestre: Cauã 

### Análise dos Algoritmos
* Códigos `idadeRep`, `idadeRep2` e análise: Paz
* Códigos `buscaBinaria`, `bBinRec` e análise: Andriel 
* Execução de todos os algoritmos de ordenação: Paz
* Análise dos resultados dos algoritmos de ordenação: Victor & Cauã
