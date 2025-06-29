/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:03:25 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/27 12:47:41 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_parse_args(int ac, char **av, t_args *args)
{
	int	i;

	args->max_iter = 100;
	args->color_mode = 0;
	args->zoom = 5.0;
	if (strncmp(av[1], "mandelbrot", 10) == 0)
		args->type = MANDELBROT;
	else if (strncmp(av[1], "julia", 5) == 0)
		args->type = JULIA;
	else
		return (0);
	if ((args->type == MANDELBROT && ac > 5) || 
		(args->type == JULIA && ac > 7))
    		return (0);
	i = 2;
	while (i < ac)
	{
		if (!is_number(av[i]))
			return (0);
		i++;
	}
	if (!parse_check_args(ac, av, args))
		return (0);
	return (1);
}
