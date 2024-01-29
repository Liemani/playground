#include <functional>
#include <iostream>
#include <fstream>
#include <string>

#include "lmi.hpp"

//template
//#ifdef GROUND000
//int main() {
//	return 0;
//}
//#endif

#define GROUND006

#ifdef GROUND006
class IpConnection {
};

class MethodProvider {

public :
  void* save() {
    std::cout << "method1" << std::endl;
    return NULL;
  }

  void* load() {
    std::cout << "method2" << std::endl;
    return NULL;
  }

  void* test() {
    std::cout << "this is test function" << std::endl;
    return NULL;
  }

};

int main() {
  MethodProvider methodProvider;

  Application<MethodProvider>::CommandMethodDictionary commandMethodDictionary = {
    {"test", &MethodProvider::test},
  };

  Application<MethodProvider> application = Application<MethodProvider>(methodProvider);

  application.setUpCommand(commandMethodDictionary);
  application.execute();

	return 0;
}
#endif

#ifdef GROUND005
class MethodProvider {

public :
  void* method1() {
    std::cout << "method1" << std::endl;
    return NULL;
  }

  void* method2() {
    std::cout << "method2" << std::endl;
    return NULL;
  }

};

int main() {
  MethodProvider methodProvider;
  Application<MethodProvider> application = Application<MethodProvider>(methodProvider);
  application.commandMethodDictionary["first"] = &MethodProvider::method1;
  application.commandMethodDictionary["second"] = &MethodProvider::method2;
  application.execute();

	return 0;
}
#endif

#ifdef GROUND004
int main() {
  Application application;
  application.debugDescribe();
  application.commandMethodDictionary["hi"] = &Application::testFunction1;
  application.commandMethodDictionary["there"] = &Application::testFunction2;
  application.debugDescribe();
  application.invoke("hi");
  application.invoke("there");

  return 0;
}
#endif

#ifdef GROUND003
int main() {
  std::string path = "lmi.hpp";

  std::ifstream ifstream = FileManager::openIFStreamAs(path);

  std::string buffer;
  while (true) {
    std::getline(ifstream, buffer);
    if (ifstream.eof()) {
      std::cout << buffer;
      break;
    }
    else {
      std::cout << buffer << std::endl;
    }
  }

  ifstream.close();

  return 0;
}
#endif
