#include "../inc/so_long.h"

void	initstuff(char **argv, t_game *game)
{
    game->mapname = argv[1];
    game->mapfd = open(argv[1], O_RDONLY);
    game->l_inmap = 0;
    game->c_inmap = 0;
    game->x_map = 0;
    game->y_map = 0;
}