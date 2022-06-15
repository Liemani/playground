#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

using std::cin;
using std::cout;
using std::endl;

static void lmi_getline(std::istream& istream, std::string& line);
static void lmi_getSingleLine(std::istream& istream, const char* prompt, std::string& line);

// const int BUF_SIZE = 8192;

template <typename T, typename U>
struct Pair {
    T command;
    U method;
};

class Program {
private:
    // variables
    std::string string;

    // instance methods
    void* describe(void);

    // class members
    typedef void* (Program::*Method)(void);
    typedef Pair<const char*, Method> MethodPair;

    static const MethodPair methodDictionary[];
    static void describeMethodCommand(void);

public:
    Program(void): string() { };

    void mainLoop(void);
};

// class variables
const Program::MethodPair Program::methodDictionary[] = {
    { "describe", &Program::describe },
};



// MARK: - instance methods
void* Program::describe(void) {
    cout << "string: \"" << this->string << "\"" << endl;
    cout << "this->string.empty(): " << this->string.empty() << endl;
    cout << "this->string.size(): " << this->string.size() << endl;
    cout << "this->string.length(): " << this->string.length() << endl;
    cout << "this->string.max_size(): " << this->string.max_size() << endl;
    cout << "this->string.capacity(): " << this->string.capacity() << endl;

    return NULL;
}

void* Program::reserve(void) {

}



// MARK: - program
void Program::mainLoop(void) {
    std::string line;

    while (true) {
        cout << endl << "enable command list:" << endl;
        Program::describeMethodCommand();
        cout << "--------------" << endl;
        lmi_getSingleLine(cin, "enter command: ", line);

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

// MARK: - static
static void lmi_getline(std::istream& istream, std::string& line) {
    std::getline(istream, line);
    if (!istream)
        throw "failed getline";
}

static void lmi_getSingleLine(std::istream& istream, const char* prompt, std::string& line) {
    cout << prompt;
    lmi_getline(istream, line);
}



// MARK: - main
int main(void) {
    Program program;

    program.mainLoop();

    return 0;
}
