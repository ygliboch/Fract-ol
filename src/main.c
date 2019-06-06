/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:13:42 by yhliboch          #+#    #+#             */
/*   Updated: 2019/06/06 16:24:29 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		update(t_fr *head)
{
	ft_bzero(head->init.addr, WIDTH * HEIGHT * 4);
	threads(head);
	mlx_put_image_to_window(head->init.mlx_ptr, head->init.win_ptr,
									head->init.img_ptr, 0, 0);
	return (0);
}

int		mause_close(void *mlx_ptr)
{
	(void)mlx_ptr;
	exit(0);
	return (1);
}

void	error(void)
{
	ft_printf("Usage: ./fractol [fractol_name]\n->Julia\n->Mandelbrot\n->Ship\n");
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
	head->maxiter = 80;
	head->jul.movex = 0;
	head->jul.movey = 0;
	head->man.movex = -0.5;
	head->man.movey = 0;
	head->ship.movex = -0.45;
	head->ship.movey = -0.5;
	head->jul.cre = -0.835;
	head->jul.cim = -0.232;
	head->jul.p = 1;
}

int		main(int argc, char **argv)
{
	t_fr	head;

	if (argc != 2)
		error();
	if (ft_strequ(argv[1], "Julia"))
		head.type = JUL;
	else if (ft_strequ(argv[1], "Mandelbrot"))
		head.type = MAN;
	else if (ft_strequ(argv[1], "Ship"))
		head.type = SHIP;
	else
		error();
	start(&head);
	mlx_expose_hook(head.init.win_ptr, update, &head);
	mlx_hook(head.init.win_ptr, 4, 1L << 2, zoom, &head);
	mlx_hook(head.init.win_ptr, 2, 0, key, &head);
	mlx_hook(head.init.win_ptr, 17, 0, mause_close, head.init.mlx_ptr);
	mlx_hook(head.init.win_ptr, 6, 1L << 6, move_julia, &head);
	mlx_loop(head.init.mlx_ptr);
	return (0);
}
