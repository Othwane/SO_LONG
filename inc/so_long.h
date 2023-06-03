/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:39:10 by omajdoub          #+#    #+#             */
/*   Updated: 2023/06/03 21:40:05 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 1

typedef struct s_g_imgs
{
	void	*wall;
	void	*backg;
	void	*player;
	void	*coin;
	void	*exit;
}		t_g_imgs;

typedef struct s_game {
	void		*mlx;
	void		*win;
	int			w_heigth;
	int			w_weidth;	
	char		**map;
	char		*mapname;
	char		*mapx;
	int			mapfd;
	int			l_inmap;
	int			c_inmap;
	int			player;
	int			x_player;
	int			y_player;
	int			collects;
	int			moves;
	int			exit;
	int			x_exit;
	int			y_exit;
	t_g_imgs	imgs;
}	t_game;

typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

void	pce(t_game *game, int i, int ii);

void	argschecker(char **argv);
void	initstuff(char **argv, t_game *game);
void	errorf(int error);
int		strlenn(char **str);
void	readmap(t_game *game);
void	mapchecker(t_game *game);
void	check_map_size(t_game *game);
void	check_walls(t_game *game);
void	check_pce(t_game *game);
void	check_noneeded(t_game *game);
int		cf_line(t_game *game);
int		cl_lines(t_game *game);
void	check_valid_path(t_game *game);
void	ddnl(t_game *game);
void	drawmap(t_game *game);
void	draw(t_game *game, int i, int ii);
char	get_in_pos(t_game *game, int x, int y);
void	change_char_in_map(t_game *game, t_pos ppostion, \
		t_pos nextposition);
int		handle_event(int keycode, t_game *game);
void	go_right(t_game *game, t_pos pposition);
void	go_left(t_game *game, t_pos pposition);
void	go_up(t_game *game, t_pos pposition);
void	go_down(t_game *game, t_pos pposition);
int		playgame(t_game *game);
void	free_map(char **str);
int		leave(t_game *game);

t_pos	get_pos(char **map, char c);
#endif
