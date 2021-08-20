#include "file.h"
void free_struct(vars_t *vars)
{
	int i = 0;
	free(vars->buffer);
}
