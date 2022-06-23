#ifndef PROGRAMMING_EXERCISE_9_1_HPP
#define PROGRAMMING_EXERCISE_9_1_HPP

const int	Len = 40;
struct golf
{
	char	fullname[Len];
	int		handicap;
};

void	setgolf(golf& g, const char* name, int hc);
int		setgolf(golf& g);
void	handicap(golf& g, int hc);
void	showgolf(const golf& g);

#endif
