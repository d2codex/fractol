/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:05:43 by diade-so          #+#    #+#             */
/*   Updated: 2025/08/01 13:17:48 by diade-so         ###   ########.fr       */
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
#include <unistd.h>
#include <math.h>

typedef enum e_fractal
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP
}	t_fractal;

typedef struct s_args
{
	t_fractal type;
	double	julia_real;
	double	julia_imag;
	int	max_iter;
	int	curr_iter;
	int	color_mode;
	double	zoom;
	double	zoom_factor;
	double	offset_x;
	double	offset_y;
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

typedef struct s_state
{
	t_args	*args;
	t_env	*env;
}	t_state;

typedef struct s_draw
{
	double	x;
	double	y;
	int	px;
	int	py;
	double	i;
	int	color;
}	t_draw;

// prototypes for init.c
int	init_parse_args(int ac, char **av, t_args *args);

// prototypes for parse.c
int     is_number(const char *s);
void    parse_mandelbrot_args(int ac, char **av, t_args *args);
void    parse_julia_args(int ac, char **av, t_args *args);
int     in_range_common_args(t_args *args);
int	parse_check_args(int ac, char **av, t_args *args);

// prototypes for print.c
void	print_usage(void);
void	perror_exit(char *msg);
void	werror_exit_args(char *msg);
void	werror_exit(char *msg);

// prototypes for window.c
int	init_window(t_env *env);
int	close_window(t_env *env);
int	handle_keypress(int keycode, t_env *env);
int     handle_expose(t_state *st);

// prototypes for mouse.c
int     mouse_scroll(int button, int x, int y, void *param);

// prototypes for draw.c
int	init_image(t_env *env);
void	put_pixel(t_img *img, int x, int y, int color);
int     get_color(double iter, int max_iter, int color_mode);

// prototypes for fractal.c
int     calc_mandelbrot(double x0, double y0, int max_iter);
double     compute_iterations(t_args *args, double x0, double y0);
void    draw_fractal(t_state *st);

#endif
