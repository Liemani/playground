int	main(void) {
	int	array[2][3] = {
		{ 5, 4, 3, },
		{ 2, 1, 0, },
	};
	int	(*pointerArray)[3];
	int	*pointer;

	pointerArray = array;
	pointerArray += 1;
	pointer = *array;
	pointer = *array + 1;

	return 0;
}
