/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:34:47 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/05 01:41:06 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_2d_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}