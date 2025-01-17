/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:55:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/17 20:24:12 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	execution(char **av)
{
	t_map		map;
	t_solong	game;

	ft_bzero(&map, sizeof(map));
	read_map(av[1], &map);
	ft_bzero(&game, sizeof(game));
	game.map = &map;
	game_start(&game);
	game_end(&game, 1);
	return (1);
}
