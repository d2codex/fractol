/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:30:22 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/21 17:26:35 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

int	main(int ac, char **av)
{
	t_args	d;

	if (ac < 2)
		werror_exit("Not enough arguments\n");
	if (!init_parse_args(ac, av, &d))
		werror_exit("Error\n");
	return (0);
}
