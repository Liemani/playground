const int	size = 3;

int	main(void) {
	int	array[size] = { 3, 2, 1 };
	const int*	end = array + size;

	for (int* pointer = array; pointer < end; pointer += 1)
		*pointer = 0;

	return 0;
}
