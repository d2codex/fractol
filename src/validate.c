/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:04:38 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/21 16:06:12 by diade-so         ###   ########.fr       */
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

int	is_valid_args_format(int ac, char **av, t_args *d)
{
	int	i;

	if (ac < 2)
		return (0);
	if (d->type == NONE)
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

int	in_range_common_args(t_args *d)
{
	if (d->max_iter < MAX_ITER_MIN || d->max_iter > MAX_ITER_MAX)
		return (0);
	if (d->color_mode < COLOR_MODE_MIN || d->color_mode > COLOR_MODE_MAX)
		return (0);
	if (d->zoom < ZOOM_MIN || d->zoom > ZOOM_MAX)
		return (0);
	return (1);
}
