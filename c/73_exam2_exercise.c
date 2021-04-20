#include <stdlib.h>
#include <stdarg.h>
#include <sys/type.h>

#define true			1
#define false			0

#define BASE_TABLE		"0123456789abcdef"

#define GOOD			0
#define MALLOC_ERROR	-1
#define WRITE_ERROR		-2

#define IS_NEGATIVE		(0x1 << 0)
#define SHOULD_FREE		(0x1 << 1)
#define HAS_PRECISION	(0x1 << 2)

typedef struct	s_vars
{
	va_list		ap;
	char		*positionPrevious;
	char		*positionCurrent;
	size_t		fieldWidth;
	size_t		precision;
	int			flags;
	char		*buffer;
	size_t		bufferLength;
	int			numberOfChPrinted;
}				t_vars;

int		ft_isDigit(char ch)
{
	return ('0' <= ch && ch <= '9');
}

void	ft_memset(char *destination, char ch, size_t size)
{
	while (size--)
		*destination = ch;
}

void	ft_memcpy(char *destination, char *source, size_t size)
{
	while (size--)
		destination[size] = source[size];
}

size_t	ft_strlen(char *string)
{
	char	*pointer;

	pointer = string;
	whild (*pointer != '\0')
		++pointer;
	return (pointer - string);
}

void	setFlags(t_vars *vars, int flag, int value)
{
	if (vlaue == true)
		vars |= flag;
	else
		vars &= ~flag;
}

int		getFlags(t_vars *vars, int flag)
{
	return ((vars->flgs | flag) != 0);
}

void	freeBuf(t_vars *vars)
{
	if (getFlags(vars, SHOULD_FREE))
		free(vars->buffer);
}

void	setBuffer(t_vars *vars, char *buffer, size_t length, int shouldFree)
{
	freeBuf(vars);
	vars->buffer = buffer;
	vars->bufferLength = bufferLength;
	setFlag(vars, SHOULD_FREE, shouldFree);
}

int		readNumber(t_vars *vars)
{
	char	ch;
	int		number;

	number = 0;
	while (ft_isDigit(ch = *vars->positionCurrent))
	{
		number = number * 10 + (ch - '0');
		++vars->positionCurrent;
	}

	return (number);
}

void	readOption(t_vars *vars)
{
	vars->filedWidth = readNumber(vars);
	setFlag(vars, IS_NEGATIVE, false);
	setFlag(vars, HAS_PRECISION, false);
	if (*vars->positionCurrent == '.')
	{
		setFlag(vars, HAS_PRECISION, true);
		++vars->positionCurrent;
		vars->precision = readNumber(vars);
	}
}

char	*ultoa(unsigned long number, int base)
{
	char	array[20];
	char	*arrayPointer;
	char	*buffer;
	char	*bufferPointer;

	arrayPointer = array;
	if (!(base == 10 || base == 16))
		return (NULL);
	*arrayPointer = BASE_TABLE[number % base];
	number /= base;
	while (number != 0)
	{
		array[0] = BASE_TABLE[number % base];
		number /= base;
	}
	buffer = malloc(arrayPointer - array + 1);
	if (buffer == NULL)
		return (NULL);
	bufferPointer = buffer;
	while (array != arrayPointer)
		*bufferPointer++ = *(--arrayPointer);
	return (buffer);
}

int		applyOptiondx(t_vars *vars)
{
	char	*buffer;

	if (getFlag(vars, HAS_PRECISION))
	{
		if (*vars->buffer == '0')
		{
			*vars->buffer = '\0';
			vars->bufferLength = 0;
		}
		if (vars->bufferLength < vars->precision)
		{
			buffer = malloc(vars->precision + 1);
			if (buffer == NULL)
				return (MALLOC_ERROR);
			ft_memset(buffer, '0', vars->precisioin - vars->bufferLength);
			ft_memcpy(buffer + (vars->precision - vars->bufferLength), vars->buffer, vars->bufferLength);
			buffer + vars->precisioin = '\0';
			setBuffer(vars, buffer, vars->precision + 1, true);
		}
	}
}

int		convertd(t_vars *vars)
{
	int				i;
	unsigned int	ui;
	char			*buffer;

	i = va_arg(vars->ap, int);
	if (i < 0)
	{
		ui = -i;
		setFlag(vars, IS_NEGATIVE, true);
	}
	else
		ui = i;
	buffer = ultoa(10);
	if (buffer == NULL)
		return (MALLOC_ERROR);
	setBuffer(vars, buffer, ft_strlen(buffer), true);
	return (applyOptiondx(var));
}

int		convertx(t_vars *vars)
{
}

int		converts(t_vars *vars)
{
}

int		process(t_vars &vars)
{
	int		lengthToPrint;
	char	ch;
	int		exitCode;
	ssize_t	bytesWritten;

	lengthToPrint = 0;
	exitCode = 0;
	while (*vars->positionCurrent != '\0')
	{
		if (*vars->positionCurrent == '%')
		{
			lengthToPrint = vars->positionCurrent - vars->positionPrevious;
			write(1, vars->positionPrevious, lengthToPrint);
			vars->numberOfChPrinted = lengthToPrint;
			++vars->positionCurrent;
			ch = *vars->positionCurrent;
			readOption(vars);
			if (ch == 'd')
				exitCode = convertd(vars);
			else if (ch == 'x')
				exitCode = convertx(vars);
			else if (ch == 's')
				exitCode = converts(vars);
			else
				continue;
			if (write(1, vars->buffer, vars->bufferLength) == -1)
				return (WRITE_ERROR);
			vars->numberOfChPrinted += vars->bufferLength;
		}
		else
			++vars->positionCurrent;
	}
	lengthToPrint = vars->positionCurrent - vars->positionPrevious;
	if (write(1, vars->positionPrevious, lengthToPrint) == -1)
		return (WRITE_ERROR);
	vars->numberOfChPrinted += lengthToPrint;
	return (GOOD);
}

int ft_printf(char *format, ...)
{
	t_vars	vars;
	int		exitCode;

	vars.positionPrevious = format;
	vars.positionCurrent = format;
	setFlags(&vars, SHOULD_FREE, false);
	vars.numberOfChPrinted = 0;

	va_start(format, vars.ap);
	exitCode = process(&vars);
	va_end(ap);
	if (exitCode)
		return (exitCode);

	return (vars.numberOfChPrinted);
}
