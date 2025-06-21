/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:03:25 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/21 17:41:44 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_parse_args(int ac, char **av, t_args *d)
{
	int	i;

	d->max_iter = 100;
	d->color_mode = 0;
	d->zoom = 1.0;
	if (strncmp(av[1], "mandelbrot", 10) == 0)
		d->type = MANDELBROT;
	else if (strncmp(av[1], "julia", 5) == 0)
		d->type = JULIA;
	else
		return (0);
	if ((d->type == MANDELBROT && ac > 5) || (d->type == JULIA && ac > 7))
    		return (0);
	i = 2;
	while (i < ac)
	{
		if (!is_number(av[i]))
			return (0);
		i++;
	}
	if (!parse_check_args(ac, av, d))
		return (0);
	return (1);
}
