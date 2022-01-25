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
    game.mlx = mlx_init();
	return 0;
}