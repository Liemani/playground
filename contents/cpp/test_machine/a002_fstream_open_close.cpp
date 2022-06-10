#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>

using std::cin;
using std::cout;
using std::endl;

const int BUF_SIZE = 1024;

static void lmi_getline(std::istream& istream, std::string& line);

template <typename T, typename U>
struct Pair {
    T command;
    U method;
};

class Program {
private:
    typedef void* (Program::*Method)(void);
    typedef Pair<const char*, Method> MethodPair;

    std::string inputPath;
    std::string outputPath;
    std::ifstream input;
    std::ofstream output;

    std::string inputFDPath;
    std::string outputFDPath;
    int inputFD;
    int outputFD;

    static void describeMethodCommand(void);

    void* describe(void);
    void* describeInputOpen(void);
    void* describeOutputOpen(void);
    bool isInputOpen(void);
    bool isOutputOpen(void);
    void* openInput(void);
    void* openOutput(void);
    void* openInputFD(void);
    void* openOutputFD(void);
    void* close(void);
    void* closeInput(void);
    void* closeOutput(void);
    void* remove(void);
    void* unlink(void);
    void* readLine(void);
    void* writeLine(void);
    void* readFDLine(void);
    void* writeFDLine(void);
    void* clear(void);
    void* custom(void);

    static const MethodPair methodDictionary[];

public:
    Program()
    : inputFD(-1)
    , outputFD(-1)
    { }

    void mainLoop(void);
};

const Program::MethodPair Program::methodDictionary[] = {
    { "describe", &Program::describe },
    { "open input", &Program::openInput },
    { "open output", &Program::openOutput },
    { "open input fd", &Program::openInputFD },
    { "open output fd", &Program::openOutputFD },
    { "close", &Program::close },
    { "close input", &Program::closeInput },
    { "close output", &Program::closeOutput },
    { "remove", &Program::remove },
    { "unlink", &Program::unlink },
    { "read line", &Program::readLine },
    { "write line", &Program::writeLine },
    { "read fd line", &Program::readFDLine },
    { "write fd line", &Program::writeFDLine },
    { "clear", &Program::clear },
    { "custom", &Program::custom },
};



// MARK: - method
void* Program::describe(void) {
    cout << "input path: " << this->inputPath << endl;
    cout << "output path: " << this->outputPath << endl;
    this->describeInputOpen();
    this->describeOutputOpen();

    return NULL;
}

void* Program::describeInputOpen(void) {
    if (this->isInputOpen())
        cout << "yes! input file is open" << endl;
    else
        cout << "no! input file is closed" << endl;

    return NULL;
}

void* Program::describeOutputOpen(void) {
    if (this->isOutputOpen())
        cout << "yes! output file is open" << endl;
    else
        cout << "no! output file is closed" << endl;

    return NULL;
}

bool Program::isInputOpen(void) {
    return this->input.is_open();
}

bool Program::isOutputOpen(void) {
    return this->output.is_open();
}

void* Program::openInput(void) {
    if (this->isInputOpen())
        throw "input is already  open!";

    cout << "current input path: " << this->inputPath << endl;
    cout << "enter new input file path: ";

    lmi_getline(cin, this->inputPath);
    this->input.open(this->inputPath);
    if (this->input.is_open())
        cout << "succeeded opening: " << this->inputPath << endl;
    else {
        cout << "failed opening: " << this->inputPath << endl;
        this->inputPath.clear();
    }

    return NULL;
}

void* Program::openOutput(void) {
    if (this->isOutputOpen())
        throw "output is already  open!";

    cout << "current output path: " << this->outputPath << endl;
    cout << "enter new output file path: ";

    lmi_getline(cin, this->outputPath);
    this->output.open(this->outputPath);
    if (this->output.is_open())
        cout << "succeeded opening: " << this->outputPath << endl;
    else {
        cout << "failed opening: " << this->outputPath << endl;
        this->outputPath.clear();
    }

    return NULL;
}

void* Program::openInputFD(void) {
    if (this->inputFD != -1)
        throw "input fd is already  open!";

    cout << "current input fd path: " << this->inputFDPath << endl;
    cout << "enter new input file path: ";

    lmi_getline(cin, this->inputFDPath);
    this->inputFD = open(this->inputFDPath.c_str(), O_RDONLY);
    if (this->inputFD != -1)
        cout << "succeeded opening: " << this->inputFDPath << endl;
    else {
        cout << "failed opening: " << this->inputFDPath << endl;
        this->inputFDPath.clear();
    }

    return NULL;
}

void* Program::openOutputFD(void) {
    if (this->outputFD != -1)
        throw "output fd is already  open!";

    cout << "current output fd path: " << this->outputFDPath << endl;
    cout << "enter new output file path: ";

    lmi_getline(cin, this->outputFDPath);
    this->outputFD = open(this->outputFDPath.c_str(), O_WRONLY | O_CREAT | O_TRUNC);
    if (this->outputFD != -1)
        cout << "succeeded opening: " << this->outputFDPath << endl;
    else {
        cout << "failed opening: " << this->outputFDPath << endl;
        this->outputFDPath.clear();
    }

    return NULL;
}

void* Program::close(void) {
    this->closeInput();
    this->closeOutput();
    this->closeInputFD();
    this->closeOutput();

    return NULL;
}

void* Program::closeInput(void) {
    if (!this->isInputOpen())
        throw "no file to close";

    this->inputPath.clear();
    this->input.close();

    cout << "input is closed" << endl;

    return NULL;
}

void* Program::closeOutput(void) {
    if (!this->isOutputOpen())
        throw "no file to close";

    this->outputPath.clear();
    this->output.close();

    cout << "output is closed" << endl;

    return NULL;
}

void* Program::closeInputFD(void) {
    if (this->inputFD == -1)
        throw "no file to close";

    this->inputFDPath.clear();
    ::close(this->inputFD);
    this->inputFD = -1;

    cout << "input fd is closed" << endl;

    return NULL;
}

void* Program::closeOutputFD(void) {
    if (this->outputFD == -1)
        throw "no file to close";

    this->outputPath.clear();
    ::close(this->outputFD);
    this->outputFD = -1;

    cout << "output fd is closed" << endl;

    return NULL;
}

void* Program::remove(void) {
    cout << "enter file path to remove: ";

    std::string path;
    lmi_getline(cin, path);
    if (::remove(path.c_str()) == 0)
        cout << "removed " << path << endl;
    else
        cout << "errno: " << errno << endl;

    return NULL;
}

void* Program::unlink(void) {
    cout << "enter file path to unlink: ";

    std::string path;
    lmi_getline(cin, path);
    if (::unlink(path.c_str()) == 0)
        cout << "unlinkd " << path << endl;
    else
        cout << "errno: " << errno << endl;

    return NULL;
}

void* Program::custom(void) {
    if (this->isOutputOpen())
        throw "output is already  open!";

    cout << "current output path: " << this->outputPath << endl;
    cout << "enter new output file path: ";

    lmi_getline(cin, this->outputPath);
    this->output.open(this->outputPath, std::ios_base::out);
    if (this->output.is_open())
        cout << "succeeded opening: " << this->outputPath << endl;
    else
        cout << "failed opening: " << this->outputPath << endl;

    return NULL;
}

void* Program::readLine(void) {
    if (!this->isInputOpen())
        throw "no file to read";

    std::string line;
    lmi_getline(this->input, line);
    cout << "line: " << line << endl;

    return NULL;
}

void* Program::writeLine(void) {
    if (!this->isOutputOpen())
        throw "no file to write";

    std::string line;
    lmi_getline(cin, line);
    this->output << line << endl;
    cout << "write succeeded" << endl;

    return NULL;
}

void* Program::readFDLine(void) {
    char line[BUF_SIZE];
    if (this->inputFD == -1)
        throw "no file to read";

    ssize_t readByteCount;
    readByteCount = read(this->inputFD, line, BUF_SIZE - 1);
    line[readByteCount] = '\0';
    cout << "line: " << line << endl;
    cout << "read byte count: " << readByteCount << endl;

    return NULL;
}

void* Program::writeFDLine(void) {
    if (this->outputFD == -1)
        throw "no file to write";

    std::string line;
    lmi_getline(cin, line);
    ssize_t writeByteCount;
    writeByteCount = write(this->outputFD, line.c_str(), line.length());
    cout << "write byte count: " << writeByteCount << endl;

    return NULL;
}

void* Program::clear(void) {
    this->input.clear();
    this->output.clear();
    cout << "cleared input" << endl;
    cout << "cleared output" << endl;

    return NULL;
}


// MARK: - program
void Program::mainLoop(void) {
    std::string line;

    while (true) {
        cout << endl << "enable command list:" << endl;
        Program::describeMethodCommand();
        cout << "----------" << endl;
        cout << "enter command: ";

        lmi_getline(cin, line);

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
        }
    }
}

// MARK: - static
void Program::describeMethodCommand(void) {
    for (unsigned long i = 0; i < sizeof(methodDictionary) / sizeof(MethodPair); ++i) {
        const MethodPair& pair = methodDictionary[i];

        cout << "\t" << pair.command << endl;
    }
}

static void lmi_getline(std::istream& istream, std::string& line) {
    std::getline(istream, line);
    if (!istream)
        throw "failed getline";
}



// MARK: - main
int main(void) {
    Program program;

    program.mainLoop();

    return 0;
}
