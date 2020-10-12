#ifndef FT_H

# define FT_H

#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 10
#include <sys/errno.h>
#include <libgen.h>
#include <string.h>
#include <stdlib.h>

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
