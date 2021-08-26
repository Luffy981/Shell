#include "file.h"
/**
 * str_tok - Function to cut string
 * @buffer: Buffer
 * @d: Delimiter
 * Return: Return string
 */
char *str_tok(char *buffer,  char *d)
{
	static char *save;
	char *string = NULL;
	char *set = NULL;

	buffer = buffer ? buffer : save;
	if (*buffer != '\0')
	{
		while (*buffer == ' ')
			buffer++;
		set = buffer;
		if (!*set)
		{
			save = '\0';
		} else
		{
			string = set;
			while (*set != *d && *set != *(d + 1) && *set != '\0')
			{
				set++;
			}
			if (*set != '\0')
			{
				*set = '\0';
				set++;
			}
			save = set;
			return (string);
		}
	}
	save = NULL;
	buffer = NULL;
	return (NULL);
}
/**
 * tokenizer - Function to tokens
 * @buffer: Buffer
 * @delimiter: Delimiter
 * Return: Return array of strings
 */
char **tokenizer(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0;
	char **ptr = NULL;
	unsigned int mcount = 1;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
		return (NULL);
	if ((*buffer == '\n' || *buffer == ' ') && *(buffer + 1) == '\0')
	{
		return (NULL);
	}
	while (*buffer == ' ')
		buffer++;
	while ((tokens[i] = str_tok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i >= mcount)
		{
			ptr = _realloc(tokens, 8 * i, 8 * (i + 1));
			tokens = ptr;
			if (tokens == NULL)
				return (NULL);
		}
		buffer = NULL;
	}
	return (tokens);
}
/**
 * _realloc - reallocates memory block
 * @ptr: pointer to the previous memory
 * @old_size: the old size
 * @new_size: the new size
 *
 * Return: a pointer to the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}
/**
 * _memcpy - cpies memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Amount of memory byte
 *
 * Return: A pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
