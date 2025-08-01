/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:36:06 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/30 18:04:06 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_image(t_env *env)
{
	
	env->img.img = mlx_new_image(env->mlx, env->width, env->height);
	if (!env->img.img)
		return (0);
	env->img.addr = mlx_get_data_addr(
		env->img.img, 
		&env->img.bpp,
		&env->img.line_len,
		&env->img.endian);
	if (!env->img.addr)
		return (0);
	return (1);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char *dst;

	if (x < 0 || y < 0)
	{
		printf("out of bounds");
		return ;
	}
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	if (!dst)
	{
		printf("error dst");
		return ;
	}
	*(unsigned int *)dst = color;
}

int	get_color(double iter, int max_iter, int color_mode)
{
	if (iter == max_iter)
		return (int)(0x000000);
	if (color_mode == 0)
		return (int)(0xFFFFFF * iter / max_iter);
	else if (color_mode == 1)
		return ((int)(iter * 5) << 16);
	else if (color_mode == 2)
		return ((int)(iter * 9) << 8);
	return (0x000000);
}
