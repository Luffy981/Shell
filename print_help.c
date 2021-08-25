#include "file.h"
/**
 * print_exit - Function to print help exit
 * @vars: Parameter
 * Return: Return value
 */
char print_exit(vars_t *vars)
{
	char *str = NULL;

	UNUSED(vars);
	str = file_read("Exit");

	write(1, str, strlen(str));
	free(str);
	return (0);
}
/**
 * print_cd - Function to print help cd
 * @vars: Parameter
 * Return: Return value
 */
char print_cd(vars_t *vars)
{
	char *str = NULL;

	UNUSED(vars);
	str = file_read("Cd");
	write(1, str, strlen(str));
	free(str);
	return (0);
}
/**
 * print_help - Function to print help help
 * @vars: Parameter
 * Return: Return value
 */
char print_help(vars_t *vars)
{
	char *str = NULL;

	UNUSED(vars);
	str = file_read("Help_to_help");
	write(1, str, strlen(str));
	free(str);
	return (0);
}
/**
 * help_print_history - Function to print help history
 * @vars: Parameter
 * Return: Return value
 */
char help_print_history(vars_t *vars)
{
	char *str = NULL;

	UNUSED(vars);
	str = file_read("Help_history");
	write(1, str, strlen(str));
	free(str);
	return (0);
}
