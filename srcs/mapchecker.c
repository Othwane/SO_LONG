#include "../inc/so_long.h"

int    cf_line(t_game *game)
{
    int i;
    char *buff;

    i = 0;
    game->mapfd = open(game->mapname, O_RDONLY);
    buff = get_next_line(game->mapfd);
    while (buff[i] != '\n')
    {
        if (buff[i] != 49)
            return (1);
        i++;
    }
    return (0);
}

int    cm_lines(t_game *game)
{
    int lines;

    lines = game->l_inmap - 2;
    while (lines > 0)
    {

        if (!(game->map[lines][0] == 49 && game->map[lines][game->c_inmap - 2] == 49))
            return (1);
        lines--;
    }
    return (0);
}

int    cl_line(t_game *game)
{
    int i;

    i = 0;
    while (game->map[game->l_inmap - 1][i])
    {
        if (!(game->map[game->l_inmap - 1][i] == 49))
            return (1);
        i++;
    }
    return (0);
}

void check_walls(t_game *game)
{
    int i = 0;
    int x;

    x = ft_strlen(game->map[game->l_inmap - 1]) + 1;
    if(cf_line(game) || cm_lines(game) || cl_line(game))
        errorf(6);
    while (game->l_inmap - 1 > i)
    {
        if (!(ft_strlen(game->map[i]) == x))
            errorf(6);
        i++;
    }
}

void    check_pce(t_game *game)
{
    int i = 0;
    int ii;
    while (game->map[i])
    {
        ii = 0;
        while (game->map[i][ii] != '\n')
        {
            if (game->map[i][ii] == 'P')
                {
                    game->player--;
                    game->y_player= i;
                    game->x_player = ii;
                }
            if (game->map[i][ii] == 'C' && game->collects > 0)
                game->collects--;
            if (game->map[i][ii] == 'E')
                {
                    game->exit--;
                    game->y_exit = i;
                    game->x_exit = ii;
                }
            ii++;
        }
        i++;
    }
    if (game->player != 0 || game->collects != 0 || game->exit != 0)
        errorf(7);
}

void mapchecker(t_game *game)
{
    check_walls(game);
    check_pce(game);
    
    printf("%d %d, %d %d.", game->y_player, game->x_player, game->y_exit, game->x_exit);
}