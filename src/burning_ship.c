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

void	ship(t_j *sp, t_fr *hd, int y, int x)
{
	int		i;

	while (++y < hd->yend && (x = hd->xstart - 1))
	{
		while (++x < hd->xend)
		{
			sp->cre = (1.5 * (x - WIDTH / 2)) /
			(0.5 * sp->zoom * WIDTH) + sp->movex;
			sp->cim = (y - HEIGHT / 2) / (0.5 * sp->zoom * HEIGHT) + sp->movey;
			sp->newre = 0;
			sp->newim = 0;
			i = -1;
			while (++i < hd->maxiter)
			{
				sp->oldre = sp->newre;
				sp->oldim = sp->newim;
				sp->newre = sp->oldre * sp->oldre
				- sp->oldim * sp->oldim + sp->cre;
				sp->newim = fabs(2 * sp->oldre * sp->oldim) + sp->cim;
				if ((sp->newre * sp->newre + sp->newim * sp->newim) > 4)
					break ;
			}
			ft_pixel_put(hd, x, y, which_color(i, hd->maxiter));
		}
	}
}
