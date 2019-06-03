/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:13:42 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/31 17:13:44 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		move_julia(int x, int y, t_fr *head)
{
	if (head->type == JUL)
	{
		ft_bzero(head->init.addr, WIDTH * HEIGHT * 4);
		head->jul.cim = (((double)x * 2) / WIDTH) - 1;
		head->jul.cre = (((double)y * 2) / HEIGHT) - 1;
		julia(&head->jul, head);
	}
	return (0);
}

void	next_fractol(t_fr *head)
{
	if (head->type == SHIP)
		head->type = MAN;
	else
		head->type += 1;
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
	ft_bzero(head->init.addr, WIDTH * HEIGHT * 4);
	if (keycode == KEY_RETURN)
		next_fractol(head);
	else if (keycode == KEY_PLUS)
		fr->zoom += 0.15;
	else if (keycode == KEY_MINUS)
		fr->zoom -= 0.15;
	else if (keycode == KEY_LEFT)
		fr->movex += 0.05;
	else if (keycode == KEY_RIGHT)
		fr->movex -= 0.05;
	else if (keycode == KEY_UP)
		fr->movey += 0.05;
	else if (keycode == KEY_DOWN)
		fr->movey -= 0.05;
	else if (keycode == IT_PLUS)
		head->maxiter += 10;
	else if (keycode == IT_MINUS)
		head->maxiter -= 10;
	if (head->type == JUL)
		julia(&head->jul, head);
	else if (head->type == MAN)
		man_rot(&head->man, head);
	else
		ship(&head->ship, head);
	return (1);
}

int		mause_close(void *mlx_ptr)
{
	(void)mlx_ptr;
	exit(0);
	return (1);
}

void	error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	start(t_fr *head)
{
	head->init.mlx_ptr = mlx_init();
	head->init.win_ptr = mlx_new_window(head->init.mlx_ptr,
										WIDTH, HEIGHT, "Fract'ol");
	head->init.img_ptr = mlx_new_image(head->init.mlx_ptr, WIDTH, HEIGHT);
	head->init.addr = mlx_get_data_addr(head->init.img_ptr, &head->bpp,
									&head->size_line, &head->endian);
	head->jul.zoom = 1;
	head->man.zoom = 1;
	head->ship.zoom = 1;
	head->maxiter = 150;
	head->jul.movex = 0;
	head->jul.movey = 0;
	head->man.movex = -0.5;
	head->man.movey = 0;
	head->ship.movex = -0.45;
	head->ship.movey = -0.5;
	head->jul.cre = -0.835;
	head->jul.cim = -0.232;
}

int	main(int argc, char **argv)
{
	t_fr	head;

	if (argc != 2)
		error("Usage: ./fractol [fractol_name]\n->Julia\n->Mandelbrot\n->\n");
	if (ft_strequ(argv[1], "Julia"))
	{
		start(&head);
		head.type = JUL;
		draw_fractol(&head);
	}
	else if (ft_strequ(argv[1], "Mandelbrot"))
	{
		start(&head);
		head.type = MAN;
		draw_fractol(&head);
	}
	else if(ft_strequ(argv[1], "Ship"))
	{
		start(&head);
		head.type = SHIP;
		draw_fractol(&head);
	}
	else
		error("Invalid fractol\n");
	mlx_hook(head.init.win_ptr, 2, 0, key, &head);
	mlx_hook(head.init.win_ptr, 17, 0, mause_close, head.init.mlx_ptr);
	mlx_hook(head.init.win_ptr, 6, 1L << 6, move_julia, &head);
	mlx_loop(head.init.mlx_ptr);
	return (0);
}
