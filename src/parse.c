/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:16:11 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/27 12:46:15 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_number(const char *s)
{
	int	dot_seen;
	int	digit_seen;

	dot_seen = 0;
	digit_seen = 0;
	if (!s || *s == '\0')
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s == '.')
		{
			if (dot_seen)
				return (0);
			dot_seen = 1;
		}
		else if (isdigit(*s))
			digit_seen = 1;
		else
			return (0);
		s++;
	}
	return (digit_seen);
}

void	parse_mandelbrot_args(int ac, char **av, t_args *args)
{

	if (ac >= 3)
		args->max_iter = ft_atoi(av[2]);
	if (ac >= 4)
		args->color_mode = ft_atoi(av[3]);
	if (ac >= 5)
		args->zoom = ft_atof(av[4]);
}

void	parse_julia_args(int ac, char **av, t_args *args)
{
	if (ac >= 3)
		args->julia_real = ft_atof(av[2]);
	if (ac >= 4)
		args->julia_imag = ft_atof(av[3]);
	if (ac >= 5)
		args->max_iter =ft_atoi(av[4]);
	if (ac >= 6)
		args->color_mode = ft_atoi(av[5]);
	if (ac >= 7)
		args->zoom = ft_atof(av[6]);
}

int	in_range_common_args(t_args *args)
{
	if (args->max_iter < MAX_ITER_MIN || args->max_iter > MAX_ITER_MAX)
		return (0);
	if (args->color_mode < COLOR_MODE_MIN || 
		args->color_mode > COLOR_MODE_MAX)
		return (0);
	if (args->zoom < ZOOM_MIN || args->zoom > ZOOM_MAX)
		return (0);
	return (1);
}

int	parse_check_args(int ac, char **av, t_args *args)
{
	if (args->type == MANDELBROT)
	{	
		parse_mandelbrot_args(ac, av, args);
		if(!in_range_common_args(args))
			return (0);
	}
	else if (args->type == JULIA)
	{
		parse_julia_args(ac, av, args);
		if(!in_range_common_args(args))
			return (0);
		if (args->julia_real < REAL_MIN || args->julia_real > REAL_MAX)
			return (0);
		if (args->julia_imag < IMAG_MIN || args->julia_imag > IMAG_MAX)
			return (0);
	}
	return (1);
}
