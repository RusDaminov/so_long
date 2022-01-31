/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:06:07 by abernita          #+#    #+#             */
/*   Updated: 2022/01/25 16:06:11 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//void	ft_put_images_window(t_game *game, int i, int j)
//{
//	while (i < game->width)
//	{
//		j = 0;
//		while (j < game->height)
//			game->map[j++][i] = '1';
//		i++;
//	}
//}

void	ft_error(const char *text)
{
    ft_putstr_fd(text, 1);
    ft_putstr_fd("\n", 1);
    exit(EXIT_FAILURE);
}

void	ft_check_enemy(t_game *game)
{
	if ((game->map[game->pos_y][game->pos_x] == 'T') || (game->map[game->pos_y][game->pos_x] == 'X'))
		ft_win(game, 0);
}

void	ft_win(t_game *game, int flag)
{
	int iw;
	int ih;

	game->wall	= mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &iw, &ih);
	ft_put_images_to_window(game, 0, 0);
	if (flag == 1)
	{
		game->winner = 1;
		ft_error("You Win!!!\n");
	}
	else
	{
		game->winner = -1;
		ft_error("Game Over!\n");
	}
}