#include <string>

class Roman {
  public:
	Roman(std::string);
	~Roman();
	int getLength();

  private:
	std::string number;
};