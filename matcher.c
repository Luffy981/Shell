#include "file.h"
void  (*match (vars_t *vars))(vars_t *vars)
{
	int i;
	arg_t op[]={
		{"exit" , file_exit},
		{"hi" , file_number},
		{NULL,NULL}
	};

	for (i = 0 ; op[i].f != NULL ; i++)
	{
		if (strcmp(op[i].n, vars->arrays[0]) == 0)
			break;
	}
	if(op[i].f != NULL)
		op[i].f(vars);
}
void file_exit(vars_t *vars)
{
	exit(98);
}
void file_number(vars_t *vars)
{
	printf("$ ");
	printf("Hola mundo\n");
}
