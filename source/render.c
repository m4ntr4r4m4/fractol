/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:18:58 by ahammoud          #+#    #+#             */
/*   Updated: 2022/03/03 18:43:03 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_next_frame(void *vars)
{
	if ((*(t_vars *)vars).hookchange || (*(t_vars *)vars).reset)
	{
		cleaner(*(t_vars *)vars, 600, 400);
		mlx_put_image_to_window((*(t_vars *)vars).mlx, \
				((t_vars *)vars)->win, ((t_vars *) vars)->img->img, 0, 0);
		if (!ft_strncmp((*(t_vars *)vars).str, "Mandel", 5))
			mandelbrotset(*(t_vars *)vars, 600, 400);
		if (!ft_strncmp((*(t_vars *)vars).str, "Julia", 4))
			juliaset(*(t_vars *)vars, 600, 400);
		if (!ft_strncmp((*(t_vars *)vars).str, "Multi", 4))
			multijulia(*(t_vars *)vars, 600, 400);
		(*(t_vars *)vars).hookchange = 0;
		(*(t_vars *)vars).reset = 0;
	}
	mlx_put_image_to_window((*(t_vars *)vars).mlx, \
			((t_vars *)vars)->win, ((t_vars *) vars)->img->img, 0, 0);
	return (1);
}

void	init_fractol(char *str)
{
	t_vars	vars;
	t_data	img;

	vars.str = str;
	init_vars(&vars);
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
