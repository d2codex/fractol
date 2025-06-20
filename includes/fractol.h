/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:05:43 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/20 18:11:38 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "libft.h"
#include <mlx.h>
#include <string.h>
#include <cytpe.h>

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
}	t_fractal_type;

typedef struct s_args
{
	t_fractal_type type;
	double	julia_real;
	double	julia_imag;
	int	max_iter;
	int	color_mode;
	double	zoom;
}	t_args;

// prototypes for init.c

// prototypes for print.c
void	print_usage(void);

// prototyeps for validate.c
static int	is_number(const char *s);
static int	is_valid_args_format(int ac, char **av);

#endif
