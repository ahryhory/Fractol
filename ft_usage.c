/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:32:13 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/14 21:33:02 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_usage(void)
{
	ft_putendl_fd("usage: ./fractol fractol_name", 2);
	ft_putendl_fd("Name_s: julia, mandelbrot, b_ship", 2);
	exit(0);
}
