/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:06:06 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/23 17:38:55 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_window(t_env *env)
{
	env->width = WIN_WIDTH;
	env->height = WIN_HEIGHT;
	env->mlx = mlx_init();
	printf("mlx: %p, width: %d, height: %d\n", env->mlx, env->width, env->height);

	if (!env->mlx)
		return (1);
	env->win = mlx_new_window(env->mlx, env->width, env->height, "fractol");
	if (!env->win)
		return (1);
	return (0);
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
	return (0);
}
