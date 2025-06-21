/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:05:43 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/21 16:02:47 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "libft.h"
#include <mlx.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITER_MIN 1
#define MAX_ITER_MAX 10000
#define COLOR_MODE_MIN 0
#define COLOR_MODE_MAX 5
#define ZOOM_MIN 0.1
#define ZOOM_MAX 100.0
#define REAL_MIN -2.0
#define REAL_MAX 2.0
#define IMAG_MIN -2.0
#define IMAG_MAX 2.0

typedef enum e_fractal
{
	NONE,
	MANDELBROT,
	JULIA,
}	t_fractal;

typedef struct s_args
{
	t_fractal type;
	double	julia_real;
	double	julia_imag;
	int	max_iter;
	int	color_mode;
	double	zoom;
}	t_args;

// prototypes for init.c
void	init_args(char **av, t_args *d);

// prototypes for parse.c
int	parse_check_args(int ac, char **av, t_args *d);
void    parse_mandelbrot_args(int ac, char **av, t_args *d);
void    parse_julia_args(int ac, char **av, t_args *d);

// prototypes for print.c
void	print_usage(void);

// prototypes for validate.c
int	is_number(const char *s);
int	is_valid_args_format(int ac, char **av);
int     in_range_common_args(t_args *d);
#endif
