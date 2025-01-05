/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:57:42 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/05 03:46:47 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	wall_border_validation(t_map *map)
{
	int32_t	row;
	int32_t	col;

	row = 0;
	while (row < map->width)
	{
		col = -1;
		while (++col < map->length)
		{
			if (map->game_map[row][col] != 1)
				game_map_error(0, "Error\n Invalid boder");
		}
		row += (map->width - 1);
	}
	col = 0;
	while (col < map->length)
	{
		row = -1;
		while (++row < map->length)
		{
			if (map->game_map[row][col] != 1)
				game_map_error(0, "Error\n Invalid boder");
		}
		col += (map->length - 1);
	}
}

void	character_validation(t_map *map)
{
	character_count(map);
	if	(map->char_1 != (map->length + map->width) * 2)
		game_map_error(0, "Error\n Invalid border");
	else if (map->char_P != 1)
		game_map_error(0, "Error\n Invalid number of players");
	else if (map->char_E != 1)
		game_map_error(0, "Error\n Invalid number of exits");
	else if (map->char_C < 1)
		game_map_error(0, "Error\n No collectibles");
	else if (map->char_0 == 0)
		game_map_error(0, "Error\n No path");
}

void	shape_validation(t_map *map)
{
	int32_t	i;
	int32_t	temp;

	i = 1;
	temp = ft_strlen(map->game_map[0]);
	while (map->game_map[i])
	{
		if (temp != map->game_map[i])
			game_map_error(0, "Error\n Map is not rectangular shape.");
		temp = map->game_map[i];
		i++;
	}
	map->length = ft_strlen(map->game_map[0]);
	map->width = ft_2d_size(map->game_map);
}

int	map_validation(t_map *map)
{
	shape_validation(map);
	character_validation(map);
	wall_border_validation(map);
	valid_path_validation(map);
}