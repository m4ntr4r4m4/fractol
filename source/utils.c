/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:35:58 by ahammoud          #+#    #+#             */
/*   Updated: 2022/02/25 20:07:58 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	putpixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	cleaner(t_vars vars, int width, int height)
{
	int	color;
	int	x;
	int	y;

	x = 0;
	y = 0;
	color = create_trgb(0, 0, 0, 0);
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			putpixel(vars.img, x, y, color);
			y++;
		}
		x++;
	}
	printf("cleaning\n");
}

void	init_vars(void *vars)
{
		(*(t_vars *)vars).c.img = 0.2321;
		(*(t_vars *)vars).c.real = -0.835;
		(*(t_vars *)vars).zoom = 1;
		(*(t_vars *)vars).movex = 0;
		(*(t_vars *)vars).movey = 0;
		(*(t_vars *)vars).b = 0;
		(*(t_vars *)vars).g = 0;
		(*(t_vars *)vars).r = 0;
		(*(t_vars *)vars).reset = 1;
}

void	color_fun(int i, void *vars)
{
	if (i < 10)
		(*(t_vars *)vars).color = create_trgb(0, (*(t_vars *)vars).r, \
				(*(t_vars *)vars).g, i % 255);
	else if (i < 50)
		(*(t_vars *)vars).color = create_trgb(0, (*(t_vars *)vars).r, \
				i % 255, (*(t_vars *)vars).b);
	else
		(*(t_vars *)vars).color = create_trgb(0, i % 255, \
				(*(t_vars *)vars).g, (*(t_vars *)vars).b);
}
