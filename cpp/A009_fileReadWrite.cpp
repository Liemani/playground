#include <iostream>
#include <fstream>

void describeUsage(char* path) {
	std::cout << "usage: " << path << " read <file-name>\n"
		<< "usage: " << path << " write <file-name> <int-value>" << std::endl;
}

int main(int argc, char** argv) {
	if (strcmp(argv[1], "read") == 0) {
		if (argc != 3) {
			describeUsage(argv[0]);
			return -1;
		}

		std::ifstream ifs(argv[2]);
		if (!ifs.is_open()) {
			std::cout << "failed opening file" << std::endl;
			return -1;
		}
		int number;
		ifs.read(reinterpret_cast<char*>(&number), sizeof(number));
		if (!ifs) {
			std::cout << "failed reading file" << std::endl;
			return -1;
		}
		std::cout << number << std::endl;
		ifs.close();
	}
	else if (strcmp(argv[1], "write") == 0) {
		if (argc != 4) {
			describeUsage(argv[0]);
			return -1;
		}

		std::ofstream ofs(argv[2]);
		if (!ofs.is_open()) {
			std::cout << "failed opening file" << std::endl;
			return -1;
		}
		int number = atoi(argv[3]);
		ofs.write(reinterpret_cast<char*>(&number), sizeof(int));
		if (!ofs) {
			std::cout << "failed writing file" << std::endl;
			return -1;
		}
		ofs.close();
	}
	else {
		describeUsage(argv[0]);
		return -1;
	}

	return 0;
}
