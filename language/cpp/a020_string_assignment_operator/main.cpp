#include <iostream>
#include <string>

#define logExpression(expression) std::cout << #expression" : " << (expression) << std::endl

int main(int argc, char* argv[]) {
  std::string first = "a";
  std::string second = "b";

  logExpression(first);
  logExpression(second);

  logExpression(static_cast<const void*>(&first));
  logExpression(static_cast<const void*>(&second));

  logExpression(static_cast<const void*>(first.c_str()));
  logExpression(static_cast<const void*>(second.c_str()));

  std::cout << "first == second : " << (first == second) << std::endl;

  first = second;

  logExpression(first);
  logExpression(second);

  logExpression(static_cast<const void*>(&first));
  logExpression(static_cast<const void*>(&second));

  logExpression(static_cast<const void*>(first.c_str()));
  logExpression(static_cast<const void*>(second.c_str()));

  std::cout << "first == second : " << (first == second) << std::endl;

  return 0;
}
