#include "../inc/so_long.h"


void    errorf(int error)
{
    if (error == 1)
        ft_putstr_fd("Error\nInvalid Arguments", 2);
    else if (error == 2)
        ft_putstr_fd("Error\nMap name is not correct", 2);
    else if (error == 3)
        ft_putstr_fd("Error\nEmpty line in the map.", 2);
    else if (error == 4)
        ft_putstr_fd("Map not found", 2);
    else if (error == 5)
        ft_putstr_fd("", 2);
    exit(1);

}