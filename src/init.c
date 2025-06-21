/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:03:25 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/21 16:04:08 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_args(char **av, t_args *d)
{
	d->max_iter = 100;
	d->color_mode = 0;
	d->zoom = 1.0;
	if (strncmp(av[1], "mandelbrot", 10) == 0)
		d->type = MANDELBROT;
	else if (strncmp(av[1], "julia", 5) == 0)
		d->type = JULIA;
	else
		d->type = NONE;
}
