#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char **envp)
{
	char **token;
	int block = 20;
	int i = 0;
	char *delimiter = ":=";
	char *string;
	char *vodka;
	int fd ;

	token == malloc(sizeof(char *) * block);
	if (token == NULL)
		return(0);
	while((token[i] =strtok( envp[24], delimiter)) != NULL)
	{
		string = NULL;
		vodka = NULL;
		if(i>1)
		{
			string = strcat(token[i],"/");
			vodka = strcat(string, argv[1]);
			if((fd = access(vodka, F_OK))== 0)
			{
				execve(vodka,token,envp);
				break;
			}
		}
		i++;
		if(i >= block)
		{
			token = realloc(token , sizeof(char *) * (i + 1));
			if(token == NULL)
				return(0);
		}
		envp[24] = NULL;
	}
	return(0);
	/*char *path = strcat(getenv("PATH"), "/");
	//printf("PATH: %s \n", path);
	path = strcat(envp, argv[1]);
	//printf("PATH: %s \n`1", path);
	//char *arg[] = {path, argv[2], NULL};
	char *cmd[] = {argv[0], argv[2], NULL};
	//char *env[] = {path};

	char * token = strtok(path, ":");

	while (token != NULL)
	{
		token = strtok(NULL, ":");
		execve(token, cmd, envp[21]);
	}
	return (0);*/
}
