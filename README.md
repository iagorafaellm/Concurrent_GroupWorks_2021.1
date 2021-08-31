# Concurrent_GroupWorks_2021.1

*Solução concorrente para esboço de gráficos de funções do segundo grau em um arquivo bitmap.*

## Estrutura do repositório
* [lib](lib)
    - [bmp.h](bmp.h): Header de bmp.c.
    - [concurrentmath.h](concurrentmath.h): Header de concurrentmath.c.
    - [threadvariables.h](threadvariables.h): Header para utilizarmos NTHREADS em concurrentmath.c e em bmp.c.
    - [timer.h](timer.h): Biblioteca que utilizamos para avaliar o desempenho do programa.
* [model_codes](model_codes)
<br>      *Ambos códigos de apoio ou modelo para o desenvolvimento do programa.*
    - [bmp - Copia.c](bmp\-\Copia.c)
    - [model.c](model_codes/model.c)
* [src](src)
    - [bmp.c](bmp.c): Arquivo que gera o bmp.
    - [concurrentmath.c](concurrentmath.h): Arquivo que faz os cálculos de y.
    - [main.c](threadvariables.h): Arquivo principal.
    - [makefile](makefile): Arquivo usado para compilar o programa.


## Pré-requisito

Antes de começar, verifique se você atendeu ao seguinte requisito:
* Você instalou a versão mais recente de `make`


## Como gerar um arquivo `.bmp`?


1. Compile o programa
```
  make all
```

2. Execute o programa
```
  ./main <a> <b> <c>
```
Em `<a>`, `<b>` e `<c>` entre com os termos de acordo com a fórmula `a*x^2 + b*x + c`. <br>O arquivo de entrada gerado estará em *src/1000x1000.bmp*.

## Autoria
* [Iago Rafael Lucas Martins](https://github.com/iagorafaellm)
* [Lucas Moreno Silva](https://github.com/Lucas-LMS)
* [Pedro Ancelmo de Aquino Vieira Amaral](https://github.com/P-Ancelmo)
