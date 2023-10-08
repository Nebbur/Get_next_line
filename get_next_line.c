/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboia-pe <rboia-pe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:19:58 by rboia-pe          #+#    #+#             */
/*   Updated: 2023/04/07 02:19:58 by rboia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (buf[0] || read(fd, &buf, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buf);
		if (ft_strlen(buf) == 0)
			break ;
		if (ft_isolate_line(buf) == 1)
			break ;
		if (read(fd, &buf, 0) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}

int	main(int ac, char **av)
{
	char	*line;
	int		i;
	int		fd;
	int		fd1;

	fd1 = open("tests/test.txt", O_RDONLY);
	i = 1;
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	while (i < 12)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	puts("\n");
	if (ac > 1)
		close(fd);
	close(fd1);
	return (0);
}