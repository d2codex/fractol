/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:30:22 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/29 11:54:16 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

int	main(int ac, char **av)
{
	t_args	args;
	t_env	env;
	t_state	st;

	if (ac < 2)
		werror_exit_args("Error: Not enough arguments\n");
	if (!init_parse_args(ac, av, &args))
		werror_exit_args("Error\n");
	if (!init_window(&env))
		werror_exit("Error: failed to create new window\n");
	if (!init_image(&env))
		werror_exit("Error: failed to create image\n");
	st.args = &args;
	st.env = &env;
	draw_fractal(&st);
	mlx_key_hook(env.win, handle_keypress, &env);
	mlx_hook(env.win, 17, 0, close_window, &env);
	mlx_expose_hook(env.win, handle_expose, &st);
	mlx_mouse_hook(env.win, mouse_scroll, &st);
	mlx_loop(env.mlx);
	return (0);
}
