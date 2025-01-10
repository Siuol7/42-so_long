/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:55:42 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/09 08:45:28 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf_fd(2, "Error:\nWrong input!\nInput as follow: ./so_long <map_file>.ber.");

	}
	if (!execution(av))
	{
		ft_printf_fd(2, "Error:\nStarting game failed");
		exit(0);
	}
	exit(1);
}