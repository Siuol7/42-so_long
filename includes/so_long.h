/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:56:04 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/06 17:19:50 by caonguye         ###   ########.fr       */
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

typedef struct s_point
{
	int32_t	x;
	int32_t	y;
}	t_point;

typedef	struct s_queue
{
	t_point	*data;
	int32_t	top;
	int32_t	bottom;
	int32_t	size;
}	t_queue;

typedef struct s_dimension
{
	int	dy[4];
	int	dx[4];
}	t_dimension;

typedef struct s_map
{
	char		**game_map;
	t_point		start;
	t_point		end;
	int32_t		length;
	int32_t		width;
	int32_t		char_1;
	int32_t		char_0;
	int32_t		char_E;
	int32_t		char_P;
	int32_t		char_C;
}	t_map;

//Utilities
int 	execution(char **av);

//PARSING
//read_map
void	read_map(char *map_file, t_map *map);

//map_validation
void		map_validation(t_map *map);

//utils
void	character_count(t_map *map);
void	file_validation(char *map_file, int *fd);

//BFS
void	enqueue(t_queue *q, t_point point);
t_point	dequeue(t_queue *q);
int		isEmpty(t_queue *q);
void	assign_dimension(t_dimension *d);
int		BFS(t_map *map, int32_t width, int32_t length);
t_queue *create_queue(int32_t size);

//ERROR_HANDLING
void	game_map_error(int32_t status, char *msg, t_map *map);
void	map_file_error(int32_t status, char *msg, int32_t fd);
void	path_error(int32_t status, char *msg, t_map *map);
void	memory_error(int32_t status, char *msg, t_map *map);

#endif