#include "../hpp/roman.hpp"
#include <map>
#include <stdexcept>

Roman::Roman(std::string strNumber) {
	this->number = strNumber;

	std::string s = strNumber;
	std::map<char, int> numerals;

	numerals['M'] = 1000;
	numerals['D'] = 500;
	numerals['C'] = 100;
	numerals['L'] = 50;
	numerals['X'] = 10;
	numerals['V'] = 5;
	numerals['I'] = 1;

	int total = 0;

	bool appearD = false;
	bool appearL = false;
	bool appearV = false;

	for (unsigned int i = 0; i < s.size(); ++i) {
		s[i] = (char)std::toupper(s[i]);

		if (numerals.count(s[i]) < 1)
			throw std::invalid_argument(
				"String Invalida, character desconhecido: " + s[i]);

		if (numerals[s[i]] == numerals[s[i + 1]])
			if (numerals[s[i]] == numerals[s[i + 2]])
				if (numerals[s[i]] == numerals[s[i + 3]])
					throw std::invalid_argument("String Invalida, character "
												"repetido mais de 3 vezes: " +
												s[i]);

		if (!appearD) {
			if (s[i] == 'D')
				appearD = true;
		} else if (s[i] == 'D')
			throw std::invalid_argument(
				"String Invalida, character repetido: " + s[i]);

		if (!appearL) {
			if (s[i] == 'L')
				appearL = true;
		} else if (s[i] == 'L')
			throw std::invalid_argument(
				"String Invalida, character repetido: " + s[i]);

		if (!appearV) {
			if (s[i] == 'V')
				appearV = true;
		} else if (s[i] == 'V')
			throw std::invalid_argument(
				"String Invalida, character repetido: " + s[i]);

		if (numerals[s[i]] < numerals[s[i + 1]]) {
			if (s[i] != 'I' && s[i] != 'X' && s[i] != 'C')
				throw std::invalid_argument(
					"String Invalida, somente I, X e C podem subtrair: " +
					s[i]);

			if (s[i] == 'I' && (s[i + 1] != 'V' && s[i + 1] != 'X'))
				throw std::invalid_argument(
					"String Invalida, I so pode subtrair de V e X: " + s[i]);

			if (s[i] == 'X' && (s[i + 1] != 'L' && s[i + 1] != 'C'))
				throw std::invalid_argument(
					"String Invalida, X so pode subtrair de L e C: " + s[i]);

			total -= numerals[s[i]] * 2;
		}

		total += numerals[s[i]];
	}

	this->numberInt = total;
}
Roman::~Roman() {}

int Roman::getLength() { return number.length(); }
int Roman::getNumber() { return this->numberInt; }
