#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char * str_tok(char * s, const char * toks)
{
	static char * last = '\0';
	char * ret = '\0';
	char * p;
	if (toks)
	{
		s = s ? s : last;
		if (s)
		{
			p = s;
			if (!*p)
			{
				last = '\0';
			} else
			{
				ret = p;
				while (*p != *toks)
				{
					p++;
				}
				*p = '\0';
				p++;
				last =p;
			}
		}
	}
	return ret;
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
void main (void)
{
	char buffer[] = "Hola mundo azucar limon y sal";
	char *delimiter = " ";
	char **array;
	array = tokenizer(buffer,delimiter);
	while(*array != NULL)
	{
		printf("%s\n",*array);
		array++;
	}
}
