#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define true			1
#define	false			0

#define HAS_PRECISION	00000001
#define SHOULD_FREE		00000002



typedef struct		s_var
{
	va_list			ap;
	char			*positionPrevious;
	char			*positionCurrent;
	int				flags;
	size_t			fieldWidth;
	size_t			precision;
	char			*buf;
	size_t			bufLength;
	int				numberOfCharacterPrinted;	
}					t_var;



int		isDigit(char ch)
{
	return ('0' <= ch && ch <= '9');
}

char	currentCharacter(t_var *var)
{
	return (*var->positionCurrent);
}

int		getFlag(t_var *var, int flag)
{
	return (var & flag != 0);
}

void	setFlag(t_var *var, int flag, int value)
{
	if (value == true)
		*var |= flag;
	else
		*var &= flag;
}

void	freeBuf(t_var *var)
{
	if (getFlag(var, SHOULD_FREE))
		free(var->buf);
}

void	setBuf(t_var *var, char *buf, bufLength, int shouldFree)
{
	freeBuf(var);
	var->buf = buf;
	var->bufLength = bufLength;
	setFlag(var, SHOULD_FREE, shouldFree);
}

char	*ultox(unsigned long)
{
}

char	*ultoa(unsigned long)
{
}

int		atoi(char *string)
{
	char	ch;
	int		number;

	number = 0;
	while (isDigit(ch = *string++) && ch != '\0')
		number = 10 * number + (ch - '0');

	return (number);
}

size_t	readNumber(t_var *var)
{
	size_t	number;
	
	number = atoi(positionCurrent);
	while (isDigit(currentCharacter(var)))
		++var->positionCurrent;

	return (number);
}

void	readOption(t_var *var)
{
	++var->positionCurrent;
	var->fieldWidth = readNumber(var);
	if (currentCharacter(var) == '.')
	{
		setFlag(var, HAS_PRECISION, true);
		++var->positionCurrent;
		var->precision = readNumber(var);
	}
}

int		conversiond(t_var *var)
{
}

int		conversionx(t_var *var)
{
}

int		conversions(t_var *var)
{
	if (var->conversion < var->bufLength)

}

int		process(t_vat *var)
{
	char	ch;

	while ((ch = *var->positionCurrent))
	{
		if (ch == '%')
		{
			write(var->buf, positionPrevious, positionCurrent - positionPrevious);
			readOption(var);
			if (d)
				conversiond(var);
			else if (x)
				conversionx(var);
			else if (s)
				conversions(var);
		}
	}
	write(var->buf, positionPrevious, positionCurrent - positionPrevious);
}

int		ft_printf(char *formatString, ...)
{
	t_var	var;
	int		exitCode;

	va_arg(formatString);

	va_start(var.ap, formatString);
	var.positionPrevious = formatString;
	var.positionCurrent = formatString;
	var.flags = 0;
	var.numberOfCharacterPrinted = 0;

	exitCode = process(&var);
	va_end(var.ap);
	freeBuf(&var);
	if (exitCode)
		return (exitCode);
	return (var.numberOfCharacterPrinted);
}
