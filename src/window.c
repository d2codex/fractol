/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:06:06 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/29 18:45:04 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
