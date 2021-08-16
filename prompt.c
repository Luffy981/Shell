#include "file.h"
int main (int argc , char **argv[] , char **enviroment)
{
	vars_t vars = {NULL,NULL};
	size_t buffer_len = 0;
	char *delimiter = " \n";

	printf("$ ");
	while(getline(&(vars.buffer),&buffer_len,stdin) != -1)
	{
		vars.arrays = tokenizer(vars.buffer,delimiter);
		if(vars.arrays == NULL)
		{
			printf("$ ");
			continue;
		}else
		{
			match(&vars);
			printf("$ ");
		}
	}
}
