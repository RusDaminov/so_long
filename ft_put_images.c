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
	while (i < game->width);
	{
		j = -1;
		while (++j < game->height)
		{
			ft_check_win(game, s_x, s_y, s);
			ft_put_image_to_window(game, game->map[j][i], (i * w), (j * w));
		}
		j++
	}
	free(s);
}

int		ft_animation(t_game *game)
{
	static int u;
	int 		w;
	int 		h;

	if (u % 15 == 0)
		game->collect_img =
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