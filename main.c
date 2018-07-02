/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:54:31 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/14 22:27:41 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_exit(void)
{
	exit(0);
	return (0);
}

static void		ft_init_m(t_cntr *cr)
{
	cr->h = 800;
	cr->w = 900;
	cr->mlx = mlx_init();
	cr->win = mlx_new_window(cr->mlx, cr->w, cr->h, "FRACT_OL");
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
}

int				main(int ac, char **av)
{
	t_cntr		cr;

	if (ac != 2)
		ft_usage();
	ft_check(&cr, av[1]);
	ft_init_m(&cr);
	ft_create(&cr);
	mlx_hook(cr.win, 2, 5, ft_control, &cr);
	mlx_hook(cr.win, 17, 1L << 17, ft_exit, 0);
	mlx_hook(cr.win, 4, 1L << 2, ft_zoom, &cr);
	mlx_hook(cr.win, 6, 1L << 6, ft_move, &cr);
	mlx_loop(cr.mlx);
	return (0);
}
