#include <stdio.h>
#include "main.h"
#include <stdarg.h>
/**
 * _strlen - Calculate the length of a string (non-const version)
 * @s: The input string
 * Return: The length of the string
 */
int _strlen(char *s)
{
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

/**
 * _strlenc - Calculate the length of a string (const version)
 * @s: The input string
 * Return: The length of the string
 */
int _strlenc(const char *s)
{
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
   return length;
}
