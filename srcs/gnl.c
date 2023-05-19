#include "../inc/so_long.h"

char	*ft_read_ln(int fd, char *line)
{
	int		readed;
	char	*buffer;
	char	*second;

	buffer = malloc(BUFFER_SIZE + 1);
	buffer[0] = 0;
	readed = 1;
	while (readed > 0 && !searchr(buffer, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		buffer[readed] = '\0';
		second = stringjoin(line, buffer);
		free(line);
		line = second;
	}
	free(buffer);
	return (line);
}

char	*ft_until_nl(char *string)
{
	int		i;
	int		ii;
	char	*line;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	ii = 0;
	line = malloc(i + 1);
	while (ii < i)
	{
		line[ii] = string[ii];
		ii++;
	}
	line[ii] = '\0';
	return (line);
}

char	*ft_after_nl(char *string)
{
	int		i;
	int		ii;
	char	*line;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	line = malloc(slength(string) - i + 1);
	ii = 0;
	while (string[i])
	{
		line[ii] = string[i];
		i++;
		ii++;
	}
	line[ii] = '\0';
	free(string);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*rest;

	if (fd < 0 || fd == 1 || fd == 2 || read(fd, 0, 0) < 0)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = ft_read_ln(fd, line);
	if (line == NULL)
		return (NULL);
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	rest = ft_until_nl(line);
	line = ft_after_nl(line);
	return (rest);
}