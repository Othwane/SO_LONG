#include "../inc/so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		errorf(1);
	else
	{
		argschecker(argc, argv, &game);
		readmap(&game);

	}
	return (0);
}
