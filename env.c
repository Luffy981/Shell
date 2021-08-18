#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
char **tokenizer(char *buffer, char *delimiter)
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
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (s1[i] == s2[i] && i < n)
	{
		if(i + 1 == n)
		{
			break;
		}

		i++;
	}

	if (s1[i] == s2[i])
	{
		return (0);
	}
	return (1);
}

/* my own strtok */
char * _strtok(char * buffer, const char * delimiter)
{
	/* save the reference out of function */
	static char *ref = NULL;
	char *str = NULL;
	char *set = NULL;

	buffer = buffer ? buffer : ref;

	if(*buffer != '\0')
	{
		set = buffer;

		if(!*set)
		{
			ref = '\0';
		}
		else
		{
			str = set;

			while (*set != *delimiter && *set != *(delimiter + 1) &&
			       *set != '\0')
			{
				set++;
			}

			if(*set != '\0')
			{
				*set = '\0';
				set++;
			}
			ref = set;
		}
	}
	return (str);
}


int main( int argc, char *argv[], char *envp[] )
{
	char *buf = NULL;
	int i;
	char *delim = ":=";
	char **tokens;

	/* acoplar cadenas */
	char *pun1 = NULL;
	char *pun2 = NULL;

	char *duplicate = NULL;

	/* fiel descriptor */
	int fd;
	char *save = argv[1];

	for(i = 0; i < 30; i++)
	{
		if(_strncmp(envp[i], "PATH", 4) == 0)
		{
			break;
		}
	}

	duplicate = malloc((sizeof(char) * strlen(envp[i])) + 1);
	if(duplicate == NULL)
	{
		return (0);
	}

	duplicate = strdup(envp[i]);

	tokens = tokenizer(duplicate, delim);
	i = 0;
	while(tokens != NULL)
	{
		pun1 = strcat(tokens[i], "/");
		pun2 = strcat(pun1, argv[1]);

		if((fd = access(pun2, F_OK)) == 0)
		{
			execve(pun2,tokens,envp);
		}
		i++;
	}
	return (0);
}
