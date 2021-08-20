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
