#include "file.h"
/**
 * handle_sigint - Function to execute after handle CTRL+C
 * @sig: Parameter
 * Return: Return value
 */
void handle_sigint(int sig)
{

	UNUSED(sig);
	PRINT("\n");
	PRINT("$ ");
	fflush(stdout);
}
/**
 * signal_C - Function to handle CTRL+C
 * Return: Return success or fail
 */
int signal_C(void)
{
	if (signal(SIGINT, handle_sigint) == SIG_ERR)
	{
		write(2, "Could not set signal handler\n", 29);
		return (EXIT_FAILURE);
	}
	return (0);
}
/**
 * check_match_return - Function pointer to function
 * @f: Pointer to function
 * @vars: Structure
 * @enviroment: Enviroment
 * Return: Return value
 */
int check_match_return(char (*f)(vars_t *r), vars_t *vars, char **enviroment)
{
	int fd;
	char *err_find = "No such file or directory";

	if (f == NULL)
	{
		fd = access(vars->arrays[0], F_OK);
		if (fd == 0)
		{
			check_path(vars, enviroment);
			if (isatty(STDIN_FILENO))
				PRINT("$ ");
		} else if (check2_path(vars, enviroment) == 0)
		{
			if (isatty(STDIN_FILENO))
				PRINT("$ ");
		} else
		{
			if (isatty(STDIN_FILENO))
			{
				PRINT(vars->arrays[0]), PRINT(": ");
				PRINT(err_find);
			}
			if (isatty(STDIN_FILENO))
				PRINT("\n");
			if (isatty(STDIN_FILENO))
				PRINT("$ ");
		}
	} else
	{
		f(vars);
		if (isatty(STDIN_FILENO))
			PRINT("$");
		return (0);
	}
	return (1);
}
/**
 * main - Function main
 * @argc: Number of arguments
 * @argv: Array of arguments
 * @enviroment: Enviroment
 * Return: Return value
 */
int main(int argc, char *argv[], char **enviroment)
{
	vars_t vars = {NULL};
	size_t buffer_len = 0;
	char *delimiter = " \n";
	char (*f)(vars_t *r);

	UNUSED(argc);
	UNUSED(argv);
	if (isatty(STDIN_FILENO))
	{
		PRINT("$ ");
	}
	signal_C();
	while (getline(&(vars.buffer), &buffer_len, stdin) != -1)
	{
		add_history(&vars);
		vars.arrays = tokenizer(vars.buffer, delimiter);
		if (vars.arrays == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				PRINT("$ ");
			}
			continue;
		} else
		{
			f = match(&vars);
			check_match_return(f, &vars, enviroment);
		}
		free(vars.arrays);
		continue;
	}
	free(vars.buffer);
	if (isatty(STDIN_FILENO))
		PRINT("\n");
	exit(98);
}
