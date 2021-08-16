#include "file.h"
char **tokenizer(char *buffer , char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0;
	unsigned int mcount = 1;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
		return (NULL);
	if((*buffer == '\n' || *buffer == ' ') && *(buffer + 1) == '\0')
	{
		return(NULL);
	}
	while ((tokens[i] = strtok(buffer,delimiter)) != NULL)
	{
		i++;
		if (i >= mcount)
		{
			tokens = realloc(tokens , sizeof(char *) * (i+1));
			if (tokens == NULL)
				return(NULL);
		}
		buffer = NULL;
	}
	return (tokens);
}
