#include <stdlib.h>
#include <stdarg.h>
#include <sys/type.h>

#define true			1
#define false			0

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

void	setBuf(t_vars *vars, char *buffer, size_t length, int shouldFree)
{
	freeBuf(vars);
	vars->buffer = buffer;
	vars->bufferLength = bufferLength;
	setFlag(vars, SHOULD_FREE, shouldFree);
}

int		isDigit(char ch)
{
	return ('0' <= ch && ch <= '9');
}

int		readNumber(t_vars *vars)
{
	char	ch;
	int		number;

	number = 0;
	while (isDigit(ch = *vars->positionCurrent))
	{
		number = number * 10 + (ch - '0');
		++vars->positionCurrent;
	}

	return (number);
}

void	readOption(t_vars *vars)
{
	vars->filedWidth = readNumber(vars);
	setFlag(vars, HAS_PRECISION, false);
	if (*vars->positionCurrent == '.')
	{
		setFlag(vars, HAS_PRECISION, true);
		++vars->positionCurrent;
		vars->precision = readNumber(vars);
	}
}

char	*ultoa(int base)
{

}

int		convertd(t_vars *vars)
{
	int				i;
	unsigned int	ui;

	i = va_arg(vars->ap, int);
	if (i < 0)
	{
		ui = -i;
		setFlag(vars, IS_NEGATIVE, true);
	}
	else
	{
		ui = i;
		setFlag(vars, IS_NEGATIVE, false);
	}
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
