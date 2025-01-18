/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:28:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/17 20:38:33 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	get_map(int fd, t_map *map)
{
	char		line[BUFFER_SIZE];
	int32_t		line_no;
	int32_t		readbytes;

	readbytes = read(fd, line, BUFFER_SIZE + 1);
	if (readbytes < 0)
		map_file_error(0, "Error:\nReading map failed\n", fd);
	else if (readbytes == 0)
		map_file_error(0, "Error:\nEmpty map\n", fd);
	else if (readbytes > BUFFER_SIZE)
		map_file_error(0, "Error:\nNot support this resolution\n", fd);
	line[readbytes] = '\0';
	line_no = (int32_t)ft_char_cnt_2d(line, '\n');
	close(fd);
	map->game_map = ft_split(line, '\n');
	if (!map->game_map || !*map->game_map)
		game_map_error(0, "Error:\nGenerating map failed\n", map);
	if (line_no + 1 != ft_2d_size(map->game_map))
	{
		ft_printf_fd(2, "Error:\nMap is not rectangular shape.\n");
		ft_free_2d((void **)map->game_map);
		exit(0);
	}
}

void	read_map(char *map_file, t_map *map)
{
	int32_t	fd;

	assets_validation();
	file_validation(map_file, &fd);
	get_map(fd, map);
	map_validation(map);
}
