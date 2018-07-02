/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:33:47 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/14 21:16:47 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_col_gamma(t_coord *cd, t_cntr *cr, int *nbr, int i)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (sin(0.020 * cd->col + nbr[0]) * 230 + 25);
	g = (sin(0.015 * cd->col + nbr[1]) * 230 + 25);
	b = (sin(0.02 * cd->col + nbr[2]) * 230 + 25);
	cr->store[i++] = r;
	cr->store[i++] = g;
	cr->store[i] = b;
}

void		ft_color(t_coord *cd, t_cntr *cr, int i)
{
	int		nbr[3];

	if (cr->n == 1)
	{
		nbr[0] = 4;
		nbr[1] = 2;
		nbr[2] = 1;
	}
	else if (cr->n == 2)
	{
		nbr[0] = 2;
		nbr[1] = 4;
		nbr[2] = 2;
	}
	else
	{
		nbr[0] = 1;
		nbr[1] = 2;
		nbr[2] = 4;
	}
	ft_col_gamma(cd, cr, nbr, i);
}
