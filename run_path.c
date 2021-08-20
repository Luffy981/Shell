#include "file.h"
void check_path(vars_t *vars, char **enviroment)
{
	pid_t child;
	int status;

	child = fork();
	switch(child)
	{
	case 0:
		execve(vars->arrays[0], vars->arrays, enviroment);
		break;
	case -1:
		printf("Error to create a child");
		break;
	default:
		wait(&status);
		break;
	}
}
int check2_path(vars_t *vars, char **enviroment)
{
	int i;
	char *delim = ":=";
	char **tokens;
	char *pun1 = NULL;
	char *pun2 = NULL;
	char *duplicate = NULL;
	int fd;
	pid_t child;
	int status;
	for(i = 0; i < 30; i++)
		if(_strncmp(enviroment[i], "PATH", 4) == 0)
			break;
	duplicate = malloc((sizeof(char) * strlen(enviroment[i])) + 1);
	if(duplicate == NULL)
		return(0);
	duplicate = strdup(enviroment[i]);
	tokens = tokenizer(duplicate, delim);
	i = 0;
	while(tokens != NULL && i < 9)
	{
		pun1 = str_cat(tokens[i], "/");
		pun2 = str_cat(pun1, vars->arrays[0]);
		if((fd = access(pun2, F_OK)) == 0)
		{
			child = fork();
			switch(child)
			{
			case 0:
				execve(pun2, vars->arrays, enviroment);
				break;
			case -1:
				printf("Error to create a child");
				break;
			default:
				wait(&status);
				break;
			}
			return(0);
		}
		i++;
	}
	if(i == 9)
		return(1);
}
