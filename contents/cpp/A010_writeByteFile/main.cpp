#include <iostream>
#include <fstream>

//	./command <int value> <file name> <position>

namespace ArgumentIndex {
	enum {
		command,
		intValue,
		fileName,
		position,
		count
	};
}

void describeUsage(char* command) {
	std::cout << "usage: " << command << " <int value> <file name> <position>" << std::endl;
}

int main(int argc, char** argv) {
	if (argc != ArgumentIndex::count) {
		describeUsage(argv[ArgumentIndex::command]);
		return -1;
	}

	std::fstream fs(argv[ArgumentIndex::fileName], std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	if (!fs.is_open()) {
		std::cout << "failed opening file" << std::endl;
	}
	fs.seekg(atoi(argv[ArgumentIndex::position]));
	int intValue = atoi(argv[ArgumentIndex::intValue]);
	fs.write(reinterpret_cast<char*>(&intValue), sizeof(int));

	fs.close();

	return 0;
}
