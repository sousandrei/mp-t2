#include "../hpp/roman.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

TEST(Roman, createValid) {

	Roman *a = new Roman("X");

	ASSERT_EQ(1, a->getLength());

	delete a;
}

TEST(Roman, createInvalid) {

	ASSERT_THROW(new Roman("a"), std::invalid_argument);
}

TEST(Roman, getNumberInvalidRepetition) {

	ASSERT_THROW(new Roman("IIII"), std::invalid_argument);

	ASSERT_THROW(new Roman("DD"), std::invalid_argument);

	ASSERT_THROW(new Roman("LL"), std::invalid_argument);

	ASSERT_THROW(new Roman("VV"), std::invalid_argument);
}

TEST(Roman, getNumberInvalidSubtraction) {

	ASSERT_THROW(new Roman("IC"), std::invalid_argument);

	ASSERT_THROW(new Roman("XM"), std::invalid_argument);

	ASSERT_THROW(new Roman("VC"), std::invalid_argument);

	ASSERT_THROW(new Roman("LC"), std::invalid_argument);

	ASSERT_THROW(new Roman("DM"), std::invalid_argument);
}

TEST(Roman, getNumberValid) {

	Roman *a = new Roman("XLIX");

	ASSERT_EQ(a->getNumber(), 49);

	a = new Roman("CCLXXVIII");

	ASSERT_EQ(a->getNumber(), 278);

	delete a;
}