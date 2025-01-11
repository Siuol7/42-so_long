/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:24:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/10 20:38:04 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	game_start(t_solong *game)
{
	(void)game;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game->windows = mlx_init(game->map->width * pixel, game->map->length * pixel
		,"abc", 1);
	graphic(game);
	mlx_loop(game->windows);
	return (0);
}