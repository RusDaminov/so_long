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

int		ft_render_enemy(t_game *game)
{
	int	iw;
	int	ih;

	game->enemy = mlx_xpm_file_to_image(game->mlx,"./imgs/tilest1.xpm", &iw, &ih);
	if (!(game->ground))
		return (-1);
	return (0);
}

int 	ft_render_tiles(t_game *game)
{
	int	iw;
	int	ih;

	game->ground = mlx_xpm_file_to_image(game->mlx, "./imgs/tilest1.xpm", &iw, &ih);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./imgs/tilest1.xpm", &iw, &ih);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./imgs/tilest1.xpm", &iw, &ih);
	if (!(game->ground) || !(game->wall) || !(game->exit_img))
		return (-1);
	return (0);
}

int		ft_render_collect(t_game *game)
{
	int	iw;
	int	ih;

	game->collect_img = mlx_xpm_file_to_image(game->mlx, "./imgs/tilest1.xpm", &iw, &ih);
	game->collred_img = mlx_xpm_file_to_image(game->mlx, "./imgs/tilest1.xpm", &iw, &ih);
	if (!(game->collect_img) || !(game->collred_img))
		return (-1);
	return (0);
}

int 	ft_render_player(t_game *game)
{
	int	iw;
	int	ih;

	game->player_up_img = mlx_xpm_file_to_image(game->mlx, "./imgs/tilest1.xpm", &iw, &ih);
	game->player_dwn_img = mlx_xpm_file_to_image(game->mlx, "./imgs/tilest1.xpm", &iw, &ih);
	game->player_l_img = mlx_xpm_file_to_image(game->mlx, "./imgs/tilest1.xpm", &iw, &ih);
	game->player_r_img = mlx_xpm_file_to_image(game->mlx, "./imgs/tilest1.xpm", &iw, &ih);
	if (!(game->player_up_img) || !(game->player_dwn_img) || !(game->player_l_img) || !(game->player_r_img))
		return (-1);
	return (0);
}

int		ft_render_img(t_game *game)
{
	if (ft_render_tiles(game) == -1)
		return (-1);
	if (ft_render_collect(game) == -1)
		return (-1);
	if (ft_render_player(game) == -1)
		return (-1);
	if (ft_render_enemy(game) == -1)
		return (-1);
	return (0);
}
