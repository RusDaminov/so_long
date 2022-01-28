/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:55:01 by abernita          #+#    #+#             */
/*   Updated: 2022/01/26 19:55:07 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_enemy_left(t_game *game, int *f)
{
	int u;

	u = 0;
	if (!(ft_strchr("1EC", game->map[game->ter_y][game->ter_x - 1])))
	{
		game->map[game->ter_y][game->ter_x - 1] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_x--;

	}
	else
	{
		*f = 1;

	}
}

void	ft_move_enemy_right(t_game *game, int *f)
{
	if (!(ft_strchr("1EC", game->map[game->ter_y][game->ter_x + 1])))
	{
		game->map[game->ter_y][game->ter_x + 1] = 'X';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_x++;
	}
	else
	{
		*f = 0;
	}
}

int 	ft_move_enemy(t_game *game)
{
	static int u;
	static int f;

	if (u % 15 == 0 || f == 0)
		ft_move_enemy_left(game, &f);
	if (u % 15 == 0 || f == 1)
		ft_move_enemy_right(game, &f);
	u++;
	ft_check_enemy(game);
	return (0);
}