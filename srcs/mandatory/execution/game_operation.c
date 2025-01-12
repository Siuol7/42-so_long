/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:24:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/12 18:05:36 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	game_done(void *param)
{
	game_end((t_solong *)param, 1);
}

int	game_start(t_solong *game)
{
	(void)game;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game->windows = mlx_init(game->map->length * pixel
		, game->map->width * pixel, "abc", 1);
	game->cur = game->map->start;
	graphic(game);
	display_img_to_windows(game);
	mlx_key_hook(game->windows, game_control, game);
	mlx_close_hook(game->windows, game_done, game);
	mlx_loop(game->windows);
	game_end(game, 1);
	return (0);
}
