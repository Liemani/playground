void display_char(char c);

void display_str(char *str)
{
	while (*str)
		display_char(*str++);
}
