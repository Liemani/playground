const int	size = 2;

int	main(void) {
	int	array[size] = { 2, 1 };
	int*	pointer;

	pointer = array + 1;
	if (pointer - array < size)
		*pointer = 0;

	return 0;
}
