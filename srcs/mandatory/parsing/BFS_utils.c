/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:51:28 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/06 17:20:18 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	enqueue(t_queue *q, t_point point)
{
	q->data[q->bottom++] = point;
}

t_point	dequeue(t_queue *q)
{
	return	q->data[q->top++];
}

int		isEmpty(t_queue *q)
{
	if (q->top == q->bottom)
		return (1);
	return (0);
}

void	assign_dimension(t_dimension *d)
{
	d->dx[0] = 0;
	d->dx[1] = 0;
	d->dx[2] = -1;
	d->dx[3] = 1;
	d->dy[0] = -1;
	d->dy[1] = 1;
	d->dy[2] = 0;
	d->dy[3] = 0;
}
