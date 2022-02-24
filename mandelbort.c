/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:45:57 by ahammoud          #+#    #+#             */
/*   Updated: 2022/02/24 21:35:04 by ahammoud         ###   ########.fr       */
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
		//	printf("this vars x y %f %f\n", vars.movex, vars.movey);
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

int	render_next_frame(void *vars)
{
	if ((*(t_vars *)vars).hookchange || (*(t_vars *)vars).reset)
	{
		cleaner(*(t_vars *)vars, 600, 400);
		mlx_put_image_to_window((*(t_vars *)vars).mlx, \
				((t_vars *)vars)->win, ((t_vars *) vars)->img->img, 0, 0);
		mandelbrotset(*(t_vars *)vars, 600, 400);
		(*(t_vars *)vars).hookchange = 0;
		(*(t_vars *)vars).reset = 0;
	}
	mlx_put_image_to_window((*(t_vars *)vars).mlx, \
			((t_vars *)vars)->win, ((t_vars *) vars)->img->img, 0, 0);
	return (1);
}

void	mandelbrot(void)
{
	t_vars	vars;
	t_data	img;

	init_mandel(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 400, "Mandelbrot Set!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	img.img = mlx_new_image(vars.mlx, 600, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	vars.img = &img;
	mlx_loop_hook(vars.mlx, render_next_frame, (void *) &vars);
	mlx_loop(vars.mlx);
}
