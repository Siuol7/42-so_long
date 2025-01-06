/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:07:11 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/06 16:59:38 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	find_path(t_map *map, t_queue *q, char **visited, int i)
{
	t_point		cur;
	t_point		new;
	t_dimension	*d;

	assign_dimension(d);
	while (isEmpty(q))
	{
		i = -1;
		cur = dequeue(q);
		while (++i < 4)
		{
			new.x = cur.x + d->dx[i];
			new.y = cur.y + d->dy[i];
		}
		if (map->game_map[new.x][new.y] != '1' && visited[new.x][new.y] != 1)
		{
			if (new.x == map->end.x && new.y == map->end.y)
				return (1);
			enqueue(q, new);
		}
	}
	return (0);
}

t_queue *create_queue(int32_t size)
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
	return (q);
}

int	BFS(t_map *map, int32_t width, int32_t length)
{
	t_queue		*q;
	int			i;
	int			**visited;

	i = 0;
	q = create_queue(map->length * map->width);
	if (!q)
		memory_error(0, "Error\n Not enough memory", map);
	visited = malloc(width * sizeof(int *));
	while (i < width)
		visited = malloc(length);
	visited[map->start.x][map->start.y] = 1;
	enqueue(q, map->start);
	if (find_path(map, q, visited, -1))
		return (1);
	return (0);
}
