#include "file.h"
/**
 * file_read - Function to open and read a file
 * @namefile: Name file
 * Return: Return buffer with file text
 */
char *file_read(char *namefile)
{
	size_t size;
	int fd;
	char *buffer;
	struct stat st;

	if (namefile == NULL)
		return (NULL);
	fd = open(namefile, O_CREAT | O_RDONLY, 0600);
	if (fd == -1)
		return (NULL);
	fstat(fd, &st);
	buffer = malloc(sizeof(char) * st.st_size + 1);
	if (buffer == NULL)
		return (NULL);
	size = read(fd, buffer, st.st_size);
	if ((size) == -1)
		return (NULL);
	close(fd);
	buffer[size] = '\0';
	return (buffer);
}
/**
 * write_file - Function to open and write a file
 * @namef: Name file
 * @n: Number of buffers
 * Return: Return returns written characters
 */

int write_file(char *namef, int n, ...)
{
	int fd;
	va_list buffers;
	int w = 0;
	char *currentbuff;

	va_start(buffers, n);
	fd = open(namef, O_WRONLY);
	if (fd == -1)
		return (-1);
	for (; n > 0 ; n--)
	{
		currentbuff = va_arg(buffers, char*);
		w += write(fd, currentbuff, strlen(currentbuff));
	}
	close(fd);
	va_end(buffers);
	return (w);
}
