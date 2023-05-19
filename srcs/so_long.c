#include "../inc/so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		errorf(1);


	argschecker(argc, argv, &game);
	initstuff(argv, &game);
	n_map(&game);
	// printf("%s\n", game.map[0]);
	// int i = 0;
	// if (game.map)
	// {
	// 	printf("There is a map\n");
	// }
	// while (game.map[i])
	// {
	// 	printf("ok\n");
	// 	// printf("%s", game.map[i++]);
	// }
	return (0);
}
