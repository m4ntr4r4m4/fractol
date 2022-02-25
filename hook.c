/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:35:58 by ahammoud          #+#    #+#             */
/*   Updated: 2022/02/25 17:17:47 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	printf("this is keycode: %d\n", keycode);
	if (keycode >= 0)
		vars->hookchange = 1;
	if (keycode == 11)
		vars->b += 10;
	if (keycode == 9)
		vars->b -= 10;
	if (keycode == 0)
		vars->c.real -= 0.01;
	if (keycode == 2)
		vars->c.real += 0.01;
	if (keycode == 1)
		vars->c.img -= 0.01;
	if (keycode == 13)
		vars->c.img += 0.01;
	if (keycode == 82 || keycode == 29)
	{
		init_vars(vars);
		vars->reset = 1;
	}
	if (keycode == 53)
		exit(0);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	if (mousecode == 1)
	{
		printf("this is x: %d this y: %d\n", x, y);
		vars->movex = ((double)(x - 300) / 600);
		vars->movey = ((double) -1 * (y - 200) / 400);
	}
	if (mousecode == 5)
		vars->zoom += 0.1;
	if (mousecode == 4)
		vars->zoom -= 0.1;
	if (mousecode > 1)
		vars->hookchange = 1;
	return (0);
}
