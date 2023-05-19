#include "../inc/so_long.h"

void	argschecker(int argc, char **argv, t_game *game)
{
    int fd;

    if (argv[1][ft_strlen(argv[1]) - 1] == 'r')
    {
        if (argv[1][ft_strlen(argv[1]) - 2] == 'e')
        {
            if (argv[1][ft_strlen(argv[1]) - 3] == 'b')
            {
                if(argv[1][ft_strlen(argv[1]) - 4] == '.')
                {
                    fd = open(argv[1], O_RDONLY);
                    if (fd == -1)
                        errorf(2);
                    close(fd);
                    return ;
                }
                errorf(2);
            }
            errorf(2);
        }
        errorf(2);
    }
    errorf(2);
}