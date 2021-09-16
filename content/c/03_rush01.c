#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char array[4][4] = { 0 };
	char numbers[2][4];
	char index;

	getNumber(numbers, argv[1]);

	index = 0;
	while (index != 16) {
		while (hasProblem) {
			++array[index];

			if (array[index] == 5) {
				array[index] = 0;
				--index;
			}
		}

		++index;
	}

	return 0;
}
