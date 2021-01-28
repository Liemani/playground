# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include "lmt.h"

#define A_LINE_HAS_BEEN_READ 1
#define EOF_HAS_BEEN_REACHED 0
#define AN_ERROR_HAPPEND -1

typedef struct		s_buf_list
{
	char			*buf;
	int				fd;
	ssize_t			read_bytes;
	char			*cur_pos;
	struct s_list	*next;
}					t_buf_list;

static int		should_break(t_buf_list *ele, char **line, size_t *p_length)
{
	const char	*end_pos = ele->buf + (ele->read_bytes - 1);
	char		*cur_pos;
	char		*prev_pos;
	char		*line_tmp;
	size_t		appended_length;

	cur_pos = ele->cur_pos;
	if (end_pos < cur_pos)
		return (0);
	prev_pos = cur_pos;
	while (cur_pos != end_pos && *cur_pos != '\n')
		++cur_pos;
	ele->cur_pos = cur_pos + 1;
	appended_length = cur_pos - prev_pos + (*cur_pos != '\n');
	line_tmp = *line;
	if (!(*line = malloc(sizeof(**line) * (*p_length + appended_length + 1))))
		return (AN_ERROR_HAPPEND);
	memcpy(*line, line_tmp, *p_length);
	free(line_tmp);
	memcpy(*line + *p_length, prev_pos, appended_length);
	*p_length += appended_length;
	return (*cur_pos == '\n');
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("argc must 2 \n");
		return (0);
	}

	t_buf_list	*ele;
	char		*line;
	int			return_value;
	size_t		length;

	if (!(ele = malloc(sizeof(*ele))))
		return (AN_ERROR_HAPPEND);

	ele->buf = argv[1];
	ele->fd = 1;
	ele->read_bytes = strlen(argv[1]);
	ele->cur_pos = argv[1];
	ele->next = NULL;

	line = NULL;
	length = 0;

	return_value = should_break(ele, &line, &length);
	*(line + length) = '\0';

	PRINT(return_value, d);
	PRINT(line, s);

	return (0);
}
