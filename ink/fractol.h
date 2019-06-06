/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:13:55 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/31 17:13:56 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# define WIDTH		1300
# define HEIGHT		1000
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_PLUS	69
# define KEY_MINUS	78
# define IT_PLUS	24
# define IT_MINUS	27
# define KEY_RETURN	36
# define KEY_U		91
# define KEY_D		84
# define KEY_L		86
# define KEY_R		88
# define THREAD		8
# define SPACE		49

enum			e_type
{
	MAN,
	JUL,
	SHIP
};

typedef struct	s_init
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
}				t_init;

typedef struct	s_j
{
	double		cim;
	double		cre;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		movex;
	double		movey;
	double		zoom;
	int			p;
}				t_j;

typedef struct	s_fr
{
	pthread_t	threads[THREAD];
	t_init		init;
	t_j			jul;
	t_j			man;
	t_j			ship;
	enum e_type	type;
	int			maxiter;
	int			bpp;
	int			endian;
	int			size_line;
	int			xstart;
	int			xend;
	int			ystart;
	int			yend;
}				t_fr;

void			man_rot(t_j *hd, t_fr *head, int y, int x);
void			ft_pixel_put(t_fr *head, int x, int y, int color);
int				which_color(int i, int maxiter);
void			julia(t_j *hd, t_fr *head, int i);
void			ship(t_j *ship, t_fr *hd, int y, int x);
void			*draw_fractol(t_fr *head);
int				move_julia(int x, int y, t_fr *head);
void			threads(t_fr *head);
int				update(t_fr *head);
int				key(int keycode, t_fr *head);
int				zoom(int button, int x, int y, t_fr *head);

#endif
