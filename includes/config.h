/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:57:57 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/27 18:27:45 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H
# endif

#define MAX_ITER_MIN 1
#define MAX_ITER_MAX 2000
#define COLOR_MODE_MIN 0
#define COLOR_MODE_MAX 2
#define ZOOM_MIN 0.0001
#define ZOOM_MAX 1000000.0
#define REAL_MIN -2.0
#define REAL_MAX 2.0
#define IMAG_MIN -2.0
#define IMAG_MAX 2.0
#define I_SCALE_FACTOR 1.0

#ifndef WIN_WIDTH
# define WIN_WIDTH 600
# endif

#ifndef WIN_HEIGHT
# define WIN_HEIGHT 600
# endif
