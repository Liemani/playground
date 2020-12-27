typedef int my_variable;
typedef my_variable * my_variable_p;

int main()
{
	my_variable_p a, b, c;
	my_variable z;

	b = a;
	b = &z;

	return (0);
}
