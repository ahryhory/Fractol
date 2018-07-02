/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:12:58 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/14 22:23:40 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init(t_cntr *cr, int nbr)
{
	cr->max_iter = 30;
	cr->n = 1;
	cr->mvx = 0;
	cr->mvy = 0;
	cr->m_x = 450;
	cr->m_y = 400;
	cr->move = 1;
	cr->zm = 1;
	cr->min_r = -2.0;
	cr->max_r = 1.0;
	cr->min_i = -1.2;
	cr->max_i = cr->min_i + (cr->max_r - cr->min_r) * cr->h / cr->w;
	cr->nbr = nbr;
}
