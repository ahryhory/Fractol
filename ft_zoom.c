/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:21:07 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/14 22:09:17 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static void		ft_app_zoom(t_cntr *cr, double m_r, double m_i, double zm_fctr)
{
	double	interpolation;

	interpolation = 1.0 / zm_fctr;
	cr->min_r = ft_interpolate(m_r, cr->min_r, interpolation);
	cr->min_i = ft_interpolate(m_i, cr->min_i, interpolation);
	cr->max_r = ft_interpolate(m_r, cr->max_r, interpolation);
	cr->max_i = ft_interpolate(m_i, cr->max_i, interpolation);
}

int				ft_zoom(int k, int x, int y, t_cntr *cr)
{
	double	m_r;
	double	m_i;

	if ((k == 4 || k == 5))
	{
		m_r = (double)x / (cr->w / (cr->max_r - cr->min_r)) + cr->min_r;
		m_i = (double)y / (cr->h / (cr->max_i - cr->min_i)) + cr->min_i;
		if (k == 5)
			ft_app_zoom(cr, m_r, m_i, 1.01);
		else if (k == 4)
			ft_app_zoom(cr, m_r, m_i, 1 / 1.01);
		mlx_destroy_image(cr->mlx, cr->img);
		ft_create(cr);
	}
	return (0);
}
