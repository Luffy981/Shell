#include "file.h"
char (*match (vars_t *m))(vars_t *n)
{
	int i;
	arg_t op[]={
		{"exit", file_exit},
		{"cd", change_directory},
		{"history", print_history},
		{NULL,NULL}
	};

	for (i = 0 ; op[i].f != NULL ; i++)
	{
		if (strcmp(op[i].n,(char*)m->arrays[0]) == 0)/*compare strings*/
			break;
	}
	return(op[i].f);
}
char file_exit(vars_t *vars)
{
	free_struct(vars);
	exit(98);
}
char **save_history(vars_t *vars)
{
	static char  **save_history = NULL;
	int count = 1;
	save_history = malloc(sizeof(char *) *count);
	if(save_history == NULL)
		return(NULL);

}

char change_directory(vars_t *vars)
{
	char *home;
	char *pun1 = NULL;
	char *pun2 = NULL;

	home = _getenv("HOME");
	pun1 = str_cat(home, "/");
	if(vars->arrays[1])
		pun2 = str_cat(pun1,vars->arrays[1]);
	else
		pun2 = pun1;

	/* change directory */
	if(_setenv("OLDPWD")== 0)
		printf("Error to set old PWD");
	if(chdir(pun2) != 0)
		printf("Error to change directory\n");
	if(_setenv("PWD") == 0)
		printf("Error to set current PWD");
	return (0);
}
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
