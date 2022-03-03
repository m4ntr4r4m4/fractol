/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathfun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:41:14 by ahammoud          #+#    #+#             */
/*   Updated: 2022/03/03 19:13:08 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real + b.real;
	c.img = a.img + b.img;
	return (c);
}

t_complex	sqr(t_complex a)
{
	t_complex	c;

	c.real = a.real * a.real - a.img * a.img;
	c.img = 2 * a.real * a.img;
	return (c);
}

t_complex	powermulti(t_complex a, int n)
{
	t_complex	c;

	c.real = pow((a.real * a.real + a.img * a.img), \
			(n / 2)) * cos(n * atan2(a.img, a.real));
	c.img = pow((a.real * a.real + a.img * a.img), \
			(n / 2)) * sin(n * atan2(a.img, a.real));
	return (c);
}

t_complex	zero(t_complex a)
{
	a.real = 0;
	a.img = 0;
	return (a);
}

int	iter_man(void *vars)
{
	int	i;

	i = 0;
	if (!ft_strncmp((*(t_vars *)vars).str, "Julia", 4))
		(*(t_vars *)vars).p = (*(t_vars *)vars).c;
	while (i < 200)
	{
		(*(t_vars *)vars).old.img = (*(t_vars *)vars).new.img;
		(*(t_vars *)vars).old.real = (*(t_vars *)vars).new.real;
		(*(t_vars *)vars).new = sqr((*(t_vars *)vars).old);
		(*(t_vars *)vars).new = add((*(t_vars *)vars).new, (*(t_vars *)vars).p);
		if (((*(t_vars *)vars).new.real * (*(t_vars *)vars).new.real + \
			(*(t_vars *)vars).new.img * (*(t_vars *)vars).new.img) > 4)
			break ;
		i++;
	}
	return (i);
}
