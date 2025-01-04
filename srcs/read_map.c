/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:28:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/05 01:24:49 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	get_map_1d(int fd, t_map *map)
{
	char	line[BUFFER_SIZE];
	int		readbytes;

	readbytes = read(fd, line, BUFFER_SIZE);
	if (readbytes < 0)
		ft_printf_fd(2, "Error\n Reading map failed\n");
	else if (readbytes == 0)
		ft_printf_fd(2, "Error\n Empty map\n");
	else if (readbytes > BUFFER_SIZE - 1)
		ft_printf_fd(2, "Error\n Not support this resolution\n");
	line[readbytes] = '\0';
	map->game_map = ft_split(line, '\n');
	if (!map->game_map || !*map->game_map)
		game_map_error();
	
}

void	read_map(char *map_name, t_map *map)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	// if (fd < 2)
	// 	readmap_error();
	get_map_1d(fd, map);
}