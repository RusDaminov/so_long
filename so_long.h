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
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx/mlx_mms/mlx.h"
# include "libft/libft.h"

# define IMGSIZE 40


typedef struct s_game
{
	char	**map;
	int		height;
	int		width;
	void 	*window;
	int		collect;
	int 	player;
	int		pos_x;
	int		pos_y;
	int		enemy;
	int		enemies;
	int		space;
	int 	exit;
	int		moves;
	int 	winner;
	int 	ter_x;
	int 	ter_y;
    void    *mlx;
}	t_game;

typedef struct s_img
{
    void	*path;
    int		x_size;
    int		y_size;
}	t_img;



int 	main(int ac, char **av);

void 	ft_error(const char *text);
void	ft_close_game(void);

char 	**ft_read_map(char *file);

void	ft_map_validation(t_game *game);

void	ft_start(t_game *game);
void 	ft_put_enemy(t_game *game);

void	ft_put_images(t_game *game, int i, int j);


#endif
