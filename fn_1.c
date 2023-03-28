#include "main.h"
/**
 * pr_int - print intiger or decimal
 * @ap: argument to print
 * Return: count and print
 */
int pr_int(va_list ap)
{
	int i, n;
	int j = va_arg(ap, int);
	char s[BUFF_SIZE];

	i = 0;
	if (j < 0)
	{
		s[0] = '-';
		j = -j;
		i++;
	}
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
 * pr_binary - print binary number
 * @ap: argument to print
 * Return: count and print
 */
int pr_binary(va_list ap)
{
	int i;
	unsigned int j = va_arg(ap, int), n;
	char s[BUFF_SIZE];

	i = 0;
	n = j;
	while (n > 0)
	{
		n /= 2;
		i++;
	}
	n = i - 1;
	while (j > 0)
	{
		s[n] = j % 2 + '0';
		j /= 2;
		n--;
	}
	return (write(1, &s[0], i));
}
