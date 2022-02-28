/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:45:57 by ahammoud          #+#    #+#             */
/*   Updated: 2022/02/25 17:36:45 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrotset(t_vars vars, int width, int height)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			vars.p.real = 1.5 * (x - width / 2) / (0.5 * vars.zoom * width) \
				+ vars.movex;
			vars.p.img = (y - height / 2) / (0.5 * vars.zoom * height) \
					+ vars.movey;
			vars.old = zero(vars.old);
			vars.new = zero(vars.new);
			i = iter_man(&vars);
			color_fun(i, &vars);
			putpixel(vars.img, x, y, vars.color);
			y++;
		}
		x++;
	}
}
