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
//
//void	put_enemy(t_game *game)
//{
//	if (game->width > 6 && game->height > 3)
//	{
//		if (!(ft_strchr("1ECP", game->map[game->height - 2]
//		[game->width - 3])))
//		{
//			game->map[game->height - 2][game->width - 3] = 'T';
//			game->ter_x = game->width - 3;
//			game->ter_y = game->height - 2;
//			game->enemies = 1;
//		}
//	}
//}
//
//void	creat_struct(t_game *game)
//{
//	game->map = NULL;
//	game->height = 0;
//	game->width = 0;
//	game->space = 0;
//	game->player = 0;
//	game->collect = 0;
//	game->exit = 0;
//	game->moves = 0;
//	game->mlx = NULL;
//	game->window = NULL;
//	game->ter_x = 0;
//	game->ter_y = 0;
//	game->winner = 0;
//	game->enemies = 0;
//	game->move_c = 0;
//	game->move_l = 0;
//	game->move_u = 0;
//}
//
//void	check_extension(char *ber)
//{
//	size_t	len;
//
//	len = ft_strlen(ber);
//	if ((ft_strncmp(&ber[len - 4], ".ber", 4)) == 0)
//		return ;
//	else
//		ft_error("Whats up, man?! Where is my correct map?!\n");
//}
//
//int	main(int argc, char **argv)
//{
//	t_game 	game;
//
//	if (argc == 2)
//	{
//		check_extension(argv[1]);
//		creat_struct(&game);
//		game.map = ft_parsing(argv[1]);
//		ft_map_validation(&game);
//		put_enemy(&game);
//		ft_start(&game);
//	}
//	else
//		ft_error("Hey, man! You do something wrong!\n");
//	return (0);
//}

void	ft_check_object(t_game *game, int i, int j)
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
		ft_error("I don't like your map!\n");
}

void	ft_check_walls(t_game *game, int h, int w)
{
	int	w_c;

	w_c = w;
	printf("h=%d, w=%d\n", h, w);
	while (w >= 0)
	{
		if (game->map[0][w] != '1' || game->map[h][w] != '1')
			ft_error("I don't like your map!\n");
		w--;
	}
	while (h >= 0)
	{
		if (game->map[h][0] != '1' || game->map[h][w_c] != '1')
			ft_error("I don't like your map!\n");
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
			ft_error("Man, map is bad! I don't play your games!\n");
		h++;
	}
	game->height = h;
	ft_check_object(game, -1, -1);
	printf("h=%d, w=%d\n", h, w);
	ft_check_walls(game, h - 1, w - 1);
}
