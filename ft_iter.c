/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:27:28 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/14 16:00:49 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_iter_1(t_coord *cd, t_cntr *cr)
{
	int		i;
	double	lg;

	i = 0;
	while (i < cr->max_iter)
	{
		cd->z_r2 = cd->z_r * cd->z_r;
		cd->z_i2 = cd->z_i * cd->z_i;
		if (cd->z_r2 + cd->z_i2 > 4)
			break ;
		cd->z_i = 2 * cd->z_r * cd->z_i + cd->c_i;
		cd->z_r = cd->z_r2 - cd->z_i2 + cd->c_r;
		i++;
	}
	lg = log(2);
	cd->col = i + 1 - (lg / sqrt(cd->z_r2 + cd->z_i2)) / lg;
}

static void	ft_iter_2(t_coord *cd, t_cntr *cr)
{
	int		i;
	double	tmp;
	double	sqt;

	i = 0;
	while (cd->z_r * cd->z_r + cd->z_i * cd->z_i < 4 && i < cr->max_iter)
	{
		tmp = cd->z_i;
		cd->z_i = fabs(cd->z_r * cd->z_i + cd->z_r * cd->z_i + cd->c_i);
		cd->z_r = fabs(cd->z_r * cd->z_r - tmp * tmp + cd->c_r);
		i++;
	}
	sqt = sqrt(cd->z_r * cd->z_r + cd->z_i * cd->z_i);
	tmp = log(2);
	cd->col = i + 1 - (tmp / sqt) / tmp;
}

void		ft_iter(t_coord *cd, t_cntr *cr)
{
	if (cr->nbr != 3)
		ft_iter_1(cd, cr);
	else
		ft_iter_2(cd, cr);
}
