#include "file.h"
void add_history(vars_t *vars)
{
	int fd;
	char *buffer = NULL;
	char *number = NULL;

	if (vars->buffer == NULL )
		return;
	if(only_chars(vars->buffer, ' ' , '\n'))
		return;
	buffer = file_read("history");
	if(buffer == NULL)
		return;
	number = get_index();
	fd = write_file("history", 4,  buffer, number, ":\t", vars->buffer);
	if(fd == -1)
		return;
}
char *get_index(void)
{
	char *number = NULL;
	int n;
	int ratoi;
	char *buffer = NULL;
	int fd;
	number = file_read("index");
	if(number == NULL)
		number = "0";
	n = strlen(number);
	if(n < 1)
		number = "0";
	/*number[n-1] = '\0'*/;
	ratoi = _atoi(number);
	ratoi++;
	buffer = malloc(sizeof(char) * sizeofnum(ratoi) + 1);
	if(buffer == NULL)
		buffer = "1";
	else
		un_int_to_buffer(ratoi, buffer, 0);
	fd = write_file("index",1,buffer);
	return(buffer);
}

int only_chars(char *str, char character , char until)
{
	if(!str | *str == until)
		return(1);
	if(*str == character)
		return(only_chars(str+1, character , until));
	return(0);
}
char *file_read(char *namefile)
{
	size_t size;
	int fd;
	char *buffer;
	struct stat st;
	if(namefile == NULL)
		return(NULL);
	fd = open(namefile, O_CREAT | O_RDONLY, 0600);
	if (fd == -1)
		return(NULL);
	fstat(fd, &st);
	buffer = malloc(sizeof(char)*st.st_size + 1);
	if(buffer == NULL)
		return(NULL);
	size = read(fd, buffer, st.st_size);
	if((size) == -1)
		return(NULL);
	close(fd);
	buffer[size] = '\0';
	return(buffer);
}
int write_file(char *namef, int n, ...)
{
	int fd;
	va_list buffers;
	int w = 0;
	char *currentbuff;
	va_start(buffers,n);
	fd = open(namef, O_WRONLY);
	if(fd == -1)
		return(-1);
	for(;n>0;n--)
	{
		currentbuff = va_arg(buffers,char*);
		w += write(fd,currentbuff, strlen(currentbuff));
	}
	close(fd);
	va_end(buffers);
	return(w);
}
char print_history(vars_t *vars)
{
	ssize_t fd, r;
	char *buff;
	int a = 1024;

	buff = malloc(sizeof(char) * a);
	if (buff == NULL)
	{
		free(buff);
		return (0);
	}
	fd = open("history", O_RDONLY);
	if (fd == -1)
		return (0);
	r = read(fd, buff, a );
	if (r == -1)
		return (0);
	write(1, buff, r);
	free(buff);
	close(fd);
	return (r);
}
/**
 * _atoi - convert a string to an integer
 * @string_number: string within number
 * Return: integer resove of the @string_number
 */
int _atoi(char *string_number)
{
	int i, resolve, scale;

	if (!string_number)
		return (0);

	i = strlen(string_number) - 1;
	resolve = 0;
	for (scale = 1; i >= 0; i -= 1, scale *= 10)
		if (string_number[i] == '-')
			resolve *= -1;
	        else
			resolve += (string_number[i] & 0x0F) * scale;
	return (resolve);
}
/**
 * unsigned_int_to_buffer - determines whether @string includes a search_string
 * @number: number to transform
 * @buffer: buffer to save
 * @idx: index of a buffer
 * Return: true or false as appropriate
 */
unsigned int un_int_to_buffer(int number, char *buffer, int idx)
{
	unsigned int num = number;
	unsigned int length = 0;

	if (num / 10)
		length = un_int_to_buffer(num / 10, buffer, idx + 1);
	else
		length = idx;

	buffer[length - idx] = (num % 10 + '0');

	if (num / 10)
	{
		buffer[length + 1] = '\0';
		return (length);
	}
	else
		return (idx);
}
int sizeofnum(int number)
{
	if(number/10)
	{
		return(1+sizeofnum(number/10));
	}
	return(0);
}
