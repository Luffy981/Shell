#include "file.h"
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
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
char *str_cat(char *s1, char *s2)
{
	char *string;
	int a;
	int b;
	int i = 0;
	a = _strlen(s1);
	b = _strlen(s2);
	string = malloc(sizeof(char) * (a + b + 1));
	if(string = NULL)
		return(NULL);
	while(s1)
	{
		string[i] = s1;
		s1++;
		i++;
	}
	while(s2)
	{
		string[i] = s2;
		s2++;
		i++;
	}
	string[i] = '\0';
	return(string);
}
