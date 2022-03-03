/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:54:33 by ahammoud          #+#    #+#             */
/*   Updated: 2022/03/03 19:25:22 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_point
{
	int	x;
	int	y;
}							t_point;
typedef struct s_complex
{
	double	real;
	double	img;
}							t_complex;
typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}							t_data;
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		*img;
	double		zoom;
	double		movex;
	double		movey;
	int			hookchange;
	int			r;
	int			g;
	int			b;
	int			color;
	int			reset;
	int			n;
	char		*str;
	t_complex	c;
	t_complex	p;
	t_complex	new;
	t_complex	old;
}							t_vars;

void		putpixel(t_data *data, int x, int y, int color);
void		init_vars(void *vars);
void		init(void *vars);
int			key_hook(int keycode, t_vars *vars);
int			mouse_hook(int mousecode, int x, int y, t_vars *vars);
int			create_trgb(int t, int r, int g, int b);
t_complex	add(t_complex a, t_complex b);
t_complex	sqr(t_complex a);
t_complex	powermulti(t_complex a, int n);
void		cleaner(t_vars vars, int width, int height);
void		mandelbrotset(t_vars vars, int width, int height);
void		juliaset(t_vars vars, int width, int height);
void		multijulia(t_vars vars, int width, int height);
void		init_fractol(char *str);
t_complex	zero(t_complex a);
void		color_fun(int i, void *vars);
int			iter_man(void *vars);
int			render_next_frame(void *vars);
int			iter_multi(void *vars);
void		check(char **argv, char **man);
void		error(void);
#endif
