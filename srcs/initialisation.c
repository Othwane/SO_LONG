#include "../inc/so_long.h"

void    mapinit(t_map **map)
{
    *map = malloc(sizeof(t_map)+1);
    (*map)->twod_map = NULL;
    (*map)->m_heigth = 1;
    (*map)->m_width = 0;
    (*map)->x_ypos.x = 0;
    (*map)->x_ypos.y = 0;
}

void    gameinit(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->moves = 0;
}

void    initboth(t_game *game)
{
    gameinit(&game);
    mapinit(&game->map);
    (*game).info.pexist = 0;
    (*game).info.cexist = 0;
    (*game).info.eexist = 0;
    
}