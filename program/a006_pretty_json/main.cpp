#include <iostream>
#include <string>
#include <algorithm>

bool contains(const char* array, char element);

bool contains(const char* array, size_t size, char element) {
  const char* first = array;
  const char* last = array + size;
  const char* result = std::find(first, last, element);

  return result != last;
}

class PrettyPrinter {

private :
  static const char openParenthesis[];
  static const char closeParenthesis[];
  static const char ignoreCharacter[];
  static const char newLineCharacter[];
  static const char beforeAfterSpaceCharacter[];

  int indentCount;
  char lastPrintCharacter;

  void printIndent();

public :
  PrettyPrinter();
  void processLine(const std::string& line);

};

const char PrettyPrinter::openParenthesis[] = "{[";
const char PrettyPrinter::closeParenthesis[] = "}]";
const char PrettyPrinter::ignoreCharacter[] = " \n";
const char PrettyPrinter::newLineCharacter[] = "{[}],";
const char PrettyPrinter::beforeAfterSpaceCharacter[] = ":";

void PrettyPrinter::printIndent() {
  for (int i = 0; i < this->indentCount; ++i) {
    std::cout << "  ";
  }
}

PrettyPrinter::PrettyPrinter()
: indentCount(0),
  lastPrintCharacter(0)
{ }

void PrettyPrinter::processLine(const std::string& line) {
  for (std::string::const_iterator it = line.begin(); it != line.end(); ++it) {
    if (contains(PrettyPrinter::closeParenthesis, sizeof(PrettyPrinter::closeParenthesis), *it)) {
      --this->indentCount;
    }

    if (this->lastPrintCharacter == '\n') {
      this->printIndent();
    }

    if (contains(PrettyPrinter::beforeAfterSpaceCharacter, sizeof(PrettyPrinter::beforeAfterSpaceCharacter), *it)) {
      std::cout << ' ';
      this->lastPrintCharacter = ' ';
    }

    if (!contains(PrettyPrinter::ignoreCharacter, sizeof(PrettyPrinter::ignoreCharacter), *it)) {
      std::cout << *it;
      this->lastPrintCharacter = *it;
    }

    if (contains(PrettyPrinter::beforeAfterSpaceCharacter, sizeof(PrettyPrinter::beforeAfterSpaceCharacter), *it)) {
      std::cout << ' ';
      this->lastPrintCharacter = ' ';
    }

    if (contains(PrettyPrinter::openParenthesis, sizeof(PrettyPrinter::openParenthesis), *it)) {
      ++this->indentCount;
    }

    if (contains(PrettyPrinter::newLineCharacter, sizeof(PrettyPrinter::newLineCharacter), *it)) {
      std::cout << std::endl;
      this->lastPrintCharacter = '\n';
    }
  }
}

int main() {
  std::string line;

  PrettyPrinter prettyPrinter = PrettyPrinter();

  while (std::getline(std::cin, line)) {
    prettyPrinter.processLine(line);
  }

  return 0;
}
