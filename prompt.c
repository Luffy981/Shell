#include "file.h"
/**
 * handle_sigint - Function to execute after handle CTRL+C
 * @sig: Parameter
 * Return: Return value
 */
void handle_sigint(int sig)
{
	char s[100];

	UNUSED(sig);
	printf("\n%s$", getcwd(s, 100));
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
	return(0);
}
/**
 * check_match_return - Function pointer to function
 * @f: Pointer to function
 * @vars: Structure
 * @enviroment: Enviroment
 */
void check_match_return(char (*f)(vars_t *r), vars_t *vars, char **enviroment)
{
	int fd;
	char s[100];
	char *err_find = "No such file or directory";

	if (f == NULL)
	{
		fd = access(vars->arrays[0], F_OK);
		if (fd == 0)
		{
			check_path(vars, enviroment);
			if (isatty(STDIN_FILENO))
				printf("%s$", getcwd(s, 100));
		} else if (check2_path(vars, enviroment) == 0)
		{
			if (isatty(STDIN_FILENO))
				printf("%s$", getcwd(s, 100));
		} else
		{
			printf("%s: %s", vars->arrays[0], err_find);
			if (isatty(STDIN_FILENO))
				putchar(10);
			if (isatty(STDIN_FILENO))
				printf("%s$", getcwd(s, 100));
		}
	} else
	{
		f(vars);
		if (isatty(STDIN_FILENO))
			printf("%s$", getcwd(s, 100));
	}
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
	char s[100];
	char (*f)(vars_t *r);

	UNUSED(argc);
	UNUSED(argv);
	if (isatty(STDIN_FILENO))
		printf("%s$", getcwd(s, 100));
	signal_C();
	while (getline(&(vars.buffer), &buffer_len, stdin) != -1)
	{
		/*add_history(&vars);*/
		vars.arrays = tokenizer(vars.buffer, delimiter);
		if (vars.arrays == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("%s$", getcwd(s, 100));
		} else
		{
			f = match(&vars);
			check_match_return(f, &vars, enviroment);
		}
		free_struct(&vars);
		continue;
	}
	if (isatty(STDIN_FILENO))
		putchar('\n');
	exit(98);
}
