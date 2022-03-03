/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:35:58 by ahammoud          #+#    #+#             */
/*   Updated: 2022/03/03 18:12:51 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	nav(int x, t_vars **vars)
{
	if (x == 123)
		(*vars)->movex += 0.2 ;
	if (x == 124)
		(*vars)->movex -= 0.2 ;
	if (x == 126)
		(*vars)->movey += 0.2 ;
	if (x == 125)
		(*vars)->movey -= 0.2 ;
	if (x > 1)
		(*vars)->hookchange = 1;
}

int	key_hook(int keycode, t_vars *vars)
{
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
	if (keycode >= 123 && keycode <= 126)
		nav(keycode, &vars);
	if (keycode == 82)
	{
		init_vars(vars);
		vars->reset = 1;
	}
	if (keycode >= 0)
		vars->hookchange = 1;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	if (mousecode == 5)
	{
		vars->zoom += 0.1;
		vars->movex += (((float) x - 300) / 600) / 4 / vars->zoom ;
		vars->movey += (((float) y - 200) / 400) / 4 / vars->zoom ;
	}
	if (mousecode == 4)
		vars->zoom -= 0.1;
	printf("this is movx: %f movey: %f\n", vars->movex, vars->movey);
	printf("this is zoom: %f\n", vars->zoom);
	if (mousecode > 1)
		vars->hookchange = 1;
	return (0);
}
