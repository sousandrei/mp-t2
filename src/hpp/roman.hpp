#include <string>

/**
* A more elaborate class description.
*/
class Roman {
  public:
	/**
	 *funcao de new
	 */
	Roman(std::string);
	/**
	 *funcao de new
	 */
	~Roman();
	/**
	 *funcao de new
	 */
	int getLength();
	/**
	 *funcao de new
	 */
	int getNumber();

  private:
	std::string number;
	int numberInt;
};