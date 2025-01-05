/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 03:07:32 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/05 16:39:55 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	file_validation(char *map_file, int32_t *fd)
{
	int32_t	len;

	*fd = (int32_t)open(map_file, O_RDONLY);
	if (fd < 0)
		map_file_error(0, "Error:\n Opening file failed", *fd);
	len = (int32_t)ft_strlen(map_file);
	if (len == 0 || map_file[len - 4] != '.' || map_file[len - 3] != 'b'
		|| map_file[len - 2] != 'e' || map_file[len - 1] != 'r')
			map_file_error(0, "Error:\nRequired .ber file", *fd);
}

void	character_count(t_map *map)
{
	int32_t	row;
	int32_t	col;

	row = 0;
	while (row < map->width)
	{
		col = 0;
		while (col < map->length)
		{
			if (map->game_map[row][col] == '1')
				map->char_1++;
			else if (map->game_map[row][col] == '0')
				map->char_0++;
			else if (map->game_map[row][col] == 'E')
				map->char_E++;
			else if (map->game_map[row][col] == 'P')
				map->char_P++;
			else if (map->game_map[row][col] == 'C')
				map->char_C++;
			else
				game_map_error(0, "Error:\nInvalid character", map);
			col++;
		}
		row++;
	}
}
