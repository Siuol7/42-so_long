/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 03:07:32 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/14 18:32:28 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	file_validation(char *map_file, int32_t *fd)
{
	int32_t	len;

	*fd = (int32_t)open(map_file, O_RDONLY);
	if (fd < 0)
		map_file_error(0, "Error:\n Opening file failed\n", *fd);
	len = (int32_t)ft_strlen(map_file);
	if (len < 4 || map_file[len - 4] != '.' || map_file[len - 3] != 'b'
		|| map_file[len - 2] != 'e' || map_file[len - 1] != 'r')
		map_file_error(0, "Error:\nRequired .ber file\n", *fd);
}

static void	assign_position(t_point *point, int32_t row, int32_t col)
{
	point->x = row;
	point->y = col;
}

void	character_count(t_map *map, int32_t row)
{
	int32_t	col;

	while (++row < map->width)
	{
		col = -1;
		while (++col < map->length)
		{
			if (map->game_map[row][col] == '0')
				map->char_0++;
			else if (map->game_map[row][col] == 'E')
			{
				map->char_e++;
				assign_position(&map->end, row, col);
			}
			else if (map->game_map[row][col] == 'P')
			{
				map->char_p++;
				assign_position(&map->start, row, col);
			}
			else if (map->game_map[row][col] == 'C')
				map->char_c++;
			else if (map->game_map[row][col] != '1')
				game_map_error(0, "Error:\nInvalid character\n", map);
		}
	}
}
