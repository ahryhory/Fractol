/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:04:14 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/14 21:33:37 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_check(t_cntr *cr, char *s)
{
	if (ft_strequ(s, "julia"))
		cr->nbr = 1;
	else if (ft_strequ(s, "mandelbrot"))
		cr->nbr = 2;
	else if (ft_strequ(s, "b_ship"))
		cr->nbr = 3;
	else
		ft_usage();
}
