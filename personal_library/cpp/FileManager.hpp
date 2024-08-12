#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <fstream>
#include <string>

class FileManager {

public :
  static std::ifstream openIFStreamAs(std::string path);

};

#endif // FILEMANAGER_HPP
