/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:53:48 by ahammoud          #+#    #+#             */
/*   Updated: 2022/03/03 19:29:01 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	printf("available sets are:\nMandelbrot\nJulia\nMulti-jul\n");
}

void	check(char **argv, char **man)
{
	if (!ft_strncmp(argv[1], man[1], ft_strlen(man[1])) \
			&& ft_strlen(argv[1]) == 10)
		init_fractol("Mandel");
	else if (!ft_strncmp(argv[1], man[0], ft_strlen(man[0])) \
			&& ft_strlen(argv[1]) == 5)
		init_fractol("Julia");
	else if (!ft_strncmp(argv[1], man[2], ft_strlen(man[2])) \
			&& ft_strlen(argv[1]) == 7)
		init_fractol("Multi");
	else
		error();
}

int	main(int argc, char **argv)
{
	char	*man[3];

	man[0] = "Julia";
	man[1] = "Mandelbrot";
	man[2] = "Multi-j";
	if (argc >= 2 && argc < 3)
	{
		if (ft_strlen(argv[1]) == 10 || ft_strlen(argv[1]) == 5 \
				|| ft_strlen(argv[1]) == 7)
			check(argv, man);
		else
			error();
	}
	else
		error();
	return (0);
}
