#include "FileManager.hpp"
#include "ErrorHandler.hpp"

std::ifstream FileManager::openIFStreamAs(std::string path) {
  std::ifstream ifstream;
  ifstream.open(path, std::ios::in);

  if (not ifstream.is_open()) {
    ErrorHandler::exitWithMessage();
  }

  return ifstream;
}
