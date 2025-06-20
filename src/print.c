/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:27:29 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/20 17:30:03 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fractol mandelbrot %s[max-iteration]%s %s[color-mode]%s" 
		" %s[zoom]%s\n", RED, RESET, GRN, RESET, YEL, RESET);
	ft_printf("    OR\n");
	ft_printf("  ./fractol julia %s<real>%s %s<imag>%s %s[max-iteration]%s"
		" %s[color-mode]%s %s[zoom]%s\n\n", BLU, RESET, CYN, RESET,
		RED, RESET, GRN, RESET, YEL, RESET);
	ft_printf("Mandatory Options:\n");
	ft_printf("  %s real%s: float (e.g -0.7)\n", BLU, RESET);
	ft_printf("  %s imag%s: float (e.g 0.27015)\n", CYN, RESET);
	ft_printf("Optional Options:\n");
	ft_printf("  %s max-iteration%s: 1 - 10000(recommended) "
		"(default: 100)\n", RED, RESET);
	ft_printf("  %s color_mode%s: 0 - 2 (default: 0)\n", GRN, RESET);
	ft_printf("  %s zoom%s: float > 0.0 (default: 1.0)\n", YEL, RESET);
}

int	main(void)
{
	print_usage();
	return (0);
}

