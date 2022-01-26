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

void	ft_init_params(t_game *game)
{
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->space = 0;
	game->player = 0;
	game->enemy = 0;
	game->collect = 0;
	game->exit = 0;
	game->moves = 0;
	game->mlx = NULL;
	game->window = NULL;

}
void	ft_check_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if ((ft_strncmp(&file[len - 4, ".ber", 4]) == 0))
		return;
	else
		ft_error("Wrong file extension\n");
}

int		main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
        ft_error("Wrong arguments number\n");
	ft_check_extension(av[1]);
	ft_init_params(&game);
    game.map = ft_read_map(av[1]);
	ft_map_validation(&game);
	ft_put_enemy(&game);
	ft_start(&game);

	return 0;
}
