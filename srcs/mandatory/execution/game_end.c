/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:12:09 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/17 19:21:17 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	game_end(t_solong *game, int exit_status)
{
	int	i;

	if (!game)
		return ;
	if (game->map && game->map->game_map)
		ft_free_2d((void **)game->map->game_map);
	if (game->img)
	{
		i = 0;
		while (i < ENT_IMG)
		{
			if (game->img[i])
			{
				mlx_delete_image(game->windows, game->img[i]);
				i++;
			}
		}
		free(game->img);
	}
	if (game->windows)
		mlx_terminate(game->windows);
	exit(exit_status);
}
