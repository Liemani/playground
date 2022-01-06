#include <cassert>

#define EXECUTE	a000

//	void	a000(int argc, char **argv)
//	{
//		(void)argc;
//		(void)argv;
//	}



// use assert()
void	a000(int argc, char **argv)
{
	assert(argc != 1);
}



int	main(int argc, char **argv)
{
	EXECUTE(argc, argv);
}
