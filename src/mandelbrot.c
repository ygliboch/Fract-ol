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

void	man_rot(t_j *mn, t_fr *hd, int y, int x)
{
	double	pr;
	double	pi;
	int		i;

	while (++y < hd->yend && (x = hd->xstart - 1))
	{
		while (++x < hd->xend)
		{
			pr = 1.5 * (x - WIDTH / 2) / (0.5 * mn->zoom * WIDTH) + mn->movex;
			pi = (y - HEIGHT / 2) / (0.5 * mn->zoom * HEIGHT) + mn->movey;
			mn->newre = 0;
			mn->newim = 0;
			i = -1;
			while (++i < hd->maxiter)
			{
				mn->oldre = mn->newre;
				mn->oldim = mn->newim;
				mn->newre = mn->oldre * mn->oldre - mn->oldim * mn->oldim + pr;
				mn->newim = 2 * mn->oldre * mn->oldim + pi;
				if ((mn->newre * mn->newre + mn->newim * mn->newim) > 4)
					break ;
			}
			ft_pixel_put(hd, x, y, which_color(i, hd->maxiter));
		}
	}
}
