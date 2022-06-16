#include <iostream>
#include <sstream>
#include <iomanip>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "util.hpp"

using std::cout;
using std::endl;

void getLine(std::istream& istream, std::string& line) {
    std::getline(istream, line);
    if (!istream)
        throw "failed getline";
}

void getSingleLine(std::istream& istream, const char* prompt, std::string& line) {
    cout << prompt;
    getline(istream, line);
}

void getMultiLine(std::istream& istream, const char* prompt, std::string& line, const char* delimiter, const char* lineSeparator) {
    std::string tempLine;

    cout << prompt << ", enter [" << delimiter << "] to quit: " << endl;

    line.clear();
    while (true) {
        getline(istream, tempLine);
        if (tempLine == delimiter)
            break;
        else {
            line += tempLine;
            line += lineSeparator;
        }
    }
}

void getUnsingedLong(std::istream& istream, const char* prompt, unsigned long& ul) {
    std::string tempString;
    unsigned long tempUL;

    getSingleLine(istream, prompt, tempString);
    std::istringstream istringstream(tempString);
    istringstream >> tempUL;
    if (istringstream.get() != EOF)
        throw "fail reading unsinged long type value";
    else
        ul = tempUL;
}



void printSuccessMessage(const char* description) {
    cout << "[success: " << description << "]" << endl;
}

void printFailMessage(const char* description) {
    cout << "[fail: " << description << "]" << endl;
}

void print16Bytes(const std::string& bytes) {
    const std::ios_base::fmtflags ff = cout.flags();

    for (int i = 0; i < 16; ++i) {
        if (i % 8 == 0)
            cout << "  ";
        else if (i % 2 == 0)
            cout << " ";
        cout << std::hex << std::setfill('0') << std::setw(2) << (int)(unsigned char)bytes[i];
    }

    cout << "   ";
    for (int i = 0; i < 16; ++i) {
        const char ch = bytes[i];
        cout << (std::isprint(ch) ? ch : '.');
    }

    cout << endl;

    cout.flags(ff);
}

void sockaddr_in_describe(struct sockaddr_in& socketAddress) {
    const std::ios_base::fmtflags ff = cout.flags();

	cout << "socketAddress.sin_len: " << socketAddress.sin_len << endl;
	cout << "socketAddress.sin_family: " << std::hex << std::setfill('0') << std::setw(2) << (int)(unsigned char)socketAddress.sin_family << endl;
	cout << "socketAddress.sin_port: " << socketAddress.sin_port << endl;
	cout << "socketAddress.sin_addr: " << socketAddress.sin_addr.s_addr << endl;
    std::string sin_zero = std::string(socketAddress.sin_zero, socketAddress.sin_zero + 7);
	cout << "socketAddress.sin_zero: " << sin_zero << endl;
    print16Bytes(sin_zero);

    cout.flags(ff);
}
