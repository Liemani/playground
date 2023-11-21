// Let's see assembly code of postfix increment operator
int	main(void)
{
	int	array1[4];
	int	array2[4];
	int	*ptr1 = array1;
	int	*ptr2 = array2;

//		ptr1 = array1;
//		ptr2 = array2;
	*ptr1++ = *ptr2++;
	return (0);
}
