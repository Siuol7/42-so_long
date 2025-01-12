/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:55:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/12 13:15:17 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int execution(char **av)
{
	t_map		map;
	t_solong	game;
	int	i;
	int	j;

	ft_bzero(&map, sizeof(map));
	read_map(av[1], &map);
	ft_bzero(&game, sizeof(game));
	game.map = &map;
	i = -1;
	while (++i < map.width)
	{
		j = -1;
		while (++j < map.length)
		{
			ft_printf_fd(1, "x:%dy:%d--%c\n", i, j, map.game_map[i][j]);
		}
	}
	i = -1;
	while (++i < map.width)
	{
		j = -1;
		while (++j < map.length)
		{
			ft_printf_fd(1, "%c", map.game_map[i][j]);
		}
		ft_printf_fd(1,"\n");
	}
	// game_start(&game);
	// game_end(&game, 1);
	ft_free_2d((void **)map.game_map);
	return (1);
}