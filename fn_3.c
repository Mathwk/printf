#include "main.h"
/**
 * pr_hexad - print octal number
 * @ap: char to print
 * Return: count and print
 */
int pr_hexad(va_list ap)
{
	int i;
	unsigned int j = va_arg(ap, int), n;
	char s[BUFF_SIZE];

	if (j == 0)
		return (write(1, "0", 1));
	n = j;
	for (i = 0; n > 0; i++)
		n /= 16;
	n = i - 1;
	while (j > 0)
	{
		s[n] = j % 16 + '0';
		if (j % 16 > 9)
		{
			switch (j % 16)
			{
				case 10:
					s[n] = 'a';
					break;
				case 11:
					s[n] = 'b';
					break;
				case 12:
					s[n] = 'c';
					break;
				case 13:
					s[n] = 'd';
					break;
				case 14:
					s[n] = 'e';
					break;
				case 15:
					s[n] = 'f';
					break;
			}
		}
		j /= 16;
		n--;
	}
	return (write(1, &s[0], i));
}
