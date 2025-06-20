/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:16:11 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/20 18:13:25 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fractol.h"
#include <ctype.h>
#include <stdio.h>

static int	is_number(const char *s)
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

static int	is_valid_args_format(int ac, char **av)
{
	int	i;

	if (ac < 2)
		return (0);
	if (!(ft_strncmp(av[1], "mandelbrot", 10) == 0 ||
		ft_strncmp(av[1], "julia", 5)== 0))
		return (0);
	i = 2;
	while (i < ac)
	{
		if (!is_number(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void	init_args(t_args *data, char **av)
{
}

