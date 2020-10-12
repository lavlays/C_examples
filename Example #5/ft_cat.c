#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	char	b;
	int		a;

	b = *str;
	a = 0;
	while (*(str + a) != '\0')
	{
		write(2, &b, 1);
		++a;
		b = *(str + a);
	}
}

void	dis_er(char *filename, char *argv)
{
	ft_putstr(basename(argv));
	ft_putstr(": ");
	ft_putstr(filename);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

void	display(void)
{
	char	c;

	while (read(0, &c, 1) > 0)
		write(1, &c, 1);
}

void	show(char *argv, char *c)
{
	char	buf[BUF_SIZE + 1];
	int		pd;
	int		res;

	errno = 0;
	if ((pd = open(argv, O_RDONLY)) > 0)
	{
		while ((res = read(pd, buf, BUF_SIZE)) > 0)
			write(1, &buf, res);
		if (res < 0)
			dis_er(argv, c);
	}
	else
		dis_er(argv, c);
	close(pd);
}

int		main(int argc, char *argv[])
{
	int i;

	i = 1;
	errno = 0;
	if (argc == 1)
	{
		display();
		return (0);
	}
	while (argc > i)
	{
		if (ft_strcmp(argv[i], "-") == 0)
			display();
		else
			show(argv[i], argv[0]);
		i++;
	}
	return (0);
}
