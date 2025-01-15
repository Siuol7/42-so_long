/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:57:42 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/15 20:15:27 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	valid_path_validation(t_map *map)
{
	if (!bfs(map, map->width, map->length))
		path_error(0, "Error:\nNo path to exit\n", map);
}

static void	wall_border_validation(t_map *map)
{
	int32_t	row;
	int32_t	col;

	row = 1;
	while (row - 1 < map->width)
	{
		col = -1;
		while (++col < map->length)
		{
			if (map->game_map[row - 1][col] != '1')
				game_map_error(0, "Error:\nInvalid border\n", map);
		}
		row += (map->width - 1);
	}
	col = 1;
	while (col - 1 < map->length)
	{
		row = -1;
		while (++row < map->width)
		{
			if (map->game_map[row][col - 1] != '1')
				game_map_error(0, "Error:\nInvalid border\n", map);
		}
		col += (map->length - 1);
	}
}

static void	character_validation(t_map *map)
{
	character_count(map, -1);
	if (map->char_p != 1)
		game_map_error(0, "Error:\nInvalid number of players\n", map);
	if (map->char_e != 1)
		game_map_error(0, "Error:\nInvalid number of exits\n", map);
	if (map->char_c < 1)
		game_map_error(0, "Error:\nNo collectibles\n", map);
}

static void	shape_validation(t_map *map)
{
	int32_t	i;
	int32_t	temp;

	i = 1;
	temp = (int32_t)ft_strlen(map->game_map[0]);
	while (map->game_map[i])
	{
		if (temp != (int32_t)ft_strlen(map->game_map[i]))
			game_map_error(0, "Error:\nMap is not rectangular shape.\n", map);
		temp = (int32_t)ft_strlen(map->game_map[i]);
		i++;
	}
	map->length = ft_strlen(map->game_map[0]);
	if (map->length > WINDOW_LENGTH)
		game_map_error(0, "Error:\nNot support this resolution\n", map);
	map->width = ft_2d_size(map->game_map);
	if (map->width > WINDOW_WIDTH)
		game_map_error(0, "Error:\nNot support this resolution\n", map);
}

void	map_validation(t_map *map)
{
	shape_validation(map);
	character_validation(map);
	wall_border_validation(map);
	valid_path_validation(map);
}
