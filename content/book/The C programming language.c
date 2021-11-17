#include <stdio.h>	// printf()
#include <stddef.h>	// size_t, NULL
#include <limits.h>
#include <float.h>

#ifndef EXECUTE
#define EXECUTE	a031
#endif



//	copy paste this function prototype
//	int	a000(int argc, char **argv)
//	{
//		(void)argc;
//		(void)argv;
//		return (0);
//	}



//	2.7
//	In general, the only automatic conversions are those that convert a "narrower" operand into a "wider" one without losing information
//	On some machines a char whose leftmost bit is 1 will be converted to a negative integer ("sign extension"). On others, a char is promoted to an int by adding zeros at the left end, and thus is always positive
//	If an operator has operands of different types, the "lower" type is promoted to the "higher" type before th operation proceeds



//	2.6
//	By definition, the numeric value of a relational or logical expression is 1 if the relation is true, and 0 if the relation is false



//	2.5
//	The direction of truncation for / and the sign of the result for % are machine-dependent for negative operands, as is the action taken on overflow or underflow



//	2.3
//	int: no suffics
//	long: The suffixes 'l' or 'L'
//		An integer too big to fit into an int will also be taken as a long.
//	unsigned: The suffixes u or U
//	unsigned long: The suffixes ul or UL
//	floating point: contain a decimal point or an exponent(1e-2) or both.
//		Their type is double, unless suffixed
//		The suffixes f or F indicate a float constant
//		The suffixes l or L indicate a long double
//	Octal integer constant
//		A leading '0' on an integer constant means octal
//		31 == 037
//	Hexadecimal integer constant
//		A leading "0x" on an integer constant means hexadecimal
//		31 == 0x1f == 0X1F
//	Octal and hexadecimal constants may also be followed by L to make them long and U to make them unsigned
//	A character constant is an integer
//		If we write '0' instead of a numeric value like 48 that depands on character set, the program is independent of the particular value and easier to read
//			'x' is an integer, used to produce the numberic value of the letter x in the machine's character set
//	'\ooo': ooo is one to three octal digits
//	'\xhh': hh is one or more hexadecimal digits
//	'\013' == '\xb', '\007' == '\x7', '\0' = 0
//	String constants can be concatenated at compile time
//		"hello," " world" == "hello, world"
//	The first name in an enum has value 0 unless explicit values are specified
//	Names in different enumerations must be distinct
//	Values need not be distinct in the same enumeration



int	a031(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("sizeof(char): %lu \n", sizeof(char));
	printf("sizeof(signed char): %lu \n", sizeof(signed char));
	printf("sizeof(unsigned char): %lu \n", sizeof(unsigned char));
	printf("sizeof(short): %lu \n", sizeof(short));
	printf("sizeof(signed short): %lu \n", sizeof(signed short));
	printf("sizeof(unsigned short): %lu \n", sizeof(unsigned short));
	printf("sizeof(int): %lu \n", sizeof(int));
	printf("sizeof(signed int): %lu \n", sizeof(signed int));
	printf("sizeof(unsigned int): %lu \n", sizeof(unsigned int));
	printf("sizeof(long): %lu \n", sizeof(long));
	printf("sizeof(signed long): %lu \n", sizeof(signed long));
	printf("sizeof(unsigned long): %lu \n", sizeof(unsigned long));
	printf("sizeof(long long): %lu \n", sizeof(long long));
	printf("sizeof(signed long long): %lu \n", sizeof(signed long long));
	printf("sizeof(unsigned long long): %lu \n", sizeof(unsigned long long));

	printf("%d <= unsigned char <= %u \n", 0, UCHAR_MAX);
	printf("%d <= unsigned short <= %u \n", 0, USHRT_MAX);
	printf("%d <= unsigned int <= %u \n", 0, UINT_MAX);
	printf("%d <= unsigned long <= %lu \n", 0, ULONG_MAX);
	printf("%d <= unsigned long long <= %llu \n", 0, ULLONG_MAX);
	printf("%d <= signed char <= %d \n", SCHAR_MIN, SCHAR_MAX);
	printf("%d <= char <= %d \n", CHAR_MIN, CHAR_MAX);
	printf("%d <= signed short <= %d \n", SHRT_MIN, SHRT_MAX);
	printf("%d <= int <= %d \n", INT_MIN, INT_MAX);
	printf("%ld <= long <= %ld \n", LONG_MIN, LONG_MAX);
	printf("%f <= float <= %f \n", FLT_MIN, FLT_MAX);
	printf("%f <= double <= %f \n", DBL_MIN, DBL_MAX);
	printf("%Lf <= long double <= %Lf \n", LDBL_MIN, LDBL_MAX);
	return (0);
}



//	2.2
//	qualifier
//	Whether plain chars are signed or unsigned is machine-dependent, but printable characters are always positive.



//	2.1
//	printf("sizeof(double): %lu \n", sizeof(double));	// sizeof(double): 8
//	printf("sizeof(long double): %lu \n", sizeof(long double));	// sizeof(long double): 16



//	Exercise 1-23
#define STATE_NORMAL					0
#define STATE_ENCOUNT_SLASH				1
#define STATE_IN_MULTI_LINE_COMMENT		2
#define STATE_ENCOUNT_ASTERISK			3
#define STATE_IN_SINGLE_QUOTE			4
#define STATE_IN_SINGLE_QUOTE_BACKSLASH 5
#define STATE_IN_DOUBLE_QUOTE			6
#define STATE_IN_DOUBLE_QUOTE_BACKSLASH	7

int	a030(int argc, char **argv)
{
	int	ch;
	int	state;

	(void)argc;
	(void)argv;
	state = STATE_NORMAL;
	while ((ch = getchar()) != EOF)
	{
		if (state == STATE_NORMAL)
		{
			if (ch == '/')
				state = STATE_ENCOUNT_SLASH;
			else if (ch == '\'')
			{
				putchar(ch);
				state = STATE_IN_SINGLE_QUOTE;
			}
			else if (ch == '\"')
			{
				putchar(ch);
				state = STATE_IN_DOUBLE_QUOTE;
			}
			else
				putchar(ch);
		}
		else if (state == STATE_ENCOUNT_SLASH)
		{
			if (ch == '/')
			{
				while ((ch = getchar()) != EOF && ch != '\n')
					;
				if (ch == '\n')
					putchar (ch);
				state = STATE_NORMAL;
			}
			else if (ch == '*')
				state = STATE_IN_MULTI_LINE_COMMENT;
			else if (ch == '\"')
			{
				putchar('/');
				putchar(ch);
				state = STATE_IN_DOUBLE_QUOTE;
			}
			else
			{
				putchar('/');
				putchar(ch);
				state = STATE_NORMAL;
			}
		}
		else if (state == STATE_IN_MULTI_LINE_COMMENT)
		{
			if (ch == '*')
				state = STATE_ENCOUNT_ASTERISK;
		}
		else if (state == STATE_ENCOUNT_ASTERISK)
		{
			if (ch == '/')
				state = STATE_NORMAL;
			else
				state = STATE_IN_MULTI_LINE_COMMENT;
		}
		else if (state == STATE_IN_SINGLE_QUOTE)
		{
			putchar(ch);
			if (ch == '\\')
				state = STATE_IN_SINGLE_QUOTE_BACKSLASH;
			else if (ch == '\'')
				state = STATE_NORMAL;
		}
		else if (state == STATE_IN_SINGLE_QUOTE_BACKSLASH)
		{
			putchar(ch);
			state = STATE_IN_SINGLE_QUOTE;
		}
		else if (state == STATE_IN_DOUBLE_QUOTE)
		{
			putchar(ch);
			if (ch == '\\')
				state = STATE_IN_DOUBLE_QUOTE_BACKSLASH;
			else if (ch == '\"')
				state = STATE_NORMAL;
		}
		else if (state == STATE_IN_DOUBLE_QUOTE_BACKSLASH)
		{
			putchar(ch);
			state = STATE_IN_DOUBLE_QUOTE;
		}
	}
	return (0);
}



//	Exercise 1-23
//	fail, try again
#define STATE_NORMAL					0
#define STATE_IN_SINGLE_LINE_COMMENT	1
#define STATE_IN_MULTI_LINE_COMMENT		2
#ifndef STATE_IN_DOUBLE_QUOTE
#define STATE_IN_DOUBLE_QUOTE			3
#endif

int	is_single_line_comment(char *str)
{
	return (str[0] == '/' && str[1] == '/');
}

int	is_multi_line_comment_open(char *str)
{
	return (str[0] == '/' && str[1] == '*');
}

int	is_multi_line_comment_close(char *str)
{
	return (str[0] == '*' && str[1] == '/');
}

int	is_double_quote(char *str)
{
	return (str[0] != '\\' && str[1] == '\"');
}

int	a029(int argc, char **argv)
{
	int		ch;
	char	ch_str[2];
	int		state;

	(void)argc;
	(void)argv;
	ch_str[0] = '\0';
	ch_str[1] = '\0';
	state = STATE_NORMAL;
	while ((ch = getchar()) != EOF)
	{
		ch_str[0] = ch_str[1];
		ch_str[1] = ch;
		if (state == STATE_NORMAL)
		{
			if (is_single_line_comment(ch_str))
				state = STATE_IN_SINGLE_LINE_COMMENT;
			else if (is_multi_line_comment_open(ch_str))
				state = STATE_IN_MULTI_LINE_COMMENT;
			else if (is_double_quote(ch_str))
			{
				state = STATE_IN_DOUBLE_QUOTE;
				putchar(ch);
			}
			else
				putchar(ch);
		}
		else if (state == STATE_IN_SINGLE_LINE_COMMENT)
		{
			if (ch == '\n')
			{
				putchar(ch);
				state = STATE_NORMAL;
			}
		}
		else if (state == STATE_IN_MULTI_LINE_COMMENT)
		{
			if (is_multi_line_comment_close(ch_str))
				state = STATE_NORMAL;
		}
		else if (state == STATE_IN_DOUBLE_QUOTE)
		{
			putchar(ch);
			if (is_double_quote(ch_str))
				state = STATE_NORMAL;
		}
	}
	return (0);
}



//	Exercise 1-22
///	- assume: TAB_STOP is less than or equal to LINE_COUNT_MAX
#define LINE_COUNT_MAX	80
#ifndef TAB_STOP
#define TAB_STOP		8
#endif
#define STATE_INITIAL_OF_LINE	0
#define STATE_MIDDLE_OF_LINE	1

int	is_blank_or_tab(char ch)
{
	return (ch == ' ' || ch == '\t');
}

void	column_increase(size_t *column, int ch)
{
	if (ch == '\t')
		*column = (*column / TAB_STOP + 1) * TAB_STOP;
	else
		++*column;
}

void	buffer_append(char **buffer_ptr, int ch)
{
	*(*buffer_ptr)++ = ch;
}

void	buffer_flush(char *buffer, char **buffer_ptr)
{
	**buffer_ptr = '\0';
	printf("%s", buffer);
	*buffer_ptr = buffer;
}

void	buffer_remove_trailing_blank_tab(char *buffer, char **buffer_ptr)
{
	while (buffer < *buffer_ptr)
	{
		--*buffer_ptr;
		if (**buffer_ptr != ' ' && **buffer_ptr != '\t')
		{
			++*buffer_ptr;
			break ;
		}
	}
}

int	should_ignore(int line_state, size_t column, int ch)
{
	return (line_state == STATE_MIDDLE_OF_LINE
			&& column == 0
			&& is_blank_or_tab(ch));
}

int	a028(int argc, char **argv)
{
	int		ch;
	int		ch_tmp;
	size_t	column;
	char	buffer[LINE_COUNT_MAX + 2];
	char	*buffer_ptr;
	int		line_state;

	(void)argc;
	(void)argv;
	column = 0;
	buffer_ptr = buffer;
	line_state = STATE_INITIAL_OF_LINE;
	while ((ch = getchar()) != EOF)
	{
		if (should_ignore(line_state, column, ch))
			continue ;
		column_increase(&column, ch);
		if (column > LINE_COUNT_MAX)
		{
			if (ch == '\n')
			{
				buffer_append(&buffer_ptr, ch);
				column = 0;
				buffer_flush(buffer, &buffer_ptr);
				line_state = STATE_INITIAL_OF_LINE;
			}
			else
			{
				ch_tmp = *--buffer_ptr;
				if (!is_blank_or_tab(ch_tmp)
						&& !is_blank_or_tab(*(buffer_ptr - 1)))
					buffer_append(&buffer_ptr, '-');
				buffer_remove_trailing_blank_tab(buffer, &buffer_ptr);
				buffer_append(&buffer_ptr, '\n');
				column = 0;
				buffer_flush(buffer, &buffer_ptr);
				if (!is_blank_or_tab(ch_tmp))
				{
					column_increase(&column, ch);
					buffer_append(&buffer_ptr, ch_tmp);
				}
				if (column != 0 || !is_blank_or_tab(ch))
				{
					column_increase(&column, ch);
					buffer_append(&buffer_ptr, ch);
				}
			}
		}
		else
		{
			buffer_append(&buffer_ptr, ch);
			if (ch == '\n')
			{
				column = 0;
				buffer_flush(buffer, &buffer_ptr);
				line_state = STATE_INITIAL_OF_LINE;
			}
			else
				line_state = STATE_MIDDLE_OF_LINE;
		}
	}
	return (0);
}



//	Exercise 1-21
#ifndef TAB_STOP
#define TAB_STOP	4
#endif

void	tab_buffer_increase(size_t *tab_buffer, size_t column)
{
	++*tab_buffer;
	if (column % TAB_STOP != 0)
		return ;
	putchar('\t');
	*tab_buffer = 0;
}

void	tab_buffer_flush(size_t *tab_buffer)
{
	while (0 < *tab_buffer)
	{
		putchar(' ');
		--*tab_buffer;
	}
}

int	a027(int argc, char **argv)
{
	int		ch;
	size_t	column;
	size_t	tab_buffer;

	(void)argc;
	(void)argv;
	column = 0;
	tab_buffer = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\t')
			column = (column / TAB_STOP + 1) * TAB_STOP;
		else
			++column;
		if (ch == ' ')
			tab_buffer_increase(&tab_buffer, column);
		else
		{
			tab_buffer_flush(&tab_buffer);
			putchar(ch);
		}
		if (ch == '\n')
			column = 0;
	}
	return (0);
}



//	Exercise 1-20
#ifndef TAB_STOP
#define TAB_STOP	4
#endif

int	a026(int argc, char **argv)
{
	int		ch;
	size_t	column;

	(void)argc;
	(void)argv;
	column = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\t')
		{
			putchar(' ');
			++column;
			while (column % TAB_STOP != 0)
			{
				putchar(' ');
				++column;
			}
		}
		else
		{
			putchar(ch);
			++column;
			if (ch == '\n')
				column = 0;
		}
	}
	return (0);
}



//	Exercise 1-19
#ifndef LINE_COUNT_MAX
#define LINE_COUNT_MAX	512
#endif

size_t	get_line(char *line, size_t size);
void	str_cpy(char *target, const char *source);

void	reverse(char *str)
{
	char	str_tmp[LINE_COUNT_MAX];
	char	*ptr;

	if (*str == '\n')
		return ;
	str_cpy(str_tmp, str);
	ptr = str_tmp;
	while (*ptr != '\n')
		++ptr;
	--ptr;
	while (str_tmp <= ptr)
		*str++ = *ptr--;
	*str++ = '\n';
	*str = '\0';
}

int	a025(int argc, char **argv)
{
	char	line[LINE_COUNT_MAX];

	(void)argc;
	(void)argv;
	while (0 < get_line(line, LINE_COUNT_MAX))
	{
		reverse(line);
		printf("%s", line);
	}
	return (0);
}



//	Exercise 1-18
#ifndef LINE_COUNT_MAX
#define LINE_COUNT_MAX	512
#endif

size_t	get_line(char *line, size_t size);

int	a024(int argc, char **argv)
{
	char	line[LINE_COUNT_MAX];
	char	*ptr;

	(void)argc;
	(void)argv;
	while (0 < get_line(line, LINE_COUNT_MAX))
	{
		if (line[0] == '\n')
			continue ;
		ptr = line;
		while (*ptr != '\n')
			++ptr;
		--ptr;
		while (*ptr == ' ' || *ptr == '\t')
			--ptr;
		++ptr;
		*ptr++ = '\n';
		*ptr = '\0';
		printf("%s", line);
	}
	return (0);
}



//	Exercise 1-18
#ifndef LINE_COUNT_MAX
#define LINE_COUNT_MAX	512
#endif

#define	STATE_NORMAL		0
#define STATE_BLANK_OR_TAB	1

int	a023(int argc, char **argv)
{
	int		ch;
	char	line[LINE_COUNT_MAX];
	size_t	index;
	int		state;

	(void)argc;
	(void)argv;
	line[0] = '\0';
	index = 0;
	state = STATE_NORMAL;
	while ((ch = getchar()) != EOF)
	{
		if (state == STATE_NORMAL)
		{
			if (ch == ' ' || ch == '\t')
			{
				state = STATE_BLANK_OR_TAB;
				line[index++] = ch;
			}
			else
				putchar(ch);
		}
		else if (state == STATE_BLANK_OR_TAB)
		{
			if (ch == ' ' || ch == '\t')
				line[index++] = ch;
			else
			{
				state = STATE_NORMAL;
				line[index] = '\0';
				index = 0;
				printf("%s", line);
				putchar(ch);
			}
		}
		if (index >= LINE_COUNT_MAX)
			return (0);
	}
	return (0);
}



//	Exercise 1-17
#ifndef LINE_COUNT_MAX
#define LINE_COUNT_MAX	512
#endif

size_t	get_line(char *line, size_t size);
void	str_cpy(char *target, const char *source);

int	a022(int argc, char **argv)
{
	char	line[LINE_COUNT_MAX];
	size_t	line_count;

	(void)argc;
	(void)argv;
	while ((line_count = get_line(line, LINE_COUNT_MAX)) != 0)
	{
		if (line_count > 80)
			printf("%s", line);
	}
	return (0);
}



//	1.9
#ifndef LINE_COUNT_MAX
#define LINE_COUNT_MAX	512
#endif

size_t	get_line(char *line, size_t size)
{
	int		ch;
	size_t	index;

	index = 0;
	while (index < size - 1 && (ch = getchar()) != '\n' && ch != EOF)
	{
		line[index] = ch;
		++index;
	}
	if (ch == '\n')
	{
		line[index] = ch;
		++index;
	}
	line[index] = '\0';
	if (ch != '\n')
		while ((ch = getchar()) != '\n' && ch != EOF)
			++index;
	if (ch == '\n')
		++index;
	return (index);
}

void	str_cpy(char *target, const char *source)
{
	int	index;

	index = 0;
	while ((target[index] = source[index]) != '\0')
		++index;
}

int	a021(int argc, char **argv)
{
	char	line[LINE_COUNT_MAX];
	size_t	line_count;
	char	longest_str[LINE_COUNT_MAX];
	size_t	longest_str_count;

	(void)argc;
	(void)argv;
	longest_str[0] = '\0';
	longest_str_count = 0;
	while (0 < (line_count = get_line(line, LINE_COUNT_MAX)))
	{
		if (line_count > longest_str_count)
		{
			str_cpy(longest_str, line);
			longest_str_count = line_count;
		}
	}
	printf("longest string: [%s] \n", longest_str);
	printf("count of longest string: [%lu] \n", longest_str_count);
	return (0);
}



//	1.9
size_t	str_count(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr != '\0')
		++ptr;
	return (ptr - str);
}

int	a020(int argc, char **argv)
{
	char	**str_array;
	size_t	str_tmp_count;
	char	*str_longest;
	size_t	str_longest_count;

	if (argc != 2)
	{
		printf("You must only enter 1 argument. \n");
		return (0);
	}
	str_array = argv + 1;
	str_longest = NULL;
	str_longest_count = 0;
	while (*str_array != NULL)
	{
		str_tmp_count = str_count(*str_array);
		if (str_longest_count < str_tmp_count)
		{
			str_longest = *str_array;
			str_longest_count = str_tmp_count;
		}
		++str_array;
	}
	printf("longest string: [%s] \n", str_longest);
	printf("count of longest string: [%lu] \n", str_longest_count);
	return (0);
}



//	1.7
int	power(int base, int times)
{
	int	result;

	if (!(times >= 0))
		return (-1);
	result = 1;
	while (0 < times)
	{
		result *= base;
		--times;
	}
	return (result);
}

int	a019(int argc, char **argv)
{
	int	index;

	(void)argc;
	(void)argv;
	index = 0;
	while (index < 10)
	{
		printf("%d: %d %d \n", index, power(2, index), power(-3, index));
		++index;
	}
	return (0);
}



//	1.6
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
	while (index < 10)
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
	while (index < 10)
		printf(" %d", digit_count[index++]);
	printf("\nwhite_space_ch_count: %d, other_count: %d \n", white_space_ch_count, other_count);
	return (0);
}



//	Exercise 1-12
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



//	1.5.4
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



//	1.5.4
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



//	Exrcise 1-10
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



//	Exercise 1-9-4
#define	PREVIOUS_CH_NOT_BLANK	0
#define PREVIOUS_CH_BLANK		1

int	a0132(int argc, char **argv)
{
	char	*str;
	int		state;

	if (!(argc == 2))
		return (0);
	str = argv[1];
	state = PREVIOUS_CH_NOT_BLANK;
	while (*str != '\0')
	{
		if (state == PREVIOUS_CH_NOT_BLANK)
		{
			putchar(*str);
			if (*str == ' ')
				state = PREVIOUS_CH_BLANK;
		}
		else if (state == PREVIOUS_CH_BLANK)
		{
			if (*str != ' ')
			{
				putchar(*str);
				state = PREVIOUS_CH_NOT_BLANK;
			}
		}
		++str;
	}
	return (0);
}



//	Exercise 1-9-3
int	a0131(int argc, char **argv)
{
	char	*str;

	if (!(argc == 2))
		return (0);
	str = argv[1];
	while (*str != '\0')
	{
		putchar(*str);
		if (*str == ' ')
			while (*str == ' ')
				++str;
		else
			++str;
	}
	return (0);
}



//	Exercise 1-9-2
#define FALSE	0
#define TRUE	1

int	a0130(int argc, char **argv)
{
	char	*str;
	int		is_previous_ch_blank;

	if (!(argc == 2))
		return (0);
	str = argv[1];
	is_previous_ch_blank = FALSE;
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			if (!is_previous_ch_blank)
			{
				putchar(*str);
				is_previous_ch_blank = TRUE;
			}
		}
		else
		{
			putchar(*str);
			is_previous_ch_blank = FALSE;
		}
		++str;
	}
	return (0);
}



//	Exercise 1-9
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



//	Exercise 1-8
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



//	1.5.3
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



//	1.5.2
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



//	Exercise 1-7
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



//	1.5.1
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



//	1.4
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



//	Exercise 1-5
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



//	Exercise 1-3
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



//	1.2
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



//	1.2
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



//	1.2
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



//	1.1
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



//	1.1
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
