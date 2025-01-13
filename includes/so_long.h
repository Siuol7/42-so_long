/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:56:04 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/13 19:27:03 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/libft/libft.h"
# include "../library/ft_printf_fd/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "MLX42.h"

//Resolution 4k
# define PIXEL 64

//windowlength 3840/64
# define WINDOW_LENGTH 60

//windowwidth 2160/64
# define WINDOW_WIDTH 34

# define BUFFER_SIZE 2041

# define ENT_IMG 14

//Wall and Ground
# define WALL1 "game_assets/wall/w1.png"
# define WALL2 "game_assets/wall/w2.png"
# define WALL3 "game_assets/wall/w3.png"
# define WALL4 "game_assets/wall/w4.png"
# define WALLL "game_assets/wall/left.png"
# define WALLR "game_assets/wall/right.png"
# define WALLT "game_assets/wall/top.png"
# define WALLB "game_assets/wall/bottom.png"
# define GROUND "game_assets/wall/ground.png"

//Character
# define CHARACTER "game_assets/character/character.png"

//Objects
# define OPENED_GATE "game_assets/objects/gate/open.png"
# define CLOSED_GATE "game_assets/objects/gate/close.png"
# define COLLECTIBLES "game_assets/objects/Collectibles/soul.png"
# define OBSTACLES	"game_assets/wall/obstacles.png"

typedef struct s_point
{
	int32_t	x;
	int32_t	y;
}	t_point;

typedef enum game_entities
{
	W1,
	W2,
	W3,
	W4,
	WL,
	WR,
	WT,
	WB,
	GR,
	CH,
	OG,
	CG,
	COL,
	OBS,
}	t_game_entities;

typedef struct s_queue
{
	t_point	*data;
	int32_t	top;
	int32_t	bottom;
	int32_t	size;
	int32_t	collec;
	int32_t	exit;
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
	int32_t		char_e;
	int32_t		char_p;
	int32_t		char_c;
}	t_map;

typedef struct s_solong
{
	mlx_t		*windows;
	mlx_image_t	**img;
	t_map		*map;
	int32_t		move;
	int32_t		collectibles;
	t_point		cur;
	t_point		next;

}	t_solong;

//Utilities
int32_t	execution(char **av);

//PARSING
//read_map
void	read_map(char *map_file, t_map *map);

//map_validation
void	map_validation(t_map *map);

//utils
void	character_count(t_map *map, int32_t row);
void	file_validation(char *map_file, int32_t *fd);

//bfs
void	enqueue(t_queue *q, t_point point);
t_point	dequeue(t_queue *q);
int32_t	is_empty(t_queue *q);
void	assign_dimension(t_dimension *d);
int32_t	bfs(t_map *map, int32_t width, int32_t length);
t_queue	*create_queue(int32_t size);
void	ft_free_queue(t_queue *q, t_dimension *d, int32_t **visited, t_map *map);

//ERROR_HANDLING
void	game_map_error(int32_t status, char *msg, t_map *map);
void	map_file_error(int32_t status, char *msg, int32_t fd);
void	path_error(int32_t status, char *msg, t_map *map);
void	memory_error(int32_t status, char *msg, t_map *map);

//EXECUTION
int		game_start(t_solong *game);
void	graphic(t_solong *game);
void	display_img_to_windows(t_solong *game);
void	game_control(mlx_key_data_t keypress, void *param);
void	game_end(t_solong *game, int exit_status);
void	game_error(const char *msg, t_solong *game);

#endif