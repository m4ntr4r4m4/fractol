/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:48:33 by ahammoud          #+#    #+#             */
/*   Updated: 2022/02/25 19:49:36 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	juliaset(t_vars vars, int width, int height)
{
	int		x;
	int		y;
	int		i;
	double	a;

	a = 0.0001;
	x = 0;
	i = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			vars.new.real = 1.5 * (x - width / 2) / (0.5 * vars.zoom * width);
			vars.new.img = (y - height / 2) / (0.5 * vars.zoom * height);
			i = iter_man(&vars);
			color_fun(i, &vars);
			putpixel(vars.img, x, y, vars.color - a);
			a += 0.0001f;
			y++;
		}
		x++;
	}
}
