/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:53:48 by ahammoud          #+#    #+#             */
/*   Updated: 2022/02/25 20:53:42 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	char	*man;
	char	*jul;

	jul = "Julia";
	man = "Mandelbrot";
	if (argc >= 2 && argc < 3)
	{
		if (ft_strncmp(argv[1], man, ft_strlen(man)) \
				&& ft_strncmp(argv[1], jul, ft_strlen(jul)))
			printf("available sets are:\nMandelbrot\nJulia\n");
		if (!ft_strncmp(argv[1], man, ft_strlen(man)))
			init_fractol("Mandel");
		if (!ft_strncmp(argv[1], jul, ft_strlen(jul)))
			init_fractol("Julia");
	}
	else
		printf("available sets are:\nMandelbrot\nJulia\n");
	return (0);
}
