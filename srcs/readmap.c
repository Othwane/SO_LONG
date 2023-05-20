#include "../inc/so_long.h"

void    readmap(t_game *game)
{
    char *buff;
    int line;

	line = 0;
    while (1)
	{
		buff = get_next_line(game->mapfd);
		if (buff)
			free(buff);
		else
			break ;
		line++;
	}
    close(game->mapfd);
    if (!(game->map = malloc(line * sizeof(char *))))
    {
		close(game->mapfd);
		return ;
	}
	close(game->mapfd);
	fdlines_c(game);
}

void    fdlines_c(t_game *game)
{
	game->mapfd = open(game->mapname, O_RDONLY);
	//printf("%s\n",get_next_line(game->mapfd));
	//game->map[game->l_inmap] = get_next_line(game->mapfd);
	while (1)
	{
		game->map[game->l_inmap] = get_next_line(game->mapfd);
		if (game->map[game->l_inmap] == NULL)
			break ;
		if (game->map[game->l_inmap][0] == '\n' && game->map[game->l_inmap][1] == '\0')
			errorf(3);
		game->l_inmap++;
	}
    game->c_inmap = ft_strlen(game->map[0]);
}