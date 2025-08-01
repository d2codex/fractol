/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:19:40 by diade-so          #+#    #+#             */
/*   Updated: 2025/08/01 12:03:34 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

static int      redraw_in_progress = 0;

int	mouse_scroll(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	t_state	*st;

	if (redraw_in_progress)
		return (0);
	redraw_in_progress = 1;
	st = (t_state *)param;
	if (button == 5)
		st->args->zoom *= 0.8;
	else if (button == 4)
		st->args->zoom *= 1.25;
	st->args->zoom_factor = log(st->args->zoom + 1.0);
	draw_fractal(st);
	mlx_put_image_to_window(st->env->mlx, st->env->win, st->env->img.img, 0, 0);
	redraw_in_progress = 0;
	return (1);
}

