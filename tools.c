#include "file.h"
/**
 * _atoi - convert a string to an integer
 * @string_number: string within number
 * Return: integer resove of the @string_number
 */
int _atoi(char *string_number)
{
	int i, resolve, scale;

	if (!string_number)
		return (0);

	i = len_str(string_number) - 1;
	resolve = 0;
	for (scale = 1; i >= 0; i -= 1, scale *= 10)
		if (string_number[i] == '-')
			resolve *= -1;
		else
			resolve += (string_number[i] & 0x0F) * scale;
	return (resolve);
}
/**
 * un_int_to_buffer - determines whether @string includes a search_string
 * @number: number to transform
 * @buffer: buffer to save
 * @idx: index of a buffer
 * Return: true or false as appropriate
 */
unsigned int un_int_to_buffer(int number, char *buffer, int idx)
{
	unsigned int num = number;
	unsigned int length = 0;

	if (num / 10)
		length = un_int_to_buffer(num / 10, buffer, idx + 1);
	else
		length = idx;

	buffer[length - idx] = (num % 10 + '0');

	if (num / 10)
	{
		buffer[length + 1] = '\0';
		return (length);
	}
	else
		return (idx);
}
/**
 *_strcmp - Function to compare two strings
 * @s1: Parameter
 * @s2: Parameter
 * Return: Return value
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int j;
	int r;

	i = 0;
	j = 0;
	r = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[j] != '\0')
	{
		j++;
	}
	if (i > j)
	{
		while (s1[r] == s2[r])
		{
			r++;
		}
	} else if (i < j)
	{
		while (s1[r] == s2[r])
		{
			r++;
		}
	} else
	{
		while (s1[r] == s2[r] && s1[r] == '\0')
		{
			r++;
		}
	}
	return (s1[r] - s2[r]);
}
