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

int sizeofnum(int number)
{
	if(number/10)
	{
		return(1+sizeofnum(number/10));
	}
	return(0);
}
