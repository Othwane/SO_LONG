#include "../inc/so_long.h"

void	argschecker(int argc, char **argv, t_game *game)
{
    if (*argv[ft_strlen(argv[1]) - 1] == 'r')
    {
        if (*argv[ft_strlen(argv[1]) - 2] == 'e')
        {
            if (*argv[ft_strlen(argv[1]) - 3] == 'b')
            {
                if(*argv[ft_strlen(argv[1]) - 4] == '.')
                    return ;
                errorf(2);
            }
            errorf(2);
        }
        errorf(2);

    }
    errorf(2);
    initstuff(argv, game);
}