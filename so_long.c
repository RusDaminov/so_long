/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:05:51 by abernita          #+#    #+#             */
/*   Updated: 2022/01/25 16:05:54 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_enemy(t_game *game)
{
	if (game->width > 6 && game->height > 3)
	{
		if (!(ft_strchr("1ECP", game->map[game->height - 2]
		[game->width - 3])))
		{
			game->map[game->height - 2][game->width - 3] = 'T';
			game->ter_x = game->width - 3;
			game->ter_y = game->height - 2;
			game->enemies = 1;
		}
	}
}

void	ft_init_struct(t_game *game) {
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->space = 0;
	game->player = 0;
	game->collect = 0;
	game->exit = 0;
	game->moves = 0;
	game->mlx = NULL;
	game->window = NULL;
	game->ter_x = 0;
	game->ter_y = 0;
	game->winner = 0;
	game->enemies = 0;
}

void	ft_check_extension(char *ber)
{
	size_t	len;

	len = ft_strlen(ber);
	if ((ft_strncmp(&ber[len - 4], ".ber", 4)) == 0)
		return ;
	else
		ft_error("Error! Wrong extension!\n");
}

int	main(int argc, char **argv)
{
	t_game 	game;

	if (argc == 2)
	{
		ft_check_extension(argv[1]);
		ft_init_struct(&game);
		game.map = ft_parsing(argv[1]);
		ft_map_validation(&game);
		ft_put_enemy(&game);
		ft_start(&game);
	}
	else
		ft_error("Error! Wrong argument number!\n");
	return (0);
}

int 	ft_close_game(void)
{
	ft_error("Farewell\n");
	exit(0);
}
