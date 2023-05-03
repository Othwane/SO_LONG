#ifndef	SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


typedef	struct	s_image {
	void	*img;
	char	*addr;
	int	heigth;
	int	width;
	int	endian;
	int	bbpixel;
	int	linelentgh;
}	t_image;

typedef struct	s_info {
	int	pexist;
	int	cexist;
	int	eexist;
}	t_info;

typedef	struct	s_handw {
	int	heigth;
	int	width;
}	t_handw;

typedef	struct	s_vector {
	int	x;
	int	y;
}	t_vector;

typedef	struct	s_player {
	t_image img;
	t_vector cposition;
	t_vector lposition;
}	t_player;

typedef	struct	s_map {
	int	m_heigth;
	int	m_width;
	int	**twod_map;
	t_vector x_ypos;
}	t_map;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	int	hwin;
	int	wwin;
	int	moves;
	t_map	**map;
	t_player player;
	t_info	info;
	
}	t_game;

#endif
