#include "../inc/so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		errorf(1);


	argschecker(argv);
	initstuff(argv, &game);
	readmap(&game);
	


	//int i = 0;
	//if (game.map)
	//{
	//	printf("There is a map\n");
	//}
	//while (game.map[i])
	//{
	//	printf("%s", game.map[i++]);
	//}
	//return (0);
}
