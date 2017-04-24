#include <string>

/**
* A more elaborate class description.
*/
class Roman {
  public:
	/**
	 * Construtor da classe Roman
	 * 
	 * @param {std::string} number string contendo o numero romano
	 *
	 * @return retorna instancia da classe Roman, com as funcoes para
	 * acesso do numero em decimais o tamanho da string de numerais romanos
	 */
	Roman(std::string);
	/**
	 * Destruidor da classe roman
	 */
	~Roman();
	/**
	 * Funcao que retorna o tamanho da string em numerais romanos
	 */
	int getLength();
	/**
	 * Funcao que retorna o numero convertido para decimais
	 */
	int getNumber();
	/**
	 * Funcao que retorna o numero em algarismos romanos
	 */
	std::string getRomanNumber();

  private:
	std::string number;
	int numberInt;
};