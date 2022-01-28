/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:06:20 by abernita          #+#    #+#             */
/*   Updated: 2022/01/25 16:06:22 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_objects(t_game *game, int i, int j)
{
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				game->collect++;
			if (game->map[i][j] == 'P')
			{
				game->pos_x = j;
				game->pos_y = i;
				game->player++;
			}
			if (game->map[i][j] == 'E')
				game->exit++;
			if (game->map[i][j] == '0')
				game->space++;
		}
	}
	if (game->player != 1 || game->exit < 1 || game->collect < 1
		|| game->space < 1)
		ft_error("Error! Wrong objects amount! (CPE0)\n");
}

void	ft_check_walls(t_game *game, int h, int w)
{
	int	w_c;

	w_c = w;
	while (w >= 0)
	{
		if (game->map[0][w] != '1' || game->map[h][w] != '1')
			ft_error("Error! Wrong walls placement!\n");
		w--;
	}
	while (h >= 0)
	{
		if (game->map[h][0] != '1' || game->map[h][w_c] != '1')
			ft_error("Error! Wrong walls placement!!\n");
		h--;
	}
}

void	ft_map_validation(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	w = (int)ft_strlen(game->map[0]);
	game->width = w;
	while (game->map[h])
	{
		if ((int)ft_strlen(game->map[h]) != w)
			ft_error("Error! Wrong width!\n");
		h++;
	}
	game->height = h;
	ft_check_objects(game, -1, -1);
	ft_check_walls(game, h - 1, w - 1);
}
