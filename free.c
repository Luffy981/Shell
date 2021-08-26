#include "file.h"
/**
 * free_struct - Function free
 * @vars: Structure to free
 */
void free_struct(vars_t *vars)
{
	int i = 1;

	while (vars->arrays[i] != NULL)
	{
		free(vars->arrays[i]);
		i++;
	}
	free(vars->arrays);
}
