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
	if (!(ft_strchr("1EC", game->map[game->ter_y][game->ter_x - 1])))
	{
		game->map[game->ter_y][game->ter_x - 1] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_x--;
	}
	else
	{
		*f = 1;
		ft_move_enemy_up(game, f);
	}
}

void	ft_move_enemy_right(t_game *game, int *f)
{
	if (!(ft_strchr("1EC", game->map[game->ter_y][game->ter_x + 1])))
	{
		game->map[game->ter_y][game->ter_x + 1] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_x++;
	}
	else
		*f = 0;
}

void	ft_move_enemy_down(t_game *game, int *f)
{
	if (!(ft_strchr("1EC", game->map[game->ter_y + 1][game->ter_x])))
	{
		game->map[game->ter_y + 1][game->ter_x] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_y++;
		*f = 2;
	}
	else
		*f = 1;
}

void	ft_move_enemy_up(t_game *game, int *f)
{
	if (!(ft_strchr("1EC", game->map[game->ter_y - 1][game->ter_x])))
	{
		game->map[game->ter_y - 1][game->ter_x] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_y--;
	}
	else
		ft_move_enemy_down(game, f);
}

int 	ft_move_enemy(t_game *game)
{
	static int u;
	static int f;

	if (u % 15 == 0 || f == 0)
		ft_move_enemy_left(game, &f);
	if (u % 15 == 0 || f == 1)
		ft_move_enemy_right(game, &f);
	if (u % 15 == 0 || f == 2)
		ft_move_enemy_down(game, &f);
//	if (u % 15 == 0 || f == 3)
//		ft_move_enemy_up(game, &f);
	u++;
	ft_check_enemy(game);
	return (0);
}