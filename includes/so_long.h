/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:56:04 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/05 02:16:24 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/libft/libft.h"
# include "../library/ft_printf_fd/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
//#include "MLX42.h"

//Resolution 4k
# define pixel 64

//windowlength 3840/64
# define window_length 60

//windowwidth 2160/64
# define window_width 34

# define BUFFER_SIZE 2041

typedef struct s_map
{
	char		**game_map;
	int32_t		length;
	int32_t		width;
}	t_map;

#endif