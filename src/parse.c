/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:16:11 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/21 15:59:57 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_mandelbrot_args(int ac, char **av, t_args *d)
{

	if (ac >= 3)
		d->max_iter = ft_atoi(av[2]);
	if (ac >= 4)
		d->color_mode = ft_atoi(av[3]);
	if (ac >= 5)
		d->zoom = ft_atof(av[4]);
}

void	parse_julia_args(int ac, char **av, t_args *d)
{
	if (ac >= 3)
		d->julia_real = ft_atof(av[2]);
	if (ac >= 4)
		d->julia_imag = ft_atof(av[3]);
	if (ac >= 5)
		d->max_iter =ft_atoi(av[4]);
	if (ac >= 6)
		d->color_mode = ft_atoi(av[5]);
	if (ac >= 7)
		d->zoom = ft_atof(av[6]);
}

int	parse_check_args(int ac, char **av, t_args *d)
{
	if (d->type == MANDELBROT)
	{	
		parse_mandelbrot_args(ac, av, d);
		if(!in_range_common_args(d))
			return (0);
	}
	else if (d->type == JULIA)
	{
		parse_julia_args(ac, av, d);
		if(!in_range_common_args(d))
			return (0);
		if (d->julia_real < REAL_MIN || d->julia_real > REAL_MAX)
			return (0);
		if (d->julia_imag < IMAG_MIN || d->julia_imag > IMAG_MAX)
			return (0);
	}
	return (1);
}