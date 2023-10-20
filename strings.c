#include "shell.h"

/**
 * _strlen - Custom implementation of strlen to
 * calculate the length of a string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strdup - Custom implementation of strdup to duplicate a string.
 * @str: The string to be duplicated.
 *
 * Return: A pointer to the duplicated string or NULL if allocation fails.
 */
char *_strdup(const char *str)
{
	size_t length = _strlen(str);
	char *dup_str = (char *)malloc(length + 1);

	if (dup_str)
	{
		size_t i = 0;

		for (; i <= length; i++)
		{
			dup_str[i] = str[i];
		}
	}
	return (dup_str);
}

/**
 * _strcmp - Custom implementation of strncmp to compare two strings
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: An integer less than, equal to, or greater
 * than zero if the first n bytes of s1
 * is found, respectively, to be less than, to match,
 * or be greater than the first n bytes of s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strcat - Custom implementation of strcat to concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to append to dest.
 *
 * Return: A pointer to the resulting string dest or NULL if allocation fails.
 */
char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t src_len = _strlen(src);
	char *result = (char *)malloc(dest_len + src_len + 1);

	if (result)
	{
		size_t i;
		size_t j;

		for (i = 0; i < dest_len; i++)
		{
			result[i] = dest[i];
		}
		for (j = 0; j < src_len; j++)
		{
			result[i + j] = src[j];
		}
		result[i + src_len] = '\0';
	}
	return (result);
}

/**
 * _strcpy - Custom implementation of strcpy to copy a string to a destination
 * @dest: The destination string
 * @src: The source string to be copied to dest
 *
 * Return: A pointer to the destination string or NULL if allocation fails
 */
char *_strcpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (original_dest);
}
