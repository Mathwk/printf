#include "main.h"
/**
 * pr_hexaD - print Hexadecimal in uppercase
 * @ap: argument to print
 * Return: count and print
 */
int pr_hexaD(va_list ap)
{
	int i;
	unsigned int j = va_arg(ap, int), n;
	char s[BUFF_SIZE];

	if (j == 0)
		return (write(1, "0", 1));
	n = j;
	for (i = 0; n > 0; i++)
		n /= 16;
	for (n = i - 1; j > 0; n--)
	{
		s[n] = j % 16 + '0';
		if (j % 16 > 9)
		{
			switch (j % 16)
			{
				case 10:
					s[n] = 'A';
					break;
				case 11:
					s[n] = 'B';
					break;
				case 12:
					s[n] = 'C';
					break;
				case 13:
					s[n] = 'D';
					break;
				case 14:
					s[n] = 'E';
					break;
				case 15:
					s[n] = 'F';
					break;
			}
		}
		j /= 16;
	}
	return (write(1, &s[0], i));
}
