#include "../inc/so_long.h"


void    errorf(int error)
{
    if (error == 1)
        ft_putstr_fd("Invalid Arguments\n", 2);
    else if (error == 2)
        ft_putstr_fd("Map name is not correct\n", 2);
    else if (error == 3)
        ft_putstr_fd("Empty line in the \n.", 2);
    else if (error == 4)
        ft_putstr_fd("Map not found\n", 2);
    else if (error == 5)
        ft_putstr_fd("thiserrorfornow", 2);
    exit(1);

}