# Metodos de Programacao - Trabalho 1
Professor: Jan Correa

Aluno: Andrei Felipe Silveira Sousa - 13/0039985

## Sobre

O objetivo neste trabalho foi desenvolver uma bibloteca de interpretação de
numerais romanos

Os testes foram feitos conforme as regras providas neste [site](https://projecteuler.net/about=roman_numerals)


Numeros usados para testes retirados deste [site](http://numeracaoromana.babuo.com/numeros-romanos-de-1-a-3000)
 fornecido pelo professor

OBS: Segundo o Project Euler, a regra de nao repetir 3 vezes um numero e opcional
visto que variava dos costumes da epoca usa-la ou nao. A liberdade dos romanos ao
escrever era maior que a acreditada. Porem, para todos os efeitos este codigo foi 
implementado com tais regras.

## Como usar


Para compilar
~~~~~~~~~~~~~~~~~~~~~
make
~~~~~~~~~~~~~~~~~~~~~

Para executar
~~~~~~~~~~~~~~~~~~~~~
 make run
~~~~~~~~~~~~~~~~~~~~~

Para executar manualmente
~~~~~~~~~~~~~~~~~~~~~
./build/t2
~~~~~~~~~~~~~~~~~~~~~
Para tracar o code-coverage
~~~~~~~~~~~~~~~~~~~~~
 make cov
~~~~~~~~~~~~~~~~~~~~~
Para limpar o projeto
~~~~~~~~~~~~~~~~~~~~~
 make clean
~~~~~~~~~~~~~~~~~~~~~

Para compilar e rodar os testes
~~~~~~~~~~~~~~~~~~~~~
 make test
~~~~~~~~~~~~~~~~~~~~~

Para executar manualmente
~~~~~~~~~~~~~~~~~~~~~
 make test_build
 ./build/t2_test
~~~~~~~~~~~~~~~~~~~~~

OBS: outros target estao no MAKEFILE porem nao sao tao usados
OBS2: todos os targets executam um `make clean` antes de compilarem, pois
alguns targets usam flags que precisam da recompilacao de tudo, como o `coverage` e o `test`