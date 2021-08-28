#include "file.h"
/**
 * match - Function to match
 * @m: Structure
 * Return: Return pointer to function
 */
char (*match(vars_t *m))(vars_t *n)
{
	int i;
	arg_t op[] = {
		{"exit", file_exit},
		/*{"cd", change_directory},*/
		{"history", print_history},
		{"help", help_func},
		{NULL, NULL}
	};

	for (i = 0 ; op[i].f != NULL ; i++)
	{              /*compare strings*/
		if (_strcmp(op[i].n, (char *)m->arrays[0]) == 0)
			break;
	}
	return (op[i].f);
}
/**
 * file_exit - Function to close shell
 * @vars: Structure
 * Return: Return value
 */
char file_exit(vars_t *vars)
{
	free_struct(vars);
	free(vars->buffer);
	exit(98);
	return (0);
}
