/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:38:20 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/14 18:51:59 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static mlx_image_t	*graphic_parse(t_solong *game, const char *png_src)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(png_src);
	if (!texture)
		game_error(mlx_strerror(mlx_errno), game);
	image = mlx_texture_to_image(game->windows, texture);
	mlx_delete_texture(texture);
	if (!image)
		game_error(mlx_strerror(mlx_errno), game);
	if (!mlx_resize_image(image, PIXEL, PIXEL))
		game_error(mlx_strerror(mlx_errno), game);
	return (image);
}

void	graphic(t_solong *game)
{
	game->img = ft_calloc(ENT_IMG + 1, sizeof(mlx_image_t));
	if (!game->img)
		game_error(mlx_strerror(mlx_errno), game);
	game->img[W1] = graphic_parse(game, WALL1);
	game->img[W2] = graphic_parse(game, WALL2);
	game->img[W3] = graphic_parse(game, WALL3);
	game->img[W4] = graphic_parse(game, WALL4);
	game->img[WL] = graphic_parse(game, WALLL);
	game->img[WR] = graphic_parse(game, WALLR);
	game->img[WT] = graphic_parse(game, WALLT);
	game->img[WB] = graphic_parse(game, WALLB);
	game->img[GR] = graphic_parse(game, GROUND);
	game->img[CH] = graphic_parse(game, CHARACTER);
	game->img[OG] = graphic_parse(game, OPENED_GATE);
	game->img[CG] = graphic_parse(game, CLOSED_GATE);
	game->img[COL] = graphic_parse(game, COLLECTIBLES);
	game->img[OBS] = graphic_parse(game, OBSTACLES);
}
