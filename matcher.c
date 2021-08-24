#include "file.h"
char (*match (vars_t *m))(vars_t *n)
{
	int i;
	arg_t op[]={
		{"exit", file_exit},
		{"cd", change_directory},
		{"history", print_history},
		{"help", help_func},
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
