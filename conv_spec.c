#include "main.h"
/**
 * conv_spec - checks for conversion specifires
 * @format: input string
 * @index: position to start checking
 * @ap: argument passed
 * Return: count and print
 */
int conv_spec(const char *format, int index, va_list ap)
{
	int i, j;
	sp_t spec[] = {
		{'c', pr_char}, {'s', pr_string}, {'%', pr_percent},
		{'d', pr_int}, {'i', pr_int}, {'b', pr_binary},
		{'u', pr_unsigned}, {'o', pr_octal}, {'x', pr_hexad},
		{'X', pr_hexaD}, {NULL, NULL}
	};

	for (i = index + 1; format[i] != '\0'; i++)
	{
		for (j = 0; spec[j].sp != '\0'; j++)
		{
			if (format[i] == spec[j].sp)
				return (spec[j].fn(ap));
		}
	}
	return (0);
}
