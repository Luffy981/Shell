#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (*s1 == *s2 && i < n)
	{
		s1++;
		s2++;
		i++;
	}

	if (--s1 == --s2)
	{
		return (0);
	}
	return (1);
}
char * str_tok(char *buffer, const char *delimiter)
{
	static char *save = NULL;
	char *string = NULL;
	char *set = NULL;

	buffer = buffer ? buffer : save;
	if (buffer)
	{
		set = buffer;
		if (!*set)
		{
			save = '\0';
		} else
		{
			string = set;
			while (*set != *delimiter && *set != *(delimiter + 1) &&
			       *set != '\0')
			{
				set++;
			}
			*set = '\0';
			set++;
			save = set;
		}
	}
	return (string);
}
void *tokens_env(char *str, char *ptr)
{
	char *duplicate;
	char *vodka;
	char *token;

	char *string;
	char *ron;
	char *delimiter = ":=";
	int fd;
	if(str== NULL)
		return(NULL);
	duplicate = malloc((sizeof(char) * strlen(str)) + 1);

	if(duplicate == NULL)
		return(NULL);
	vodka = malloc((sizeof(char) * strlen(str)) + 1);

	if(vodka == NULL)
		return(NULL);
	duplicate = strdup(str);
	vodka = strdup(str);
	if((_strncmp("PATH",duplicate, 4)) == 0);
	{
			while((token = str_tok( vodka, delimiter)) != NULL)
			{
				string = NULL;
				ron = NULL;
				string = strcat(token,"/");
				ron = strcat(string, ptr);
				if((fd = access(ron, F_OK))== 0)
				{
					break;
				}
				vodka = NULL;
			}
		}

}
int main(int argc, char *argv[], char **envp)
{
	int i = 0;
	while( envp[i] != NULL)
	{
		tokens_env(envp[i],argv[1]);
		i++;
	}
	return(0);
}
