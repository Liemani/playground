#define playground005

/*
#ifdef playground000
// description
#include <iostream>

int main()
{
  return 0;
}
#endif

*/

#ifdef playground005
// initializer list this test
// enum class access test
#include <iostream>

class My_class
{
private :
  int my_variable;
  int& my_reference;

  enum class Sockets_offset
  {
    server,
    connection,
    client,
    count,
  };

public :
  My_class();

  void hello();
  void test();
  void describe();
};

My_class::My_class()
  : my_reference(this->my_variable)
{
}

void My_class::hello()
{
  std::cout << "Hello, world!" << std::endl;
}

void My_class::test()
{
  this->my_variable = 10;
  this->describe();

  this->my_reference = 42;
  this->describe();

  std::cout << (int)Sockets_offset::connection << std::endl;
  std::cout << (int)Sockets_offset::client << std::endl;
}

void My_class::describe()
{
  std::cout << "describe : " << std::endl;
  std::cout << " my_variable : " << my_variable << std::endl;
  std::cout << " my_reference : " << my_reference << std::endl;
}

int main()
{
  My_class my_class = My_class();
  my_class.hello();
  my_class.test();
  return 0;
}
#endif

#ifdef playground004
// hex_dump test
#include <iostream>
#include "hex_dump.h"

const char* message = "Hello, world!\nHello, world!\nHello, world!\n";

int main()
{
  hex_dump((const unsigned char*)message, strlen(message));

  return 0;
}
#endif

#ifdef playground003
// print with snprintf
#include <iostream>
#include <cstdio>

struct Line {
    char content[9];
    char terminator;
};

Line line;

int main()
{
  snprintf((char*)&line, sizeof(line.content), "%08x", (unsigned int)&line);
  std::cout << (char*)&line << std::endl;

  return 0;
}
#endif

#ifdef playground002
// check size
#include <iostream>

class MyBuffer {
  unsigned char line[78];
  char terminator;
};

int main()
{
  MyBuffer myBuffer = MyBuffer();
  std::cout << "sizeof(myBuffer) : " << sizeof(myBuffer) << std::endl;

  (reinterpret_cast<char*>(&myBuffer))[0] = 'l';
  std::cout << reinterpret_cast<char*>(&myBuffer) << std::endl;

  return 0;
}
#endif

#ifdef playground001
// print address with 8 width
#include <iostream>
#include <string>
#include <iomanip>

//std::string message = "Hello, world!\n";
const char* message = "Hello, world!\n";

int main()
{
  std::cout << "address : "
    << std::hex << std::setw(8) << std::setfill('0')
    << static_cast<int>(reinterpret_cast<std::uintptr_t>(message)) << std::endl;

  return 0;
}
#endif

#ifdef playground000
// print all printable character
// if not print '.'
#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
  for (int i = 0; i < std::numeric_limits<unsigned char>::max(); ++i)
  {
    // goal : [000].\n([%d]%c\n)
    std::cout << "["
      << std::setw(3) << std::setfill('0')
      << i << "]" << (std::isprint(i) ? static_cast<char>(i) : '.') << std::endl;
  }
  return 0;
}
#endif
