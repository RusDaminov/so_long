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

void	ft_put_images(t_game *game, int i, int j)
{
	int	w;
	char *s;
	int s_x;
	int s_y;

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
			ft_check_win(game, s_x, s_y, s);
			ft_put_image_to_window(game, game->map[j][i], (i * w), (j * w));
		}
		j++;
	}
	free(s);
}

int		ft_animation(t_game *game)
{
	static int u;
	int 		w;
	int 		h;

	if (u % 15 == 0)
		game->collect_img = mlx_xpm_file_to_image(game->mlx, ".imgs/tilest1.xpm", &w, &h);
	if (u % 30 == 0)
		game->collect_img = mlx_xpm_file_to_image(game->mlx, ".imgs/tilest1.xpm", &w, &h);
	if (u % 45 == 0)
		game->collect_img = mlx_xpm_file_to_image(game->mlx, ".imgs/tilest1.xpm", &w, &h);
	if (game->winner == 1 || game->winner == -1)
	{
		if (u % 300 == 0)
			exit (0);
	}
	u++;
	if (game->enemies)
		ft_move_enemy(game);
	ft_put_images(game, 0, 0);
	return (0);
}

void 	ft_check_win(t_game *game, int s_x, int s_y, char *s)
{
	if (game->winner == 0)
		mlx_string_put(game->mlx, game->window, 5, 5, 0x000000, s);
	else if (game->winner == 1)
		mlx_string_put(game->mlx, game->window, s_x, s_y, 0x000000, "You Win!");
	else if (game->winner == -1)
		mlx_string_put(game->mlx, game->window, s_x, s_y, 0x000000, "Game Over!");
}

void	ft_put_image_to_window(t_game *game, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->ground, x, y);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, x, y);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit_img, x, y);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collect_img, x, y);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player_dwn_img, x, y);
	if (c == 'U')
		mlx_put_image_to_window(game->mlx, game->window, game->player_up_img, x, y);
	if (c == 'u')
		mlx_put_image_to_window(game->mlx, game->window, game->player_up_img, x, y);
	if (c == 'R')
		mlx_put_image_to_window(game->mlx, game->window, game->player_r_img, x, y);
	if (c == 'r')
		mlx_put_image_to_window(game->mlx, game->window, game->player_r_img, x, y);
	if (c == 'L')
		mlx_put_image_to_window(game->mlx, game->window, game->player_l_img, x, y);
	if (c == 'l')
		mlx_put_image_to_window(game->mlx, game->window, game->player_l_img, x, y);
	if (c == 'X')
		mlx_put_image_to_window(game->mlx, game->window, game->enemy, x, y);
}