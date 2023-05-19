#include "../inc/so_long.h"

void    n_map(t_game *game)
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
	printf("%d\n", line);
    game->map = malloc(line * sizeof(char *));
    readmap(game);
}

void    readmap(t_game *game)
{
	if (!game->map)
        return ;
	close(game->mapfd);
	game->mapfd = open(game->mapname, O_RDONLY);
	printf("%s\n",get_next_line(game->mapfd));
	// game->map[game->l_map] = get_next_line(game->mapfd);
	// while (1)
	// {
	// 	game->map[game->l_map] = get_next_line(game->mapfd);
	// 	if (game->map[game->l_map] == NULL)
	// 		break ;
	// 	if (game->map[game->l_map][0] == '\n' && game->map[game->l_map][1] == '\0')
	// 		errorf(3);
	// 	game->l_map++;
	// }
    // game->c_map = ft_strlen(game->map[0]);
}