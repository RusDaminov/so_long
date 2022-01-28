/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:05:59 by abernita          #+#    #+#             */
/*   Updated: 2022/01/25 16:06:01 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx/mlx_mms/mlx.h"
# include "libft/libft.h"

# define IMGSIZE 40


typedef struct s_game
{
	char	**map;
	int		height;
	int		width;
	void 	*window;
	int		collect;
	int 	player;
	int		pos_x;
	int		pos_y;
	int		enemies;
	int		space;
	void	*enemy;
	void	*enemy2;
	void	*ground;
	void	*wall;
	void	*exit_img;
	void	*collect_img;
	void	*collect2_img;
	void	*player_u_img;
	void	*player_d_img;
	void	*player_l_img;
	void	*player_r_img;
	int 	exit;
	int		moves;
	int 	winner;
	int 	ter_x;
	int 	ter_y;
    void    *mlx;
}	t_game;

// so_long
int 	main(int ac, char **av);
// ft_error
void 	ft_error(const char *text);
int 	ft_close_game(void);
void	ft_check_enemy(t_game *game);
void	ft_put_images_to_window(t_game *game, int i, int j);
void	ft_win_lose(t_game *game, int flag);
// ft_parsing
char 	**ft_parsing(char *file);
// ft_map_validation
void	ft_map_validation(t_game *game);
// ft_start
void	ft_start(t_game *game);
void 	ft_put_enemy(t_game *game);
// ft_put_images
void	ft_put_images(t_game *game, int i, int j);
void	ft_put_image_to_window(t_game *game, char c, int x, int y);
int		ft_animation(t_game *game);
// ft_moves
void 	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
// ft_render
int 	ft_render_img(t_game *game);
// ft_enemy
int 	ft_move_enemy(t_game *game);
void	ft_move_enemy_left(t_game *game, int *f);
void	ft_move_enemy_right(t_game *game, int *f);

#endif
