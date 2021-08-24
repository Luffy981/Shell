#include "file.h"
char * str_tok(char *buffer, const char *delimiter)
{
	static char *save = NULL;
	char *string = NULL;
	char *set = NULL;

	buffer = buffer ? buffer : save;
	if (*buffer != '\0')
	{
		while(*buffer == ' ')
			buffer++;
		set = buffer;
		if (!*set)
		{
			save = '\0';
		} else
		{
			string = set;
			while (*set != *delimiter && *set != *(delimiter + 1) && *set != '\0')
			{
				set++;
			}
			if(set != NULL)
			{
				*set = '\0';
				set++;
			}
			save = set;
		}
	}
	return (string);
}
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
	while(*buffer == ' ')
		buffer++;
	while ((tokens[i] = str_tok(buffer,delimiter)) != NULL)
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
