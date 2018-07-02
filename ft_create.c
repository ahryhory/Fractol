/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:21:19 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/15 12:26:38 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_crt(t_coord *cd, t_cntr *cr)
{
	if (cr->nbr == 1)
	{
		cd->c_i = (cr->min_i + cr->m_y * cd->i_factr) + cr->mvy - 0.1;
		cd->c_r = (cr->min_r + cr->m_x * cd->r_factr) + cr->mvx + 0.5;
		cd->z_i = (cr->min_i + cd->y * cd->i_factr) + cr->mvy - 0.1;
		cd->z_r = (cr->min_r + cd->x * cd->r_factr) + cr->mvx + 0.5;
	}
	else if (cr->nbr == 2)
	{
		cd->c_i = (cr->min_i + cd->y * cd->i_factr) + cr->mvy - 0.1;
		cd->c_r = (cr->min_r + cd->x * cd->r_factr) + cr->mvx;
		cd->z_i = cd->c_i;
		cd->z_r = cd->c_r;
	}
	else if (cr->nbr == 3)
	{
		cd->c_i = (cr->min_i + cd->y * cd->i_factr) - cr->mvy - 0.5;
		cd->c_r = (cr->min_r + cd->x * cd->r_factr) - cr->mvx;
		cd->z_i = cd->c_i;
		cd->z_r = cd->c_r;
	}
}

static void		ft_ini(t_coord *cd, t_cntr *cr)
{
	int			bpp;
	int			s_l;
	int			endian;

	cd->r_factr = (cr->max_r - cr->min_r) / (cr->w - 1);
	cd->i_factr = (cr->max_i - cr->min_i) / (cr->h - 1);
	cr->img = mlx_new_image(cr->mlx, cr->w, cr->h);
	cr->store = mlx_get_data_addr(cr->img, &bpp, &s_l, &endian);
}

static void		*ft_threads(void *m)
{
	t_thread	*t;
	int			i;

	t = (t_thread *)m;
	t->cd.y = t->cr.h / THREADS * t->id;
	i = 1;
	while (t->cd.y < t->cr.h / THREADS * (t->id + 1))
	{
		i = 1;
		t->cd.x = 0;
		while (t->cd.x < t->cr.w)
		{
			ft_crt(&t->cd, &t->cr);
			ft_iter(&t->cd, &t->cr);
			ft_color(&t->cd, &t->cr, t->cd.y * t->cr.w * 4 + t->cd.x * 4);
			t->cd.x++;
			i++;
		}
		t->cd.y++;
	}
	pthread_exit(NULL);
	return (NULL);
}

void			ft_create(t_cntr *cr)
{
	t_coord		cd;
	t_rend		r;
	int			i;

	ft_ini(&cd, cr);
	i = 0;
	while (i < THREADS)
	{
		r.rend[i].id = i;
		r.rend[i].cr = *cr;
		r.rend[i].cd = cd;
		pthread_create(r.threads + i, NULL, ft_threads, &(r.rend[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(r.threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(cr->mlx, cr->win, cr->img, 0, 0);
}
