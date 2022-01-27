/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:30:08 by abernita          #+#    #+#             */
/*   Updated: 2022/01/26 13:30:15 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void 	ft_check_collect(t_game *game, int y, int x)
{
	if (game->collect == 0)
	{
		if (game->map[game->pos_y - y][game->pos_x - x] == 'E')
		{
			game->moves++;
			printf("Moves: %d\n", game->moves);
			ft_win_lose(game, 1);
		}
	}
}

void 	ft_move_up(t_game *game)
{
	ft_check_collect(game, 1, 0);
	if (!(ft_strchr("1E", game->map[game->pos_y - 1][game->pos_x])))
	{
		if (game->map[game->pos_y - 1][game->pos_x] == 'C')
			game->collect--;
		if (game->map[game->pos_y - 1][game->pos_x] == 'X')
			ft_win_lose(game, 1);
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_y--;
		if (game->move_u == 0)
		{
			game->map[game->pos_y][game->pos_x] = 'U';
			game->move_u = 1;
		}
		else
		{
			game->map[game->pos_y][game->pos_x] = 'u';
			game->move_u = 0;
		}
		game->moves++;
		printf("Moves: %d\n", game->moves);
	}
}

void	ft_move_down(t_game *game)
{
	ft_check_collect(game, -1, 0);
	if (!(ft_strchr("1E", game->map[game->pos_y + 1][game->pos_x])))
	{
		if (game->map[game->pos_y + 1][game->pos_x] == 'C')
			game->collect--;
		if (game->map[game->pos_y + 1][game->pos_x] == 'X')
			ft_win_lose(game, 0);
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_y++;
		game->map[game->pos_y][game->pos_x] = 'D';
		game->moves++;
		printf("Moves: %d\n", game->moves);
	}
}

void	ft_move_left(t_game *game)
{
	ft_check_collect(game, 0, 1);
	if (!(ft_strchr("1E", game->map[game->pos_y][game->pos_x - 1]))) {
		if (game->map[game->pos_y][game->pos_x - 1] == 'C')
			game->collect--;
		if (game->map[game->pos_y][game->pos_x - 1] == 'X')
			ft_win_lose(game, 0);
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_x--;
		if (game->move_l == 0)
		{
			game->map[game->pos_y][game->pos_x] = 'L';
			game->move_l = 1;
		}
		else
		{
			game->map[game->pos_y][game->pos_x] = 'l';
			game->move_l = 0;
		}
		game->moves++;
		printf("Moves: %d\n", game->moves);

	}
}

void	ft_move_right(t_game *game)
{
	ft_check_collect(game, 0, -1);
	if (!(ft_strchr("1E", game->map[game->pos_y][game->pos_x + 1]))) {
		if (game->map[game->pos_y][game->pos_x + 1] == 'C')
			game->collect--;
		if (game->map[game->pos_y][game->pos_x + 1] == 'X')
			ft_win_lose(game, 0);
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_x++;
		if (game->move_l == 0)
		{
			game->map[game->pos_y][game->pos_x] = 'R';
			game->move_l = 1;
		}
		else
		{
			game->map[game->pos_y][game->pos_x] = 'r';
			game->move_l = 0;
		}
		game->moves++;
		printf("Moves: %d\n", game->moves);

	}
}