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

void	check_extension(char *file)
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
	check_extension(av[1]);
    game.map = ft_read_map(av[1]);
	ft_map_validation(&game);
    game.mlx = mlx_init();
	return 0;
}
