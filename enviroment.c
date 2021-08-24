#include "file.h"
extern char **environ;

char *_getenv(char *path_name)
{
	char **environ_cursor, *env_ptr, *name_ptr;

	environ_cursor = environ;
	while (*environ_cursor)
	{
		env_ptr = *environ_cursor;
		name_ptr = path_name;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);
		environ_cursor++;
	}
	return (NULL);
}

int _setenv(char *path_name)
{
	char buffer[100];
	char *vodka;
	char *pwd;
	char *duplicate;
	int i;
	int a = 0;
	for(i = 0; i < 30; i++)
		if(_strncmp(environ[i], path_name, strlen(path_name)) == 0)
			break;
	duplicate = strdup(environ[i]);
	while(duplicate[a] != '=')
	{
		a++;
	}
	pwd = getcwd(buffer,100);
	vodka = malloc(sizeof(char) * (a + strlen(pwd) + 1));
	if(vodka == NULL)
		return(0);
	a = 0;
	while(duplicate[a] != '/')
	{
		vodka[a] = duplicate [a];
		a++;
	}
	while(*pwd !='\0')
	{
		vodka[a] = *pwd;
		a++;
		pwd++;
	}
	vodka[a] = '\0';
	environ[i] = vodka;
	free(vodka);
	free(duplicate);
	return(1);
}
