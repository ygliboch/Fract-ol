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

int		move_julia(int x, int y, t_fr *head)
{
	if (head->type == JUL && head->jul.p == 0)
	{
		head->jul.cre = (((double)y * 2) / HEIGHT) - 1;
		head->jul.cim = (((double)x * 2) / WIDTH) - 1;
		update(head);
	}
	return (0);
}

void	julia(t_j *j, t_fr *hd, int i)
{
	int		x;
	int		y;

	y = hd->ystart - 1;
	while (++y < hd->yend)
	{
		x = hd->xstart - 1;
		while (++x < hd->xend)
		{
			j->newre = 1.5 * (x - WIDTH / 2) /
			(0.5 * j->zoom * WIDTH) + j->movex;
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
}
