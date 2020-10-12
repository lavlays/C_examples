#include <unistd.h>

void	rush(int width, int heigth);
void	print_string(char start_s, char end_s, char middle, int length);
void	print_midlle_chars(char middle, int *length);
void	ft_putchar(char c);

void	rush(int width, int heigth)
{
	int		num_pos;
	char	start_s;
	char	end_s;
	char	borders;
	char	center;

	start_s = 'A';
	borders = 'B';
	end_s = 'C';
	center = ' ';

	num_pos = 1;
	while ((num_pos <= heigth) && (1 <= width))
	{
		if (num_pos == 1 || num_pos == heigth)
			print_string(start_s, end_s, borders, width);
		else
			print_string(borders, borders, center, width);
		ft_putchar('\n');
		num_pos++;
	}
}

void	print_string(char start_s, char end_s, char middle, int length)
{
	int length_s;

	length_s = length;
	if (length_s > 0)
	{
		ft_putchar(start_s);
		length_s -= 2;
	}
	if (length_s > 0)
		print_midlle_chars(middle, &length_s);
	length_s++;
	if (length_s > 0)
		ft_putchar(end_s);
}

void	print_midlle_chars(char middle, int *length)
{
	int num_pos;

	num_pos = 0;
	while (num_pos < *(length))
	{
		ft_putchar(middle);
		num_pos++;
	}
	*(length) -= num_pos;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
