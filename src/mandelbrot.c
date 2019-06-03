/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:13:42 by yhliboch          #+#    #+#             */
/*   Updated: 2019/06/03 15:13:44 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	man_rot(t_j *man, t_fr *hd)
{
	int		y;
	int		x;
	double	pr;
	double	pi;
	int		i;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = 1.5 * (x - WIDTH / 2) / (0.5 * man->zoom * WIDTH) + man->movex;
			pi = (y - HEIGHT / 2) / (0.5 * man->zoom * HEIGHT) + man->movey;
			man->newre = 0;
			man->newim = 0;
			man->oldre = 0;
			man->newre = 0;
			i = -1;
			while (++i < hd->maxiter)
			{
				man->oldre = man->newre;
				man->oldim = man->newim;
				man->newre = man->oldre * man->oldre - man->oldim * man->oldim + pr;
				man->newim = 2 * man->oldre * man->oldim + pi;
				if ((man->newre * man->newre + man->newim *man->newim) > 4)
					break ;
			}
			ft_pixel_put(hd, x, y, which_color(i, hd->maxiter));
		}
	}
	mlx_put_image_to_window(hd->init.mlx_ptr, hd->init.win_ptr,
										hd->init.img_ptr, 0, 0);
}
