/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:35:58 by ahammoud          #+#    #+#             */
/*   Updated: 2022/02/23 20:00:33 by ahammoud         ###   ########.fr       */
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
