/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:30:22 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/23 16:48:08 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

int	main(int ac, char **av)
{
	t_args	d;
	t_env	env;

	if (ac < 2)
		werror_exit("Error: Not enough arguments\n");
	if (!init_parse_args(ac, av, &d))
		werror_exit("Error\n");
	if (!init_window(&env))
		werror_exit("Error: failed to create new window\n");
	mlx_key_hook(env.win, handle_keypress, &env);
	mlx_hook(env.win, 17, 0, close_window, &env);
	mlx_loop(env.mlx);
	return (0);
}
