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

# define IMGSIZE 20


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
	void	*ground;
	void	*wall;
	void	*exit_img;
	void	*collect_img;
	void	*collred_img;

	void	*player_up_img;
	void	*player_dwn_img;
	void	*player_l_img;
	void	*player_r_img;

	int 	exit;
	int		moves;
	int 	winner;
	int 	ter_x;
	int 	ter_y;
    void    *mlx;

	int 	move_u;
	int 	move_l;
	int 	move_c;
}	t_game;

typedef struct s_img
{
    void	*path;
    int		x_size;
    int		y_size;
}	t_img;



int 	main(int ac, char **av);

void 	ft_error(const char *text);
void	ft_close_game(void);
void	ft_check_enemy(t_game *game);
void	ft_put_images_to_window(t_game *game, int i, int j);
void	ft_win_lose(t_game *game, int flag);

char 	**ft_read_map(char *file);

void	ft_map_validation(t_game *game);

void	ft_start(t_game *game);
void 	ft_put_enemy(t_game *game);

void	ft_put_images(t_game *game, int i, int j);
void 	ft_check_win(t_game *game, int s_x, int s_y, char *s);
void	ft_put_image_to_window(t_game *game, char c, int x, int y);
int		ft_animation(t_game *game);

void 	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

int 	ft_render_img(t_game *game);

int 	ft_move_enemy(t_game *game);

#endif
