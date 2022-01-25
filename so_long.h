#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "mlx/mlx_mms/mlx.h"
#include "libft/libft.h"


typedef struct s_game
{
	char	**map;
	int		height;
	int		width;
    void    *mlx;
}	t_game;

typedef struct s_img
{
    void	*path;
    int		x_size;
    int		y_size;
}	t_img;



int main(int ac, char **av);

void ft_error(const char *text);

char **ft_read_map(char *file);

#endif