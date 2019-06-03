/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:55:24 by yhliboch          #+#    #+#             */
/*   Updated: 2019/06/03 19:55:25 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ship(t_j *ship, t_fr *hd)
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
			ship->cre = (1.5 * (x - WIDTH / 2)) / (0.5 * ship->zoom * WIDTH) + ship->movex;
			ship->cim = (y - HEIGHT / 2) / (0.5 * ship->zoom * HEIGHT) + ship->movey;
			ship->newre = 0;
			ship->newim = 0;
			i = -1;
			while (++i < hd->maxiter)
			{
				ship->oldre = ship->newre;
				ship->oldim = ship->newim;
				ship->newre = ship->oldre * ship->oldre - ship->oldim * ship->oldim + ship->cre;
				ship->newim = fabs(2 * ship->oldre * ship->oldim) + ship->cim;
				if ((ship->newre * ship->newre + ship->newim * ship->newim) > 4)
					break ;
			}
			ft_pixel_put(hd, x, y, which_color(i, hd->maxiter));
		}
	}
	mlx_put_image_to_window(hd->init.mlx_ptr, hd->init.win_ptr,
										hd->init.img_ptr, 0, 0);
}
