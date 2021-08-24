#include "file.h"
/**
 * len_str - Function to obtain string length
 * @str: String
 * Return: Return value
 */
size_t len_str(char *str)
{
	size_t len = 0;

	if (str == NULL)
		return (0);
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
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
	int m = 0;

	a = len_str(s1);
	b = len_str(s2);
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

char *MyStrDup(char *str)
{
	char *result = malloc(sizeof(char) * (len_str(str) + 1));
	if (result == NULL)
	{
		return NULL;
	}

	int i = 0;
	while(str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}

	result[i] = '\0';

	return result;
}
