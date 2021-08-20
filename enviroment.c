#include "file.h"
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
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char *str_cat(char *s1, char *s2)
{
	char *string;
	int a;
	int b;
	int i = 0;
	int m = 0;
	a = _strlen(s1);
	b = _strlen(s2);
	string = malloc(sizeof(char) * (a + b + 1));
	if(string == NULL)
		return(NULL);
	while(s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while(s2[m] != '\0')
	{
		string[i] = s2[m];
		i++;
		m++;
	}
	string[i] = '\0';
	return(string);
}
