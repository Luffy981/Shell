#include "file.h"
/**
 * check_path - Function to check path
 * @vars: Structure
 * @enviroment: Enviroment
 * Return: Return value
 */
void check_path(vars_t *vars, char **enviroment)
{
	pid_t child;
	int status;

	child = fork(); /*Create a child*/
	switch (child)
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
/**
 * check2_path - Function to check path
 * @vars: Structure
 * @enviroment: Enviroment
 * Return: Return value
 */
int check2_path(vars_t *vars, char **enviroment)
{
	int i, fd, status;
	char **tokens;
	char *pun1 = NULL, *pun2 = NULL, *duplicate = NULL, *delim = ":=";
	pid_t child;

	for (i = 0; i < 30; i++)
		if (_strncmp(enviroment[i], "PATH", 4) == 0)/*Find string PATH*/
			break;
	duplicate = str_dup(enviroment[i]); /* Duplicate PATH string*/
	tokens = tokenizer(duplicate, delim);
	i = 0;
	while (tokens[i] != NULL)
	{
		pun1 = str_cat(tokens[i], "/"); /*Form to pathname*/
		pun2 = str_cat(pun1, vars->arrays[0]);
		fd = access(pun2, F_OK);
		if (fd  == 0) /*Verified pathname*/
		{
			child = fork(); /*Create a child*/
			switch (child)
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
			free(pun1), free(pun2);
			return (0);
		}
		free(pun1), free(pun2), i++;
	}
	free(tokens);
	if (i == 9)
		return (1);
	return(1);
}
/**
 * iter_number - Function to iter number
 * @buffer: buffer
 * Return: Return value
 */
int iter_number(char *buffer)
{
	char delimiter = ';';
	int i = 0;
	int count = 0;

	while (buffer[i])
	{
		if (buffer[i] == delimiter)
		{
			count += 1;
		}
		i++;
	}
	return (count);
}
