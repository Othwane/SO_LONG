#include "../inc/so_long.h"

int	checkfandc(int argc, char *argv)
{
	char *suf;

	suf = ".ber";
	if (argc != 2)
			return (1);
	while (*argv)
	{
		if (*argv == '.')
		{
			while((*argv || *suf) && *argv == *suf)
			{
				argv++;
				suf++;
			}
			if (*argv == '\0' && *suf == '\0')
				return (1);
		}
		argv++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_game game;
	int	fd;
	
	if (!checkfandc(argc, argv[1]))
		return (1);
	initboth(&game);
	fd = open(argv[1], O_RDONLY);
	
}

