/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:40:21 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/15 08:10:53 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_change_col(int k, t_cntr *cr)
{
	if (k == 18)
		cr->n = 1;
	else if (k == 19)
		cr->n = 2;
	else if (k == 20)
		cr->n = 3;
}

static void	ft_change_fract(int k, t_cntr *cr)
{
	if (k == 83)
		ft_init(cr, 1);
	else if (k == 84)
		ft_init(cr, 2);
	else if (k == 85)
		ft_init(cr, 3);
}

static void	ft_mv_1(int k, t_cntr *cr)
{
	if (k == 123)
		cr->mvx -= 0.01;
	else if (k == 124)
		cr->mvx += 0.01;
	else if (k == 125)
		cr->mvy += 0.01;
	else if (k == 126)
		cr->mvy -= 0.01;
	else if (k == 1)
	{
		if (cr->max_iter / 2 > 0)
			cr->max_iter /= 2;
	}
	else if (k == 13)
		cr->max_iter *= 2;
	else if (k == 46)
	{
		if (cr->move)
			cr->move = 0;
		else
			cr->move = 1;
	}
}

static void	ft_mv_2(int k, t_cntr *cr)
{
	if (k == 123)
		cr->mvx += 0.01;
	else if (k == 124)
		cr->mvx -= 0.01;
	else if (k == 125)
		cr->mvy -= 0.01;
	else if (k == 126)
		cr->mvy += 0.01;
	else if (k == 1)
	{
		if (cr->max_iter / 2 > 0)
			cr->max_iter /= 2;
	}
	else if (k == 13)
		cr->max_iter *= 2;
}

int			ft_control(int k, t_cntr *cr)
{
	if (k == 53)
		exit(0);
	mlx_destroy_image(cr->mlx, cr->img);
	if (cr->nbr != 3)
		ft_mv_1(k, cr);
	else
		ft_mv_2(k, cr);
	if (k >= 18 && k <= 20)
		ft_change_col(k, cr);
	else if (k >= 83 && k <= 85)
		ft_change_fract(k, cr);
	ft_create(cr);
	return (0);
}
