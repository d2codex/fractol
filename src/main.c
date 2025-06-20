/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:30:22 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/20 18:13:22 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

int	main(void)
{
	t_args	data;
//	void	*mlx_ptr;
//	void	*win_ptr;

	if (!is_valid_args_format())
	{
		print_usage();
		return (1); // or exit?
	}
	init_args(&data);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	mlx_new_window(mlx_ptr, 500, 500, "Test");
	win_ptr = mlx_clear_window(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
