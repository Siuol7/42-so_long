/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:55:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/10 17:26:24 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int execution(char **av)
{
	t_map		map;
	t_solong	game;

	ft_bzero(&map, sizeof(map));
	read_map(av[1], &map);
	ft_bzero(&game, sizeof(game));
	game.map = &map;
	game_start(&game);
	ft_free_2d((void **)map.game_map);
	return (1);
}