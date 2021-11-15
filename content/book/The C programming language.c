#include <stdio.h>

#define EXECUTE	a018



//	copy paste this function prototype
//	int	a000(int argc, char **argv)
//	{
//		(void)argc;
//		(void)argv;
//		return (0);
//	}



int	is_digit(char ch)
{
	return ('0' <= ch && ch <= '9');
}

int	is_space(char ch);

int	a018(int argc, char **argv)
{
	int	ch;
	int	index;
	int	digit_count[10];
	int	white_space_ch_count;
	int	other_count;

	(void)argc;
	(void)argv;
	index = 0;
	while (index <= 9)
		digit_count[index++] = 0;
	white_space_ch_count = 0;
	other_count = 0;
	while ((ch = getchar()) != EOF)
	{
		if (is_digit(ch))
			++digit_count[ch - '0'];
		else if (is_space(ch))
			++white_space_ch_count;
		else
			++other_count;
	}
	printf("digits =");
	index = 0;
	while (index <= 9)
		printf(" %d", digit_count[index++]);
	printf("\nwhite_space_ch_count: %d, other_count: %d \n", white_space_ch_count, other_count);
	return (0);
}



#define BEFORE_WORD	0
#define IN_WORD		1
#define AFTER_WORD	2

int	is_space(char ch);

int	a017(int argc, char **argv)
{
	int	ch;
	int	state;

	(void)argc;
	(void)argv;
	state = BEFORE_WORD;
	while ((ch = getchar()) != EOF)
	{
		if (state == BEFORE_WORD)
		{
			if (ch == '\n')
				putchar(ch);
			else if (!is_space(ch))
			{
				putchar(ch);
				state = IN_WORD;
			}
		}
		else if (state == IN_WORD)
		{
			if (ch == '\n')
			{
				state = BEFORE_WORD;
				putchar(ch);
			}
			else if (ch == ' ' || ch == '\t')
				state = AFTER_WORD;
			else
				putchar(ch);
		}
		else
			if (ch == '\n')
			{
				putchar(ch);
				state = BEFORE_WORD;
			}
	}
	return (0);
}



#define OUT_WORD	0
#define IN_WORD		1

int	is_space(char ch);

int	a016(int argc, char **argv)
{
	int	ch;
	int	ch_count;
	int	word_count;
	int	line_count;
	int	state;

	(void)argc;
	(void)argv;
	ch_count = 0;
	word_count = 0;
	line_count = 0;
	state = OUT_WORD;
	while ((ch = getchar()) != EOF)
	{
		++ch_count;
		if (ch == '\n')
			++line_count;
		if (is_space(ch))
			state = OUT_WORD;
		else if (state == OUT_WORD)
		{
			state = IN_WORD;
			++word_count;
		}
	}
	printf("%d %d %d \n", ch_count, word_count, line_count);
	return (0);
}



#define FALSE	0
#define TRUE	1

int	is_space(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n');
}

int	a015(int argc, char **argv)
{
	int	ch;
	int	word_count;
	int	is_previous_ch_space;

	(void)argc;
	(void)argv;
	word_count = 0;
	is_previous_ch_space = TRUE;
	while ((ch = getchar()) != EOF)
	{
		if (is_space(ch))
			is_previous_ch_space = TRUE;
		else if (is_previous_ch_space)
		{
			++word_count;
			is_previous_ch_space = FALSE;
		}
	}
	printf("word_count is %d \n", word_count);
	return (0);
}



int	a014(int argc, char **argv)
{
	int	ch;

	(void)argc;
	(void)argv;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\t')
		{
			putchar('\\');
			putchar('t');
		}
		else if (ch == '\b')
		{
			putchar('\\');
			putchar('b');
		}
		else if (ch == '\\')
		{
			putchar('\\');
			putchar('\\');
		}
		else
			putchar(ch);

	}
	return (0);
}



#define FALSE	0
#define TRUE	1

int	a013(int argc, char **argv)
{
	int	ch;
	int	is_previous_ch_blank;

	(void)argc;
	(void)argv;
	is_previous_ch_blank = FALSE;
	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ')
		{
			if (!is_previous_ch_blank)
			{
				putchar(ch);
				is_previous_ch_blank = TRUE;
			}
		}
		else
		{
			putchar(ch);
			is_previous_ch_blank = FALSE;
		}
	}
	return (0);
}



int	a012(int argc, char **argv)
{
	int	ch;
	int	space_count;

	(void)argc;
	(void)argv;
	space_count = 0;
	while ((ch = getchar()) != EOF)
		if (ch == ' ' || ch == '\t' || ch == '\n')
			++space_count;
	printf("space_count is %d \n", space_count);
	return (0);
}



int	a011(int argc, char **argv)
{
	int	ch;
	int	line_count;

	(void)argc;
	(void)argv;
	line_count = 0;
	while ((ch = getchar()) != EOF)
		if (ch == '\n')
			++line_count;
	printf("line_count is %d \n", line_count);
	return (0);
}



int	a010(int argc, char **argv)
{
	int	ch_count;

	(void)argc;
	(void)argv;
	ch_count = 0;
	while (getchar() != EOF)
		++ch_count;
	printf("ch_count is %d \n", ch_count);
	return (0);
}



int	a009(int argc, char **argv)
{
	int	c;

	(void)argc;
	(void)argv;
	while ((c = getchar()) != EOF)
		putchar(c);
	printf("EOF: [%d]\n", c);
	return (0);
}



int	a008(int argc, char **argv)
{
	int	c;

	(void)argc;
	(void)argv;
	c = getchar();
	while (c != EOF)
	{
		putchar(c);
		c = getchar();
	}
	return (0);
}



#define LOWER	0
#define UPPER	300
#define STEP	20

int	a007(int argc, char **argv)
{
	float	fahrenheit;
	float	celsius;

	(void)argc;
	(void)argv;
	printf("fahrenheit celsius\n");
	fahrenheit = LOWER;
	while (fahrenheit <= UPPER)
	{
		celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
		printf("%5.1f %8.1f\n", fahrenheit, celsius);
		fahrenheit += STEP;
	}
	return (0);
}



int	a006(int argc, char **argv)
{
	float	fahrenheit;
	float	celsius;
	int		lower;
	int		upper;
	int		step;

	(void)argc;
	(void)argv;
	lower = 300;
	upper = 0;
	step = -20;
	printf("fahrenheit celsius\n");
	fahrenheit = lower;
	while (fahrenheit >= upper)
	{
		celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
		printf("%5.1f %8.1f\n", fahrenheit, celsius);
		fahrenheit += step;
	}
	return (0);
}



int	a005(int argc, char **argv)
{
	float	fahrenheit;
	float	celsius;
	int		lower;
	int		upper;
	int		step;

	(void)argc;
	(void)argv;
	lower = 0;
	upper = 300;
	step = 20;
	printf("fahrenheit celsius\n");
	fahrenheit = lower;
	while (fahrenheit <= upper)
	{
		celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
		printf("%5.1f %8.1f\n", fahrenheit, celsius);
		fahrenheit += step;
	}
	return (0);
}



int	a004(int argc, char **argv)
{
	float	fahrenheit;
	float	celsius;
	int		lower;
	int		upper;
	int		step;

	(void)argc;
	(void)argv;
	lower = 0;
	upper = 300;
	step = 20;
	fahrenheit = lower;
	while (fahrenheit <= upper)
	{
		celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
		printf("%5.1f %8.1f\n", fahrenheit, celsius);
		fahrenheit += step;
	}
	return (0);
}



int	a003(int argc, char **argv)
{
	int	fahrenheit;
	int	celsius;
	int	lower;
	int	upper;
	int	step;

	(void)argc;
	(void)argv;
	lower = 0;
	upper = 300;
	step = 20;
	fahrenheit = lower;
	while (fahrenheit <= upper)
	{
		celsius = (fahrenheit - 32) * (5.0 / 9.0);
		printf("%3d %6d\n", fahrenheit, celsius);
		fahrenheit += step;
	}
	return (0);
}



int	a002(int argc, char **argv)
{
	float	celsius;
	float	fahrenheit;

	(void)argc;
	(void)argv;
	celsius = 0;
	while (celsius <= 300)
	{
		fahrenheit = celsius * (9.0 / 5.0) + 32;
		printf("%.0f\t%.0f\n", celsius, fahrenheit);
		celsius += 20;
	}
	return (0);
}



int	a001(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("hello, ");
	printf("world");
	printf("\n");
//		printf("\c");
	return (0);
}



int	a000(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("hello, world\n");
	return (0);
}



int	main(int argc, char **argv)
{
	return (EXECUTE(argc, argv));
}
