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

int 	ft_move_enemy(t_game *game)
{
	static int u;
	static int f;

	if (u % 15 == 0 || f == 0)
		ft_move_enemy_left(game, &f);
	if (u % 15 == 0 || f == 1)
		ft_move_enemy_rigth(game, &f);
	if (u % 15 == 0 || f == 2)
		ft_move_enemy_down(game, &f);
	u++;
	ft_check_enemy(game);
	return (0);
}