/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:07:11 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/14 17:59:41 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	move_in_graph(t_map *map, t_queue *q
							, int32_t **visited, t_point new)
{
	if (new.x > 0 && new.x < map->width -1
		&& new.y > 0 && new.y < map->length -1
		&& visited[new.x][new.y] == 0
		&& map->game_map[new.x][new.y] != '1')
	{
		if (new.x == map->end.x && new.y == map->end.y)
			q->exit++;
		else if (map->game_map[new.x][new.y] == 'C')
			q->collec++;
		visited[new.x][new.y] = 1;
		enqueue(q, new);
	}
}

static int32_t	find_path(t_map *map, t_queue *q
							, int32_t **visited, t_dimension *d)
{
	t_point		cur;
	t_point		new;
	int32_t		i;

	assign_dimension(d);
	while (!is_empty(q))
	{
		i = -1;
		cur = dequeue(q);
		while (++i < 4)
		{
			new.x = cur.x + d->dx[i];
			new.y = cur.y + d->dy[i];
			move_in_graph(map, q, visited, new);
		}
	}
	if (q->collec == map->char_c && q->exit == 1)
		return (1);
	else if (q->collec != map->char_c)
	{
		ft_free_queue(q, d, visited, map);
		path_error(0, "Error:\nNo path to collectibles\n", map);
	}
	return (0);
}

t_queue	*create_queue(int32_t size)
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	if (!q)
		return (NULL);
	q->data = malloc(size * sizeof(t_point));
	if (!q->data)
		return (NULL);
	q->top = 0;
	q->bottom = 0;
	q->size = size;
	q->collec = 0;
	q->exit = 0;
	return (q);
}

static void	visited_generating(int32_t **visited,
			int32_t width, int32_t length, t_map *map)
{
	int32_t	i;

	i = -1;
	while (++i < width)
	{
		visited[i] = (int32_t *)malloc(length * sizeof(int32_t));
		if (!visited[i])
			memory_error(0, "Error:\n Not enough memory\n", map);
		ft_bzero(visited[i], length * sizeof(int32_t));
	}
	visited[map->start.x][map->start.y] = 1;
}

int32_t	bfs(t_map *map, int32_t width, int32_t length)
{
	t_queue		*q;
	t_dimension	*d;
	int32_t		i;
	int32_t		**visited;

	i = -1;
	d = malloc(sizeof(t_dimension));
	if (!d)
		memory_error(0, "Error:\n Not enough memory\n", map);
	q = create_queue(map->length * map->width);
	if (!q)
		memory_error(0, "Error:\n Not enough memory\n", map);
	visited = (int32_t **)malloc(width * sizeof(int32_t *));
	if (!visited)
		memory_error(0, "Error:\n Not enough memory\n", map);
	visited_generating(visited, width, length, map);
	enqueue(q, map->start);
	i = (find_path(map, q, visited, d));
	ft_free_queue(q, d, visited, map);
	return (i);
}
