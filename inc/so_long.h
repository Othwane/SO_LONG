#ifndef	SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 100

typedef struct	s_game {
	void	*mlx;
	void	*win;
	int		w_heigth;	
	int		w_weidth;
	
	char	**map;
	char	*mapname;
	char 	*mapx;
	int 	mapfd;
	int		l_map;
	int		c_map;
	int 	x_map;
	int 	y_map;

	int 	player;
	int 	x_player;
	int 	y_player;

	int 	collects;

	int	moves;

	int 	exit;
	int 	x_exit;
	int 	y_exit;

}	t_game;

int 	ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

int		slength(char *string);
char	*searchr(char *string, int x);
char	*stringjoin(char *pref, char *suff);
char	*ft_read_ln(int fd, char *line);
char	*ft_until_nl(char *string);
char	*ft_after_nl(char *string);
char	*get_next_line(int fd);

void	argschecker(int argc, char **argv, t_game *game);
void	initstuff(char **argv, t_game *game);
void    errorf(int error);

void    r_map(t_game *game);
void    n_map(t_game *game);


#endif
