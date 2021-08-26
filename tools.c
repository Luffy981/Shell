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
