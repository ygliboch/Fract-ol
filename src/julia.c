/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:47:03 by yhliboch          #+#    #+#             */
/*   Updated: 2019/06/03 17:47:04 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_j *j, t_fr *hd)
{
	int		x;
	int		y;
	int		i;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			j->newre = 1.5 * (x - WIDTH / 2) / (0.5 * j->zoom * WIDTH) + j->movex;
			j->newim = (y - HEIGHT / 2) / (0.5 * j->zoom * HEIGHT) + j->movey;
			i = -1;
			while (++i < hd->maxiter)
			{
				j->oldre = j->newre;
				j->oldim = j->newim;
				j->newre = j->oldre * j->oldre - j->oldim * j->oldim + j->cre;
				j->newim = 2 * j->oldre * j->oldim + j->cim;
				if ((j->newre * j->newre + j->newim * j->newim) > 4)
					break ;
			}
			ft_pixel_put(hd, x, y, which_color(i, hd->maxiter));
		}
	}
	mlx_put_image_to_window(hd->init.mlx_ptr, hd->init.win_ptr,
									hd->init.img_ptr, 0, 0);
}
