/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:59:04 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/14 22:24:02 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "includes/libft/libft.h"
# include <pthread.h>

# define THREADS 8

typedef struct		s_coord
{
	double			r_factr;
	double			i_factr;
	double			c_i;
	double			c_r;
	double			z_i;
	double			z_r;
	double			z_i2;
	double			z_r2;
	int				col;
	int				x;
	int				y;
}					t_coord;

typedef struct		s_cntr
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*store;
	int				h;
	int				w;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			zm;
	int				m_x;
	int				m_y;
	int				move;
	double			mvx;
	double			mvy;
	int				max_iter;
	int				nbr;
	int				n;
}					t_cntr;

typedef struct		s_thread
{
	int				id;
	t_cntr			cr;
	t_coord			cd;
}					t_thread;

typedef struct		s_rend
{
	t_thread		rend[THREADS];
	pthread_t		threads[THREADS];
}					t_rend;

int					ft_usage(void);
void				ft_create(t_cntr *cr);
int					ft_zoom(int k, int x, int y, t_cntr *cr);
void				ft_color(t_coord *cd, t_cntr *cr, int i);
int					ft_move(int x, int y, t_cntr *cr);
void				ft_iter(t_coord *cd, t_cntr *cr);
int					ft_control(int k, t_cntr *cr);
void				ft_check(t_cntr *cr, char *s);
void				ft_init(t_cntr *cr, int nbr);

#endif
