/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:34:53 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/14 22:10:59 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_move(int x, int y, t_cntr *cr)
{
	int		mv;

	mv = cr->move;
	if (cr->nbr == 1 && x >= 0 && x <= cr->w && y >= 0 && y <= cr->h && mv)
	{
		mlx_destroy_image(cr->mlx, cr->img);
		cr->m_x = x;
		cr->m_y = y;
		ft_create(cr);
	}
	return (0);
}
