/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:03:19 by diade-so          #+#    #+#             */
/*   Updated: 2025/08/01 13:17:19 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int calc_mandelbrot(double cr, double ci, int max_iter)
{
	double zr;
	double zi;
	double zr2;
	double zi2;
	int i;
	
	zr = 0;
	zi = 0;
	zr2 = 0;
    	zi2 = 0;
	i = 0;
	while ((zr2 + zi2) <= 4 && i < max_iter)
	{
		zi = 2 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		zr2 = zr * zr;
		zi2 = zi * zi;
		i++;
	}
	return (i);
}

int	calc_julia(double x, double y, t_args *args)
{
	int		i;
	double		zr;
	double		zi;
	double		temp;

	zr = x;
	zi = y;
	i = 0;
	while (zr * zr + zi * zi <= 4 && i < args->curr_iter)
	{
		temp = zr * zr - zi * zi + args->julia_real;
		zi = 2 * zr * zi + args->julia_imag;
		zr = temp;
		i++;
	}
	return (i);
}

double	compute_iterations(t_args *args, double x0, double y0)
{
	if (args->type == MANDELBROT)
		return (calc_mandelbrot(x0, y0, args->curr_iter));
	else if (args->type == JULIA)
		return (calc_julia(x0, y0, args));
	return (0);
}

void draw_fractal(t_state *st)
{
	t_draw d;
	int scaled_iter;
	double scale;
	double x0;
	double xy;
	
	scaled_iter = (int)(st->args->max_iter * st->args->zoom_factor * I_SCALE_FACTOR);
	if (scaled_iter < 1)
		scaled_iter = 1;
	if (scaled_iter > MAX_ITER_MAX)
		scaled_iter = MAX_ITER_MAX;
	st->args->curr_iter = scaled_iter;
	scale = 1.0 / st->args->zoom;d.py = 0;
	while (d.py < st->env->height)
	{
		d.px = 0;
		while (d.px < st->env->width)
		{
			x0 = d.px * scale + st->args->offset_x - (st->env->width
				/ 2.0) * scale;
			y0 = -d.py * scale + st->args->offset_y + (st->env->height
				/ 2.0) * scale;
			d.i = compute_iterations(st->args, x0, y0);
			d.color = get_color(d.i, st->args->curr_iter, st->args->color_mode);
			put_pixel(&st->env->img, d.px, d.py, d.color);
			d.px++;
		}
		d.py++;
	}
	mlx_put_image_to_window(st->env->mlx, st->env->win, st->env->img.img, 0, 0);
}

