#include "file.h"
char (*match (vars_t *m))(vars_t *n)
{
	int i;
	arg_t op[]={
		{"exit", file_exit},
		{"hi", file_number},
		{NULL,NULL}
	};

	for (i = 0 ; op[i].f != NULL ; i++)
	{
		if (strcmp(op[i].n,(char*)m->arrays[0]) == 0)
			break;
	}
	return(op[i].f);
}
char file_exit(vars_t *vars)
{
	exit(98);
}
char file_number(vars_t *vars)
{
	printf("Hola mundo\n");
	return(0);
}
