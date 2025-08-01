/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:11:27 by diade-so          #+#    #+#             */
/*   Updated: 2025/08/01 11:42:04 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int      redraw_in_progress = 0;

int	mouse_scroll_bonus(int button, int x, int y, void *param)
{
	t_state	*st;
	double	mouse_re;
	double	mouse_im;
	double	prev_zoom;

	if (redraw_in_progress)
		return (0);
	redraw_in_progress = 1;
	st = (t_state *)param;
	prev_zoom = st->args->zoom;
	mouse_re = (x - st->env->width / 2.0) / prev_zoom + st->args->offset_x;
	mouse_im = -(y - st->env->height / 2.0) / prev_zoom + st->args->offset_y;
	if (button == 5)
		st->args->zoom *= 0.8;
	else if (button == 4)
		st->args->zoom *= 1.25;
	st->args->zoom_factor = log(st->args->zoom + 1.0);
	st->args->offset_x = mouse_re - (x - st->env->width / 2.0) / st->args->zoom;
	st->args->offset_y = mouse_im + (y - st->env->height / 2.0) / st->args->zoom;
	draw_fractal(st);
	mlx_put_image_to_window(st->env->mlx, st->env->win, st->env->img.img, 0, 0);
	redraw_in_progress = 0;
	return (1);
}
