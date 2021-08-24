#include "file.h"
void check_path(vars_t *vars, char **enviroment)
{
	pid_t child;
	int status;

	child = fork(); /*Create a child*/
	switch(child)
	{
	case 0:      /*Child created*/ /*execute pathname*/
		execve(vars->arrays[0], vars->arrays, enviroment);
		free_struct(vars);/*free memory of child*/
		exit(errno);/*kill the fu*** child*/
		break;
	case -1:     /*Error to create a child*/
		printf("Error to create a child");
		break;
	default:     /*Father working*/
		wait(&status); /*Wait for the child to finish*/
		break;
	}
	free_struct(vars); /*free memory of parent*/
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
		if(_strncmp(enviroment[i], "PATH", 4) == 0)/*Find string PATH*/
			break;
	duplicate = strdup(enviroment[i]); /* Duplicate PATH string*/
	tokens = tokenizer(duplicate, delim);
	i = 0;
	while(tokens[i] != NULL)
	{
		pun1 = str_cat(tokens[i], "/"); /*Form to pathname*/
		pun2 = str_cat(pun1, vars->arrays[0]);
		if((fd = access(pun2, F_OK)) == 0) /*Verified pathname*/
		{
			child = fork(); /*Create a child*/
			switch(child)
			{
			case 0: /*Child created*/ /*Execute pathname*/
				execve(pun2, vars->arrays, enviroment);
				exit(errno); /*kill the fu*** child*/
				break;
			case -1: /*Error to create a child*/
				printf("Error to create a child");
				break;
			default: /*Father working*/
				wait(&status); /*Wait for the child to finish*/
				break;
			}
			free(pun1);
			free(pun2);
			free(duplicate);
			free(tokens);
			return(0);
		}
		free(pun1);
		free(pun2);
		i++;
	}
	free(duplicate);
	if(i == 9)
		return(1);
}
int iter_number(char *buffer)
{
	char delimiter = ';';
	int i = 0;
	int count = 0;
	while(buffer[i])
	{
		if(buffer[i] == delimiter)
		{
			count += 1;
		}
		i++;
	}
	return(count);
}
