/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 21:28:34 by yhliboch          #+#    #+#             */
/*   Updated: 2019/06/03 21:28:36 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		which_color(int i, int maxiter)
{
	double	t;
	int		color;

	t = (double)i/(double)maxiter;
	color = (((int)((9 * (1 - t) * t * t * t * 255)) << 16) |
				(((int)(15 * (1 - t) * (1 - t) * t * t * 255)) << 8)) |
							(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (color);
}

void	ft_pixel_put(t_fr *head, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * head->bpp / 8) + (y * head->size_line);
		head->init.addr[i] = color;
		head->init.addr[++i] = color >> 8;
		head->init.addr[++i] = color >> 16;
	}
}

void	draw_fractol(t_fr *head)
{
	if (head->type == JUL)
		julia(&head->jul, head);
	else if (head->type == MAN)
		man_rot(&head->man, head);
	else
		ship(&head->ship, head);
}
