#include <string>

class Roman {
  public:
	Roman(std::string);
	~Roman();
	int getLength();
	int getNumber();

  private:
	std::string number;
	int numberInt;
};