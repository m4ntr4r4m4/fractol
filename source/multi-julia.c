/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi-julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:15:19 by ahammoud          #+#    #+#             */
/*   Updated: 2022/03/03 19:11:08 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter_multi(void *vars)
{
	int	i;

	i = 0;
	while (i < 200)
	{
		(*(t_vars *)vars).old.img = (*(t_vars *)vars).new.img;
		(*(t_vars *)vars).old.real = (*(t_vars *)vars).new.real;
		(*(t_vars *)vars).new = powermulti((*(t_vars *)vars).old, \
				(*(t_vars *)vars).n);
		(*(t_vars *)vars).new = add((*(t_vars *)vars).new, (*(t_vars *)vars).c);
		if (((*(t_vars *)vars).new.real * (*(t_vars *)vars).new.real + \
			(*(t_vars *)vars).new.img * (*(t_vars *)vars).new.img) > 4)
			break ;
		i++;
	}
	return (i);
}

void	multijulia(t_vars vars, int width, int height)
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
			vars.new.real = 1.5 * (x - width / 2) / (0.5 * vars.zoom * width) \
							+ vars.movex;
			vars.new.img = (y - height / 2) / (0.5 * vars.zoom * height) \
							+ vars.movey;
			i = iter_multi(&vars);
			color_fun(i, &vars);
			putpixel(vars.img, x, y, vars.color - a);
			a += 0.0001f;
			y++;
		}
		x++;
	}
}
