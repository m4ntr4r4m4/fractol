/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:48:33 by ahammoud          #+#    #+#             */
/*   Updated: 2022/02/25 17:36:39 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void juliaset(t_vars vars, int width,int height)
{
	int	x;
	int	y;
	int	i;
	double a;
	
	a = 0.0001;
	x = 0;
	i = 0;
	while(x < width)
	{
		y = 0;
		while(y < height)
		{
			vars.new.real = 1.5 * (x - width / 2) / (0.5 * vars.zoom * width);
			vars.new.img = (y - height / 2) / (0.5 * vars.zoom * height);
			i = 0;
			while(i < 200)
			{
				vars.old.real = vars.new.real;
				vars.old.img =  vars.new.img;
				vars.new = sqr(vars.old);
				vars.new = add(vars.new, vars.c);
				if((vars.new.real * vars.new.real + vars.new.img * vars.new.img) > 4 )
					break;
				i++;
			}
			color_fun(i, &vars);
			putpixel(vars.img, x, y, vars.color -  a );
			a += 0.0001f;
			y++;
		}
		x++;
	}
}
