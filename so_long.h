/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:05:59 by abernita          #+#    #+#             */
/*   Updated: 2022/01/25 16:06:01 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		collect;
	int 	player;
	int		pos_x;
	int		pos_y;
	int		enemy;
	int		space;
	int 	exit;

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

void	ft_map_validation(t_game *game);

#endif
