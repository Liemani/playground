#include <iostream>
#include "util.hpp"

using std::cin;
using std::cout;
using std::endl;

template <typename T, typename U>
struct Pair {
    T command;
    U method;
};



class Program {
private:
    typedef void (Program::*Method)(void);
    typedef Pair<const char*, Method> MethodPair;

private:
    // instance variables
    std::string string;

    // class members
    static const MethodPair methodDictionary[];
    static void describeMethodCommand(void);

    // instance methods
    void describe(void);
    void reserve(void);
    void memcpy(void);
    void append(void);

public:
    Program(void): string() { };

    void mainLoop(void);
};  // class Program



// class variables
const Program::MethodPair Program::methodDictionary[] = {
    { "describe", &Program::describe },
    { "reserve", &Program::reserve },
    { "memcpy", &Program::memcpy },
    { "append", &Program::append },
};



// MARK: - instance methods
void Program::describe(void) {
    cout << "string: \"" << this->string << "\"" << endl;
    cout << "this->string.empty(): " << this->string.empty() << endl;
    cout << "this->string.size(): " << this->string.size() << endl;
    cout << "this->string.length(): " << this->string.length() << endl;
    cout << "this->string.max_size(): " << this->string.max_size() << endl;
    cout << "this->string.capacity(): " << this->string.capacity() << endl;
    cout << "(void*)this->string.c_str(): " << (void*)this->string.c_str() << endl;
    cout << "this->string.c_str(): \"" << this->string.c_str() << "\"" << endl;
    cout << "(void*)this->string.data(): " << (void*)this->string.data() << endl;
    cout << "this->string.data(): \"" << this->string.data() << "\"" << endl;
    cout << "(void*)&this->string[0]: " << (void*)&this->string[0] << endl;
    cout << "&this->string[0]: \"" << &this->string[0] << "\"" << endl;
}

void Program::reserve(void) {
    unsigned long size;

    getUnsingedLong(cin, "enter size to reserve: ", size);
    this->string.reserve(size);
}

void Program::memcpy(void) {
    std::string stringToCopy;

    getSingleLine(cin, "enter string to memcpy(): ", stringToCopy);
    std::memcpy(&this->string[0], stringToCopy.data(), stringToCopy.length() + 1);
    printSuccessMessage("memcpy()");
}

void Program::append(void) {
    std::string stringToAppend;

    getSingleLine(cin, "enter string to append(): ", stringToAppend);
    this->string.append(stringToAppend);
    printSuccessMessage("this->string.append()");
}



// MARK: - program
void Program::mainLoop(void) {
    std::string line;

    while (true) {
        cout << endl << "enable command list:" << endl;
        Program::describeMethodCommand();
        cout << "--------------" << endl;
        getSingleLine(cin, "enter command: ", line);

        unsigned long i;
        for (i = 0; i < sizeof(methodDictionary) / sizeof(MethodPair); ++i) {
            const MethodPair* pair = &methodDictionary[i];

            if (line == pair->command)
                break;
        }
        if (i == sizeof(methodDictionary) / sizeof(MethodPair)) {
            cout << "not found: [" << line << "]" << endl;
            continue;
        }
        try {
            const MethodPair* pair = &methodDictionary[i];
            (this->*(pair->method))();
        } catch(const char* string) {
            cout << line << ": " << string << endl;
            cout << "errno: " << errno << endl;
        }
    }
}



// MARK: - class method
void Program::describeMethodCommand(void) {
    for (unsigned long i = 0; i < sizeof(methodDictionary) / sizeof(MethodPair); ++i) {
        const MethodPair& pair = methodDictionary[i];

        cout << "\t" << pair.command << endl;
    }
}



// MARK: - main
int main(void) {
    Program program;

    program.mainLoop();

    return 0;
}
