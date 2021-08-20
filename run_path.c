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
		break;
	case -1:     /*Error to create a child*/
		printf("Error to create a child");
		break;
	default:     /*Father working*/
		wait(&status); /*Wait for the child to finish*/
		break;
	}
	free(vars);
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
	duplicate = malloc((sizeof(char) * strlen(enviroment[i])) + 1);
	if(duplicate == NULL)
		return(0);
	duplicate = strdup(enviroment[i]); /* Duplicate PATH string*/
	tokens = tokenizer(duplicate, delim);
	i = 0;
	while(tokens != NULL && i < 9)
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
			return(0);
		}
		free(pun1);
		free(pun2);
		i++;
	}
	if(i == 9)
		return(1);
}
