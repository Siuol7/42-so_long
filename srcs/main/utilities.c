/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:55:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/10 13:34:35 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int execution(char **av)
{
	t_map	map;

	ft_bzero(&map, sizeof(map));
	read_map(av[1], &map);

	ft_free_3d((void ***)map.game_map);
	return (0);
}