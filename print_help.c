#include "file.h"
char print_exit(vars_t *vars)
{
	char *str = NULL;
	str = file_read("Exit");

	write(1, str, strlen(str));
	free(str);
	return (0);
}
char print_cd(vars_t *vars)
{
	char *str = NULL;
	str = file_read("Cd");
	write(1, str, strlen(str));
	free(str);
	return(0);
}
char print_help(vars_t *vars)
{
	char *str = NULL;
	str = file_read("Help_to_help");
	write(1, str, strlen(str));
	free(str);
	return(0);
}
char help_print_history(vars_t *vars)
{
	char *str = NULL;
	str = file_read("Help_history");
	write(1, str, strlen(str));
	free(str);
	return(0);
}
