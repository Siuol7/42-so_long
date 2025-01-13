/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:51:56 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/13 18:23:59 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	display(t_solong *game, mlx_image_t *img, int row, int col)
{
	if (mlx_image_to_window(game->windows, img, col * PIXEL, row * PIXEL) < 0)
		game_error(mlx_strerror(mlx_errno), game);
}

static void	display_obj(t_solong *game, int row, int col)
{
	while (++row < game->map->width)
	{
		col = -1;
		while (++col < game->map->length)
		{
			display(game, game->img[GR], row, col);
			if (game->map->game_map[row][col] == 'C')
				display(game, game->img[COL], row, col);
			else if (game->map->game_map[row][col] == '0')
				display(game, game->img[GR], row, col);
			else if (game->map->game_map[row][col] == 'E')
			{
				display(game, game->img[OG], row, col);
				display(game, game->img[CG], row, col);
			}
		}
	}
}

static void	display_wall(t_solong *game, int row, int col)
{
	while (++row < game->map->width)
	{
		col = -1;
		while (++col < game->map->length)
		{
			if ((row != 0 && row != game->map->width -1)
				&& col == 0)
				display(game, game->img[WL], row, col);
			else if ((row != 0 && row != game->map->width -1)
				&& col == game->map->length - 1)
				display(game, game->img[WR], row, col);
			else if ((col != 0 && col != game->map->length -1)
				&& row == 0)
				display(game, game->img[WT], row, col);
			else if ((col != 0 && col != game->map->length -1)
				&& row == game->map->width - 1)
				display(game, game->img[WB], row, col);
		}
	}
	row = game->map->width - 1;
	col = game->map->length - 1;
	display(game, game->img[W1], 0, 0);
	display(game, game->img[W2], 0, col);
	display(game, game->img[W3], row, 0);
	display(game, game->img[W4], row, col);
}

static void	display_extra(t_solong *game, int row, int col)
{
	while (++row < game->map->width)
	{
		col = -1;
		while (++col < game->map->length)
		{
			if ((row != 0 && row != game->map->width -1)
				&& (col != 0 && col != game->map->length - 1)
				&& game->map->game_map[row][col] == '1')
				display(game, game->img[OBS], row, col);
		}
	}
	display(game, game->img[CH], game->cur.x, game->cur.y);
}

void	display_img_to_windows(t_solong *game)
{
	display_obj(game, -1, -1);
	display_wall(game, -1, -1);
	display_extra(game, -1, -1);
}
