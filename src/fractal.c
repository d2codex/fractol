/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:03:19 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/29 11:59:39 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_mandelbrot(double x0, double y0, int max_iter)
{
	double	x;
	double	y;
	double	xtemp;
	int	i;
	
	x = 0;
	y = 0;
	i = 0;
	while ((x * x) + (y * y) <= 4 && i < max_iter)
	{
		xtemp = (x * x) - (y * y) + x0;
		y = (2 * x * y) + y0;
		x = xtemp;
		i++;
	}
	return (i);
}

int	compute_iterations(t_args *args, double x0, double y0)
{
	if (args->type == MANDELBROT)
		return (calc_mandelbrot(x0, y0, args->curr_iter));
	return (0);
}

void	draw_fractal(t_state *st)
{
	t_draw	d;
	int	scaled_iter;
	double	x0;
	double	y0;

	scaled_iter = (int)(st->args->max_iter * st->args->zoom * I_SCALE_FACTOR);
	if (scaled_iter < 1)
		scaled_iter = 1;
	if (scaled_iter >MAX_ITER_MAX)
		scaled_iter = MAX_ITER_MAX;
	st->args->curr_iter = scaled_iter;
	d.py = 0;
	while (d.py < st->env->height)
	{
		d.px = 0;
		while (d.px < st->env->width)
		{
			x0 = (d.px - st->env->width / 2.0) / st->args->zoom;
			y0 = (d.py - st->env->height / 2.0) / st->args->zoom;
			d.i = compute_iterations(st->args, x0, y0);
			d.color = get_color(d.i, st->args->curr_iter,
				st->args->color_mode);
			put_pixel(&st->env->img, d.px, d.py, d.color);
			d.px++;
		}
		d.py++;
	}
	mlx_put_image_to_window(st->env->mlx, st->env->win, st->env->img.img, 0, 0);
}

