/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:03:04 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 13:45:36 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_char_u(t_e *e, t_u *u, uintmax_t nb)
{
	int		sz_zero;
	int		sz_space;

	sz_space = u->size_space;
	sz_zero = u->size_zero;
	u->nbr = (e->precision != -1 && !nb ? ft_strnew_p(0) : u_itoa_base(nb, 10));
	u->zero = ft_strnew_p((size_t)sz_zero);
	while (--sz_zero != -1)
		u->zero[sz_zero] = '0';
	u->space = ft_strnew_p((size_t)sz_space);
	while (--sz_space != -1)
		u->space[sz_space] = ' ';
}

t_u		*init_u(uintmax_t nb, t_e *e)
{
	t_u		*u;

	u = malloc(sizeof(t_u));
	u->size_nbr = get_size_nb(nb);
	u->size_space = 0;
	u->size_zero = 0;
	if (e->precision > u->size_nbr)
		u->size_zero = (P_N_U < 0 ? 0 : P_N_U);
	else if ((e->precision < e->width) && e->f->zero)
		u->size_zero = (W_N_U < 0 ? 0 : W_N_U);
	if ((e->precision < e->width) && (u->size_nbr < e->width) && !e->f->zero)
		u->size_space = (e->width - (e->precision > u->size_nbr ? e->precision
					: (u->size_nbr + u->size_zero)));
	init_char_u(e, u, nb);
	return (u);
}

void	free_u(t_u *u)
{
	free(u->space);
	u->space = NULL;
	free(u->zero);
	u->zero = NULL;
	free(u->nbr);
	u->nbr = NULL;
	free(u);
}

void	get_unbr(uintmax_t nb, t_e *e)
{
	t_u		*u;

	u = init_u(nb, e);
	if (e->f->minus == 1)
	{
		e->bits_count += write(e->fd, u->zero, ft_strlen_p(u->zero));
		e->bits_count += write(e->fd, u->nbr, ft_strlen_p(u->nbr));
		e->bits_count += write(e->fd, u->space, ft_strlen_p(u->space));
	}
	else
	{
		e->bits_count += write(e->fd, u->space, ft_strlen_p(u->space));
		e->bits_count += write(e->fd, u->zero, ft_strlen_p(u->zero));
		e->bits_count += write(e->fd, u->nbr, ft_strlen_p(u->nbr));
	}
	free_u(u);
}
