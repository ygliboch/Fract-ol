/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:26:52 by yhliboch          #+#    #+#             */
/*   Updated: 2019/06/04 14:26:54 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	next_fractol(t_fr *head)
{
	if (head->type == SHIP)
		head->type = MAN;
	else
		head->type += 1;
}

int		key_two(int keycode, t_fr *head, t_j *fr)
{
	if (keycode == KEY_LEFT)
		fr->movex += 0.05;
	if (keycode == KEY_RIGHT)
		fr->movex -= 0.05;
	if (keycode == KEY_UP)
		fr->movey += 0.05;
	if (keycode == KEY_DOWN)
		fr->movey -= 0.05;
	if (keycode == IT_PLUS)
		head->maxiter += 10;
	if (keycode == IT_MINUS)
		head->maxiter -= 10;
	if (keycode == SPACE && head->type == JUL)
		fr->p = (fr->p == 0 ? 1 : 0);
	update(head);
	return (1);
}

int		key(int keycode, t_fr *head)
{
	t_j	*fr;

	if (keycode == 53)
		exit(0);
	if (head->type == JUL)
		fr = &(head->jul);
	else if (head->type == MAN)
		fr = &(head->man);
	else
		fr = &(head->ship);
	if (keycode == KEY_RETURN)
		next_fractol(head);
	return (key_two(keycode, head, fr));
}

int		zoom(int button, int x, int y, t_fr *head)
{
	t_j	*fr;

	if (head->type == JUL)
		fr = &(head->jul);
	else if (head->type == MAN)
		fr = &(head->man);
	else
		fr = &(head->ship);
	if (button == 5)
		fr->zoom *= 1.12;
	if (button == 4)
		fr->zoom /= 1.12;
	update(head);
	return (0);
}

void	threads(t_fr *head)
{
	t_fr	hd[THREAD];
	int		i;

	i = -1;
	while (++i < THREAD)
	{
		hd[i] = *head;
		hd[i].xstart = 0;
		hd[i].xend = WIDTH;
		hd[i].ystart = HEIGHT / THREAD * i;
		hd[i].yend = HEIGHT / THREAD * (i + 1);
		pthread_create(&head->threads[i], NULL,
		(void *)draw_fractol, (void *)&hd[i]);
	}
	i = -1;
	while (++i < THREAD)
		pthread_join(head->threads[i], NULL);
}
