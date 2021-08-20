#include "file.h"
int main (int argc , char *argv[] , char **enviroment)
{
	vars_t vars = {NULL};
	size_t buffer_len = 0;
	char *delimiter = " \n", (*f)(vars_t *r);
	char *Cisfun = "#Cisfun$ ", *err_find = "No such file or directory";
	int fd;

	if(isatty(STDIN_FILENO))
		printf("%s", Cisfun);
	while(getline(&(vars.buffer),&buffer_len,stdin) != -1)
	{
		vars.arrays = tokenizer(vars.buffer,delimiter);
		if(vars.arrays == NULL)
		{
			if(isatty(STDIN_FILENO))
				printf("%s", Cisfun);
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
						printf("%s", Cisfun);
					continue;
				}
				if(check2_path(&vars, enviroment) == 0)
				{
					if(isatty(STDIN_FILENO))
						printf("%s", Cisfun);
					continue;
				}
				printf("%s: %s", vars.arrays[0], err_find);
					if(isatty(STDIN_FILENO))
						putchar(10);
					if(isatty(STDIN_FILENO))
						printf("%s", Cisfun);
					continue;
			}else
			{
				f(&vars);
				if(isatty(STDIN_FILENO))
					printf("%s", Cisfun);
				continue;
			}
		}
	}
	if(isatty(STDIN_FILENO))
		printf("%s", Cisfun);
}
