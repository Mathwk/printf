#include "main.h"
/**
 * _printf - function like printf
 * @format: received strint to be printed
 * Return: printed character count
 */
int _printf(const char *format, ...)
{
	int index, pr_counter = 0, p_index = 0;
	char str[BUFF_SIZE];
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	for (index = 0; format && format[index]; index++)
	{
		if (format[index] != '%')
		{
			str[p_index] = format[index];
			p_index++;
			if (p_index == BUFF_SIZE)
			{
				print_str(str, p_index);
				p_index = 0;
			}
			pr_counter++;
		}
		else
		{
			print_str(str, p_index);
			++index;
			if (format[index] == '%')
			{
				p_index = write(1, "%%", 1);
				p_index = 0;
				continue;
			}
			p_index = conv_spec(format, index, ap);
			if (p_index == -1)
				return (-1);
			pr_counter += p_index;
			p_index = 0;
		}
	}
	print_str(str, p_index);
	va_end(ap);
	return (pr_counter);
}
/**
 * print_str - writes the string str to stdout
 * @str: string to print
 * @p_index: number of characters
 * Return: Nothing
 */
int print_str(char *str, int p_index)
{
	if (p_index > 0)
		return (write(1, &str[0], p_index));
	return (0);
}
