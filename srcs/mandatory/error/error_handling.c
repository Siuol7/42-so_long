/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 04:17:05 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/06 17:20:43 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	game_map_error(int32_t status, char *msg, t_map *map)
{
	ft_printf_fd(2, "%s", msg);
	(void)map;
	//map_clear(map);
	exit(status);
}

void	map_file_error(int32_t status, char *msg, int32_t fd)
{
	ft_printf_fd(2, "%s", msg);
	close(fd);
	exit(status);
}

void	path_error(int32_t status, char *msg, t_map *map)
{
	(void)map;
	ft_printf_fd(2, "%s", msg);
	exit(status);
}

void	memory_error(int32_t status, char *msg, t_map *map)
{
	(void)map;
	ft_printf_fd(2, "%s", msg);
	exit(status);
}
