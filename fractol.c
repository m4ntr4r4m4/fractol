/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:53:48 by ahammoud          #+#    #+#             */
/*   Updated: 2022/02/23 17:21:07 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	leaks(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	char	*man;
	char	*jul;

	atexit(leaks);
	jul = "Julia";
	man = "Mandelbrot";
	if (argc >= 2)
	{
		if (ft_strncmp(argv[1], man, ft_strlen(man)) \
				&& ft_strncmp(argv[1], jul, ft_strlen(jul)))
			printf("available sets are:\nMandelbrot\nJulia\n");
		if (!ft_strncmp(argv[1], man, ft_strlen(man)))
			mandelbrot();
	}
	return (0);
}
