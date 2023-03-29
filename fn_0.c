#include "main.h"
/**
 * pr_char - print character
 * @ap: argument to print
 * Return: count and print
 */
int pr_char(va_list ap)
{
	char c = va_arg(ap, int);

	return (write(1, &c, 1));
}
/**
 * pr_string - print string
 * @ap:  rgument to print
 * Return: count and print
 */
int pr_string(va_list ap)
{
	int i;
	char *s = va_arg(ap, char *);

	if (s == NULL)
		return (write(1, "(null)", 6));
	for (i = 0; s[i] != '\0';)
		i++;
	return (write(1, &s[0], i));
}
/**
 * pr_percent - print percent
 * @ap: argument to print
 * Return: count and print
 */
int pr_percent(va_list ap)
{
	char p = va_arg(ap, int);

	if (p != 0)
		return (write(1, "%%", 1));
	return (0);
}
