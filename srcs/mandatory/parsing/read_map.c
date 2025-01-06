/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:28:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/06 17:01:41 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	get_map(int fd, t_map *map)
{
	char		line[BUFFER_SIZE];
	int32_t		readbytes;

	readbytes = read(fd, line, BUFFER_SIZE);
	if (readbytes < 0)
		ft_printf_fd(2, "Error:\nReading map failed\n");
	else if (readbytes == 0)
		ft_printf_fd(2, "Error\n Empty map\n");
	else if (readbytes > BUFFER_SIZE - 1)
		ft_printf_fd(2, "Error:\nNot support this resolution\n");
	line[readbytes] = '\0';
	map->game_map = ft_split(line, '\n');
	if (!map->game_map || !*map->game_map)
		game_map_error(0, "Error:\nGenerating map failed", map);
}

void	read_map(char *map_file, t_map *map)
{
	int32_t	fd;

	file_validation(map_file, &fd);
	get_map(fd, map);
	map_validation(map);
}