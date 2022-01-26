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

void	ft_error(const char *text)
{
    ft_putstr_fd(text, 1);
    ft_putstr_fd("\n", 1);
    exit(EXIT_FAILURE);
}

void	ft_close_game(void)
{
	ft_error("Game Over\n");
	exit(0);
}

void	ft_check_enemy(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x] == 'X')
		ft_close_game();
}