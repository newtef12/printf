#include "main.h"

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);
	return (handle_write_char(c, buffer, flags, width, precision, size));
}

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0;
	char *str = va_arg(types, char *);

	if (str == NULL)
		str = "(null)";

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, str, length);
			print_padding(' ', width - length);
			return width;
		}
		else
		{
			print_padding(' ', width - length);
			write(1, str, length);
			return width;
		}
	}

	return write(1, str, length);
}

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	print_padding(' ', width - 1);
	write(1, "%", 1);
	return width;
}

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)(-n);
		is_negative = 1;
	}

	fill_buffer_with_digits(num, buffer, &i);

	return write_number(is_negative, i, buffer, flags, width, precision, size);
}

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n = va_arg(types, unsigned int);
	int a[32], count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	fill_binary_array(n, a);
	
	while (count < 32 && a[count] == 0)
		count++;
	
	if (count == 32)
		count--;

	for (int i = count; i < 32; i++)
		write(1, &(a[i]), 1);
	
	return (32 - count);
}
