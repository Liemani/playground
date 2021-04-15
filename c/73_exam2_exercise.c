#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define true			1
#define	false			0

#define HAS_FIELDWIDTH	00000001
#define HAS_PRECISION	00000002
#define SHOULD_FREE		00000004



typedef struct		s_var
{
	va_list			*ap;
	char			*formatString;
	char			*positionPrevious;
	char			*positionCurrent;
	int				flag;
	char			*buf;
	unsigned long	bufLen;
	int				numberOfCharacterPrinted;	
}					t_var;



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

void	setBuf(t_var *var, char *buf, bufLen, int shouldFree)
{
	freeBuf(var);
	var->buf = buf;
	var->bufLen = bufLen;
	setFlag(var, SHOULD_FREE, shouldFree);
}

char	*ultox(unsigned long)
{

}

ultoa()
{
}

atoi()
{
}

readOption
{
}

setBuf()
{
}

applyOption()
{
}

int		process(char *formatString)
{

}

int		ft_printf(char *formatString, ...)
{
	t_var	var;
	int		exitCode;

	va_arg(formatString);
	va_start(var.ap, formatString);
	exitCode = process(&var);
	va_end(var->ap);
	freeBuf(&var);
	if (exitCode)
		return (exitCode);
	return (var.numberOfCharacterPrinted);
}
