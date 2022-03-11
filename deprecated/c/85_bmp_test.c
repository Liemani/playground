#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <ctype.h>

#define DATA_FILE	"sample_brick_data"
#define RESULT_FILE	"red_brick.bmp"

unsigned char	aHexToDigit(char c)
{
	if (isdigit(c))
		return (c - '0');
	else if (isalpha(c))
		return (10 + c - 'a');
	else
		return (-1);
}

unsigned char	characterToByte(char *buffer)
{
	return (aHexToDigit(buffer[0]) * 16 + aHexToDigit(buffer[1]));
}

int	main(void)
{
	char			buffer[3];
	unsigned char	byteToWrite;
	ssize_t			bytes_read;

	int input_file = open(DATA_FILE, O_RDONLY | O_CREAT);
	if (input_file == -1)
		return (-1);
	int output_file = open(RESULT_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file == -1)
		return (-1);

	while ((bytes_read = read(input_file, buffer, 3)) > 0)
	{
		byteToWrite = characterToByte(buffer);
		if (write(output_file, &byteToWrite, 1) < 0)
			return (-1);
	}
	return (bytes_read);
}
