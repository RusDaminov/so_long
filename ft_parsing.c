/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:06:28 by abernita          #+#    #+#             */
/*   Updated: 2022/01/25 16:06:36 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd, int *f)
{
	char	*str;
	char	buf[2];
	int 	byte;

	str = ft_calloc(1, 1);
	if (!str)
		exit(0);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buf, 1);
		if (byte == -1)
			ft_error("Error reading file!\n");
		if (buf[0] == '\n' || byte == 0)
			break;
		if (!(ft_strchr("10CPE", buf[0])))
			ft_error("Wrong symbols!\n");
		str = ft_strjoin(str, buf);
	}
	if (byte == 0)
		*f = 0;
	return (str);
}

int		ft_count_map_lines(char *file)
{
	int		count_line;
	int 	fd;
	int		byte;
	char 	buf[2];

	fd = open(file, O_RDONLY);
	count_line = 0;
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buf, 1);
		if (buf[0] == '\n')
			count_line++;
	}
	if (byte == -1)
		ft_error("Error reading file\n");
	close(fd);
	return (count_line);
}

char	**ft_parsing(char *file)
{
    int 	count_line;
	int		fd;
	char 	**map;
	int 	f;
	int		i;

	count_line = ft_count_map_lines(file);
	f = 1;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char **) * (count_line + 1));
	if (!map)
		ft_error("Memory Error\n");
	i = -1;
	while (f)
		map[++i] = get_next_line(fd, &f);
	map[++i] = NULL;
	close(fd);
	return (map);
}
