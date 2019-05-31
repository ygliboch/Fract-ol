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
# define WIDTH 1000
# define HEIGHT 900
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_PLUS 69
# define KEY_MINUS 78
// # define DEFOLT_COLOR 0xffffff
// # define COLOR1 0x00ff7f
// # define COLOR2 0xff8c00
// # define COLOR3 0xff0000
// # define COLOR4 0x8b0000
# define KEY_U 91
# define KEY_D 84
# define KEY_L 86
# define KEY_R 88
typedef struct	s_init
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
}				t_init;

typedef struct s_fr
{
	t_init		init;
	int			bpp;
	int			endian;
	int			size_line;
}				t_fr;

#endif
