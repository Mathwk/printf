#include "main.h"
/**
 * pr_unsigned - print unsigned intiger number
 * @ap: argument to print
 * Return: count and print
 */
int pr_unsigned(va_list ap)
{
	int i;
	unsigned int j = va_arg(ap, int), n;
	char s[BUFF_SIZE];

	if (j == 0)
		return (write(1, "0", 1));
	i = 0;
	n = j;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	n = i - 1;
	while (j > 0)
	{
		s[n] = j % 10 + '0';
		j /= 10;
		n--;
	}
	return (write(1, &s[0], i));
}
/**
 * pr_octal - print octal number
 * @ap: argument to print
 * Return: count and print
 */
int pr_octal(va_list ap)
{
	int i;
	unsigned int j = va_arg(ap, int), n;
	char s[BUFF_SIZE];

	if (j == 0)
		return (write(1, "0", 1));
	i = 0;
	n = j;
	while (n > 0)
	{
		n /= 8;
		i++;
	}
	n = i - 1;
	while (j > 0)
	{
		s[n] = j % 8 + '0';
		j /= 8;
		n--;
	}

	return (write(1, &s[0], i));
}
