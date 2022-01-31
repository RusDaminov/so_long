/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renfer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:59:09 by abernita          #+#    #+#             */
/*   Updated: 2022/01/26 14:59:11 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_enemy(t_game *game)
{
	int	iw;
	int	ih;

	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"./img/enemy.xpm", &iw, &ih);
	game->enemy2 = mlx_xpm_file_to_image(game->mlx,
			"./img/enemy2.xpm", &iw, &ih);
	if (!(game->ground))
		return (-1);
	return (0);
}

int	ft_open_collect(t_game *game)
{
	int	iw;
	int	ih;

	game->coll_img = mlx_xpm_file_to_image(game->mlx,
			"./img/btc1.xpm", &iw, &ih);
	game->coll2_img = mlx_xpm_file_to_image(game->mlx,
			"./img/btc2.xpm", &iw, &ih);
	if (!(game->coll_img) || !(game->coll2_img))
		return (-1);
	return (0);
}

int	ft_open_space_wall_exit(t_game *game)
{
	int	iw;
	int	ih;

	game->ground = mlx_xpm_file_to_image(game->mlx,
			"./img/space.xpm", &iw, &ih);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &iw, &ih);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"./img/exit.xpm", &iw, &ih);
	if (!(game->ground) || !(game->wall) || !(game->exit_img))
		return (-1);
	return (0);
}

int	ft_open_player(t_game *game)
{
	int	iw;
	int	ih;

	game->p_u_img = mlx_xpm_file_to_image(game->mlx,
			"./img/up.xpm", &iw, &ih);
	game->p_d_img = mlx_xpm_file_to_image(game->mlx,
			"./img/down.xpm", &iw, &ih);
	game->p_l_img = mlx_xpm_file_to_image(game->mlx,
			"./img/left.xpm", &iw, &ih);
	game->p_r_img = mlx_xpm_file_to_image(game->mlx,
			"./img/right.xpm", &iw, &ih);
	if (!(game->p_u_img) || !(game->p_d_img)
		|| !(game->p_l_img) || !(game->p_r_img))
		return (-1);
	return (0);
}

int	ft_render_img(t_game *game)
{
	if (ft_open_space_wall_exit(game) == -1)
		return (-1);
	if (ft_open_collect(game) == -1)
		return (-1);
	if (ft_open_player(game) == -1)
		return (-1);
	if (ft_open_enemy(game) == -1)
		return (-1);
	return (0);
}
