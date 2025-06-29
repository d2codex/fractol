/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:06:06 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/29 12:02:38 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static int	redraw_in_progress = 0;

int	init_window(t_env *env)
{
	env->width = WIN_WIDTH;
	env->height = WIN_HEIGHT;
	env->mlx = mlx_init();

	if (!env->mlx)
	{
		printf("mlx");
		return (0);
	}
//	printf("mlx: %p, width: %d, height: %d\n", env->mlx, env->width, env->height);
	env->win = mlx_new_window(env->mlx, env->width, env->height, "fractol");
	if (!env->win)
	{
		printf("win");
		return (0);
	}
//	printf("win: %p, width: %d, height: %d\n", env->win, env->width, env->height);
	return (1);
}

int	close_window(t_env *env)
{
	if (env->img.img)
		mlx_destroy_image(env->mlx, env->img.img);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
		mlx_destroy_display(env->mlx);
	exit(0);
}

int	handle_keypress(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
		close_window(env);
	return (1);
}

int	handle_expose(t_state *st)
{
	draw_fractal(st);
	mlx_put_image_to_window(st->env->mlx, st->env->win, st->env->img.img, 0,0);
	return (1);
}

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
	draw_fractal(st);
	mlx_put_image_to_window(st->env->mlx, st->env->win, st->env->img.img, 0, 0);
	redraw_in_progress = 0;
	return (1);
}
