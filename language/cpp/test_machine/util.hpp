#ifndef UTIL_HPP
#define UTIL_HPP

const int BUF_SIZE = 1024;

void getLine(std::istream& istream, std::string& line);
void getSingleLine(std::istream& istream, const char* prompt, std::string& line);
void getMultiLine(std::istream& istream, const char* prompt, std::string& line, const char* delimiter, const char* lineSeparator);
void getUnsingedLong(std::istream& istream, const char* prompt, unsigned long& ul);

void printSuccessMessage(const char* description);
void printFailMessage(const char* description);
void print16Bytes(const std::string& bytes);
void sockaddr_in_describe(struct sockaddr_in& socketAddress);

#endif  // UTIL_HPP
