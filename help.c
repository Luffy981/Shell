#include "file.h"
/**
 * help_func - Function to command help
 * @vars: Argument type structure
 * Return: Return success
 */
char help_func(vars_t *vars)
{
	char *str = NULL;
	char (*f)(vars_t *h);

	if (vars->arrays[1])
	{
		f = help_match(vars);
		f(vars);
	}
	else
	{
		str = file_read("Help");

		write(1, str, strlen(str));
		free(str);
	}
	return (0);
}
/**
 * help_match - Function to help matcher
 * @vars: Argument type structure
 * Return: Return pointer to function
 */
char (*help_match(vars_t *vars))(vars_t *vars)
{
	unsigned int i;
	help_v h[] = {
		{"exit", print_exit},
		{"cd", print_cd},
		{"help", print_help},
		{"history", help_print_history},
		{NULL, NULL}
	};
	for (i = 0 ; h[i].p != NULL ; i++)
	{
		if (strcmp(vars->arrays[1], h[i].name) == 0)
		{
			break;
		}
	}
	return (h[i].p);
}
