/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:17:06 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/15 22:28:30 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	got_collectible(t_solong *game)
{
	int32_t	i;

	i = 0;
	while (i < game->map->char_c)
	{
		if (game->img[COL]->instances[i].y == game->cur.x * PIXEL
			&& game->img[COL]->instances[i].x == game->cur.y * PIXEL)
		{
			game->img[COL]->instances[i].enabled = false;
			game->collectibles++;
			break ;
		}
		i++;
	}
}

static void	play(t_solong *game)
{
	game->cur = game->next;
	ft_printf_fd(1, "Current number of movements:%d\n", ++game->move);
	if (game->map->game_map[game->cur.x][game->cur.y] == 'C')
	{
		game->map->game_map[game->cur.x][game->cur.y] = '0';
		got_collectible(game);
		if (game->collectibles == game->map->char_c)
			game->img[CG]->instances[0].enabled = false;
	}
	else if (game->map->game_map[game->cur.x][game->cur.y] == 'E'
		&& game->collectibles == game->map->char_c)
	{
		ft_printf_fd(1, "You win!\n");
		game_end(game, 1);
	}
	game->img[CH]->instances[0].x = game->cur.y * PIXEL;
	game->img[CH]->instances[0].y = game->cur.x * PIXEL;
}

void	game_control(mlx_key_data_t keypress, void *param)
{
	t_solong	*game;

	game = (t_solong *)param;
	if (keypress.action == MLX_PRESS || keypress.action == MLX_REPEAT)
	{
		if (keypress.key == MLX_KEY_ESCAPE)
			game_end(game, 1);
		if (keypress.key == MLX_KEY_UP || keypress.key == MLX_KEY_W)
			game->next = (t_point){game->cur.x - 1, game->cur.y};
		else if (keypress.key == MLX_KEY_DOWN || keypress.key == MLX_KEY_S)
			game->next = (t_point){game->cur.x + 1, game->cur.y};
		else if (keypress.key == MLX_KEY_LEFT || keypress.key == MLX_KEY_A)
			game->next = (t_point){game->cur.x, game->cur.y -1};
		else if (keypress.key == MLX_KEY_RIGHT || keypress.key == MLX_KEY_D)
			game->next = (t_point){game->cur.x, game->cur.y + 1};
		else
			return ;
		if (game->map->game_map[game->next.x][game->next.y] != '1')
			play(game);
	}
}
