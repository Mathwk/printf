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
	int j, n = 0;
	sp_t spec[] = {
		{'c', pr_char}, {'s', pr_string}, {'%', pr_percent},
		{'d', pr_int}, {'i', pr_int}, {'b', pr_binary},
		{'u', pr_unsigned}, {'o', pr_octal}, {'x', pr_hexad},
		{'X', pr_hexaD}, {'\0', NULL}
	};

	for (j = 0; spec[j].sp != '\0'; j++)
	{
		if (format[index] == spec[j].sp)
			return (spec[j].fn(ap));
	}
	if (spec[j].sp == '\0')
	{
		if (format[index] == '\0')
			return (-1);
		n += write(1, "%%", 1);
		if (format[index - 1] == ' ')
			n += (write(1, " ", 1));
		n += write(1, &format[index], 1);
		return (n);
	}
	return (0);
}
