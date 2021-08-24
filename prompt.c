#include "file.h"
#include<signal.h>

char *Cisfun = "#Cisfun$ ";

void handle_sigint(int sig)
{
	printf("\n%s", Cisfun);
	fflush(stdout);
}

int main (int argc , char *argv[] , char **enviroment)
{
	vars_t vars = {NULL};
	size_t buffer_len = 0;
	char *delimiter = " \n", (*f)(vars_t *r);
	char *err_find = "No such file or directory";
	int fd;
	int i;
	char s[100];
	int count = 0;
	/*char *line;
	while((line = fgets(vars.buffer, buffer_len, stdin)) == NULL)
	{
		printf("\04");
		continue;
		}*/
	if(isatty(STDIN_FILENO))
		printf("%s$", getcwd(s, 100));
	if (signal(SIGINT, handle_sigint) == SIG_ERR)
	{
		write(2, "Could not set signal handler\n",29);
		return EXIT_FAILURE;
	}
	while(getline(&(vars.buffer),&buffer_len,stdin) != -1)
	{
		add_history(&vars);
		vars.arrays = tokenizer(vars.buffer,delimiter);
		if(vars.arrays == NULL)
		{
			if(isatty(STDIN_FILENO))
				printf("%s$", getcwd(s, 100));
			continue;
		}else
		{
			f = match(&vars);
			if(f == NULL)
			{
				if((fd = access(vars.arrays[0], F_OK)) == 0)
				{
					check_path(&vars,enviroment);
					if(isatty(STDIN_FILENO))
						printf("%s$", getcwd(s, 100));
					continue;
				}
				if(check2_path(&vars, enviroment) == 0)
				{
					if(isatty(STDIN_FILENO))
   						printf("%s$", getcwd(s, 100));
					continue;
				}
				printf("%s: %s", vars.arrays[0], err_find);
					if(isatty(STDIN_FILENO))
						putchar(10);
					if(isatty(STDIN_FILENO))
						printf("%s$", getcwd(s, 100));
					continue;
			}else
			{
				f(&vars);
				if(isatty(STDIN_FILENO))
					printf("%s$", getcwd(s, 100));
				continue;
			}
		}
	}
	if(isatty(STDIN_FILENO))
		putchar('\n');
}
