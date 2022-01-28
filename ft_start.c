/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:21:46 by abernita          #+#    #+#             */
/*   Updated: 2022/01/26 11:21:48 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void 	ft_put_enemy(t_game *game)
{
	if (game->width > 6 && game->height > 3)
	{
		if (!(ft_strchr("1ECP", game->map[game->height - 2]
			[game->width - 3])))
		{
			game->map[game->height - 2][game->width - 3] = 'X';
			game->ter_x = game->width - 3;
			game->ter_y = game->height - 2;
			game->enemies = 1;
		}
	}
}

int		ft_key_press(int key, t_game *game)
{
	if (key == 53)
	{
		ft_error("Farewell\n");
		exit(0);
	}
	if (key == 13)
		ft_move_up(game);
	if (key == 1)
		ft_move_down(game);
	if (key == 0)
		ft_move_left(game);
	if (key == 2)
		ft_move_right(game);
	ft_check_enemy(game);
	ft_put_images(game, 0, 0);
	return 0;
}

void	ft_start(t_game *game)
{
	int	window_height;
	int window_width;

	game->mlx = mlx_init();
	window_height = game->height * IMGSIZE;
	window_width = game->width * IMGSIZE;
	game->window = mlx_new_window(game->mlx, window_width, window_height, "So_Long");
	if (ft_render_img(game) == -1)
		ft_error("Error opening images\n");
	ft_put_images(game, 0, 0);
	mlx_key_hook(game->window, ft_key_press, game);
	mlx_loop_hook(game->mlx, ft_animation, game);
	mlx_hook(game->window, 17, 0L, ft_close_game, 0);
	mlx_loop(game->mlx);
}



