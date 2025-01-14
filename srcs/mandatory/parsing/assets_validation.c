/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:32:43 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/14 18:51:39 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	png_src_error(int32_t status, const char *png_src,
						int32_t fd)
{
	ft_printf_fd(2, "Error:\nBroken path:%s\n", png_src);
	close(fd);
	exit(status);
}

static void	access_check(const char *png_src)
{
	int	fd;

	fd = open(png_src, O_RDONLY);
	if (fd < 0)
		png_src_error(0, png_src, fd);
}

void	assets_validation(void)
{
	access_check(WALL1);
	access_check(WALL2);
	access_check(WALL3);
	access_check(WALL4);
	access_check(WALLL);
	access_check(WALLR);
	access_check(WALLT);
	access_check(WALLB);
	access_check(GROUND);
	access_check(CHARACTER);
	access_check(OPENED_GATE);
	access_check(CLOSED_GATE);
	access_check(COLLECTIBLES);
	access_check(OBSTACLES);
}
