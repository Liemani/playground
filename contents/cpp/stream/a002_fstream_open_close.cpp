#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

using std::cin;
using std::cout;
using std::endl;

class Program {
private:
    std::ifstream inputFileStream;

    typedef void (Program::*Method)(void);
    typedef std::pair<std::string, Method> MethodMapElementType;
    typedef std::map<std::string, Method> MethodMap;

    void setInputFileStream(void);
    void isInputFileStreamOpen(void);
    void displayALine(void);
    void closeInputFileStream(void);

    static const MethodMap methodMap;

public:
    void mainLoop(void);
};

const Program::MethodMap Program::methodMap = {
    { "a", &Program::setInputFileStream },
    { "b", &Program::isInputFileStreamOpen },
    { "c", &Program::displayALine },
    { "d", &Program::closeInputFileStream },
};

void Program::mainLoop(void) {
    std::string line;

    while (true) {
        cout << endl << "Enter command" << endl;

        getline(cin, line);
        if (!cin)
            break;

        Program::MethodMap::const_iterator iter = Program::methodMap.find(line);
        if (iter == Program::methodMap.end())
            continue;
        (this->*(iter->second))();
    }
}

void Program::setInputFileStream(void) {
    std::string line;

    cout << "Enter file path" << endl;

    getline(cin, line);
    if (!cin) {
        cout << "cin error has occured" << endl;
        cin.clear();
        return;
    }
    this->inputFileStream.open(line);
}

void Program::isInputFileStreamOpen(void) {
    if (!this->inputFileStream.is_open())
        cout << "file open failed" << endl;
    else
        cout << "file open succeeded" << endl;
}

void Program::displayALine(void) {
    std::string line;

    getline(this->inputFileStream, line);
    cout << line << endl;
}

void Program::closeInputFileStream(void) {
    this->inputFileStream.close();
}

int main(void) {
    Program program;

    program.mainLoop();

    return 0;
}
