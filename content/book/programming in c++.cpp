#include <iostream>

#define EXECUTE	a001

//	void	a001(int argc, char **argv)
//	{
//		(void)argc;
//		(void)argv;



// 34p
// practice getopt()
#include <unistd.h>

void	a001(int argc, char **argv) {
	int	ch;

	if (argc < 2) {
		std::cout << "need argument" << std::endl;
	}

	(void)argc;
	(void)argv;
	while ((ch = getopt(argc, argv, "ab:")) != EOF) {
		switch (ch) {
			case 'a':
				std::cout << "option a" << std::endl;
				break ;
			case 'b':
				std::cout << "option b" << std::endl;
				break ;
			case '?':
				std::cout << "error" << std::endl;
				break ;
		}
	}
}



// C++ has bool with constants true and false
// print value of true and false
void	a000(int argc, char **argv)
{
	const bool	true_constant = true;
	const bool	false_constant = false;

	(void)argc;
	(void)argv;
	std::cout << true_constant;
	std::cout << false_constant;
}



int	main(int argc, char **argv)
{
	EXECUTE(argc, argv);
}
