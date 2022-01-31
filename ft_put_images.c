/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:21:31 by abernita          #+#    #+#             */
/*   Updated: 2022/01/26 11:21:33 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image_to_window(t_game *game, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx,
			game->window, game->ground, x, y);
	else if (c == '1')
		mlx_put_image_to_window(game->mlx,
			game->window, game->wall, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx,
			game->window, game->exit_img, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx,
			game->window, game->coll_img, x, y);
	else if ((c == 'P') || (c == 'D'))
		mlx_put_image_to_window(game->mlx,
			game->window, game->p_d_img, x, y);
	else if (c == 'U')
		mlx_put_image_to_window(game->mlx,
			game->window, game->p_u_img, x, y);
	else if (c == 'L')
		mlx_put_image_to_window(game->mlx,
			game->window, game->p_l_img, x, y);
	else if (c == 'R')
		mlx_put_image_to_window(game->mlx,
			game->window, game->p_r_img, x, y);
}

void	ft_put_enemy_to_window(t_game *game, char c, int x, int y)
{
	if (c == 'T')
		mlx_put_image_to_window(game->mlx,
			game->window, game->enemy, x, y);
	else if (c == 'X')
		mlx_put_image_to_window(game->mlx,
			game->window, game->enemy2, x, y);
}

int	ft_animation(t_game *game)
{
	static int	u;
	int			w;
	int			h;

	if (u % 15 == 0)
	{
		if (game->enemies)
			ft_move_enemy(game);
	}
	if (u % 15 == 0)
		game->coll_img = mlx_xpm_file_to_image(game->mlx,
				"./img/btc1.xpm", &w, &h);
	if (u % 30 == 0)
		game->coll_img = mlx_xpm_file_to_image(game->mlx,
				"./img/btc2.xpm", &w, &h);
	if (game->winner == 1 || game->winner == -1)
	{
		if (u % 300 == 0)
			exit (0);
	}
	u++;
	ft_put_images(game, 0, 0);
	return (0);
}

void	ft_check_winner(t_game *game, int s_x, int s_y, char *s)
{
	ft_put_images_to_window(game, (s_x), (s_y));
	if (game->winner == 0)
	{
		mlx_string_put(game->mlx, game->window, 5, 5, 0xFFFF00, "Moves:");
		mlx_string_put(game->mlx, game->window, 66, 5, 0xFFFF00, s);
	}
	else if (game->winner == 1)
		mlx_string_put(game->mlx, game->window, s_x, s_y, \
		0x000000, "You Win");
	else if (game->winner == -1)
		mlx_string_put(game->mlx, game->window, s_x, s_y, \
		0x000000, "Game Over");
}

void	ft_put_images(t_game *game, int i, int j)
{
	int		w;
	char	*s;
	int		s_x;
	int		s_y;

	w = IMGSIZE;
	s_x = (game->width * w - w) / 2;
	s_y = (game->height * w - w) / 2;
	s = ft_itoa(game->moves);
	mlx_clear_window(game->mlx, game->window);
	while (i < game->width)
	{
		j = -1;
		while (++j < game->height)
		{
			ft_put_image_to_window(game, game->map[j][i], (i * w), (j * w));
			ft_put_enemy_to_window(game, game->map[j][i], (i * w), (j * w));
			ft_check_winner(game, s_x, s_y, s);
		}
		i++;
	}
	free(s);
}
