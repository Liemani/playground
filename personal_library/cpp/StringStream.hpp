#ifndef STREAM_HPP
#define STREAM_HPP

/*
usage {
  int fd = newFD();
  Stream stream = Stream(fd);
  stream.appendWriteBuffer("message");
  stream.write();
  close(fd);
}
*/

#include <string>

class Stream {

public :
  Stream(int fd = -1);

  const std::string& readBuffer() const;
  void appendWriteBuffer(const std::string& string);

  ssize_t read();
  ssize_t write();

  bool isWriteBuffer();

private :
  int _fd;

  std::string _readBuffer;

  std::string _writeBuffer;
  unsigned int _writeCount;

};

#endif  // STREAM_HPP
