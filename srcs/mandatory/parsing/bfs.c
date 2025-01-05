/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:07:11 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/05 23:34:54 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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

int	bfs(t_map *map)
{
	t_queue	*q;
	int		dx[4] = {0, 0, -1, 1};
	int		dy[4] = {-1, 1, 0, 0};
	int		visited[map->width][map->length];

	q = create_queue(map->length * map->width);
	if (!q)
		memory_error(0, "Error\n Not enough memory", map);
	

}
