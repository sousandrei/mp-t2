#include "../hpp/roman.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
/** @file */

/**
* Testa a criacao normal de um numeral romano, e suas funcoes e o descontrutor
*/
TEST(Roman, createValid) {

	Roman *a = new Roman("X");

	ASSERT_EQ(1, a->getLength());
	ASSERT_EQ(10, a->getNumber());

	delete a;
}

/**
* Testa a criacao de um numeral com caratere invalido
*/
TEST(Roman, createInvalid) {

	ASSERT_THROW(new Roman("a"), std::invalid_argument);

	ASSERT_THROW(new Roman("Xa"), std::invalid_argument);
}

/**
* Testa a criacao de um numeral com repeticoes que nao cabem nas regras 
* de apenas um D, L e V e nao mais que 4 do mesmo algarismo
*/
TEST(Roman, getNumberInvalidRepetition) {

	ASSERT_THROW(new Roman("IIII"), std::invalid_argument);

	ASSERT_THROW(new Roman("DD"), std::invalid_argument);

	ASSERT_THROW(new Roman("LL"), std::invalid_argument);

	ASSERT_THROW(new Roman("VV"), std::invalid_argument);
}

/**
* Testa a criacao de um numeral com subtracoes que nao sao 
* permitidas. 
* <br>
* <br>
* Subtracoes possiveis:
* <br>
* I pode subratir de X e C
* <br>
* X pode subratir de V e X
* <br>
* C pode subratir de L e C
* <br>
* <br>
* Como nao usamos algarismos maiores que M (1000), a regra do C nao foi
* implementada, pois todos os maiores que ele podem ser subtraidos por tal.
*/
TEST(Roman, getNumberInvalidSubtraction) {

	ASSERT_THROW(new Roman("IC"), std::invalid_argument);

	ASSERT_THROW(new Roman("XM"), std::invalid_argument);

	ASSERT_THROW(new Roman("VC"), std::invalid_argument);

	ASSERT_THROW(new Roman("LC"), std::invalid_argument);

	ASSERT_THROW(new Roman("DM"), std::invalid_argument);
}

/*
* Testa a criacao de numeros validos.
* <br>
*  Foram usados numeros que passam por todas as regras para melhor teste
*/
TEST(Roman, getNumberValid) {

	Roman *a = new Roman("XLIX");

	ASSERT_EQ(a->getNumber(), 49);

	a = new Roman("CCLXXVIII");

	ASSERT_EQ(a->getNumber(), 278);

	delete a;
}