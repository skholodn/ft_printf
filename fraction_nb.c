/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraction_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:59:28 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 12:26:34 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_ceil(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr <= i)
		return (i);
	return (i + 1);
}

long double	ft_floor(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr >= i)
		return (i);
	return (i - 1);
}

long double	fraction_nb(long double nbr)
{
	if (nbr - ft_floor(nbr) == 0.5 && (long long)ft_floor(nbr) % 2 == 0)
		return (ft_floor(nbr));
	else if (ft_ceil(nbr) - nbr == 0.5)
		return (ft_ceil(nbr));
	if (nbr - ft_floor(nbr) >= 0.5)
		return (ft_ceil(nbr));
	else
		return (ft_floor(nbr));
}
