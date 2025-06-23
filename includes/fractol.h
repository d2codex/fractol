/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:05:43 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/23 16:49:20 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "libft.h"
#include "config.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef enum e_fractal
{
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

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	int	width;
	int	height;
}	t_env;

// prototypes for init.c
int	init_parse_args(int ac, char **av, t_args *d);

// prototypes for parse.c
int     is_number(const char *s);
void    parse_mandelbrot_args(int ac, char **av, t_args *d);
void    parse_julia_args(int ac, char **av, t_args *d);
int     in_range_common_args(t_args *d);
int	parse_check_args(int ac, char **av, t_args *d);

// prototypes for print.c
void	print_usage(void);
void	perror_exit(char *msg);
void	werror_exit_args(char *msg);
void	werror_exit(char *msg);

// prototypes for windows.c
int	init_window(t_env *env);
int	close_window(t_env *env);
int	handle_keypress(int keycode, t_env *env);

#endif
