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
    if(cf_line(game) || cm_lines(game) || cl_line(game))
        errorf(2);
    // while ()
    // {
    //     /* code */
    // }
    
}

// void mapchecker(void)
// {
//     printf("here2");
//     // check_walls(mapfd);
// }