/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:02:51 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 12:23:22 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_size_nb(uintmax_t nb)
{
	int		i;

	i = 1;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void		init_char_di(t_di *di, intmax_t nb, t_e *e)
{
	int		sz_zero;
	int		sz_space;

	sz_space = di->size_space;
	sz_zero = di->size_zero;
	di->nbr = (e->precision == 0 && !nb ? ft_strnew_p(0)
			: u_itoa_base((uintmax_t)MOD(nb), 10));
	di->zero = ft_strnew_p((size_t)sz_zero);
	while (--sz_zero >= 0)
		di->zero[sz_zero] = '0';
	di->space = ft_strnew_p((size_t)sz_space);
	while (--sz_space >= 0)
		di->space[sz_space] = ' ';
	di->sign = ft_strnew_p(1);
	if (di->size_sign && nb < 0)
		di->sign[0] = '-';
	else if (di->size_sign && e->f->plus)
		di->sign[0] = '+';
	else if (di->size_sign && e->f->space)
		di->sign[0] = ' ';
}

t_di		*init_di(intmax_t nb, t_e *e)
{
	t_di		*di;

	di = malloc(sizeof(t_di));
	di->size_nbr = get_size_nb((uintmax_t)MOD(nb));
	di->size_sign = 0;
	di->size_space = 0;
	di->size_zero = 0;
	if ((nb < 0 || e->f->plus || e->f->space))
		di->size_sign = 1;
	else if (nb == 0 && e->precision == 0)
		di->size_nbr = 0;
	if (e->precision > di->size_nbr)
		di->size_zero = e->precision - di->size_nbr;
	else if (e->precision < di->size_nbr && e->f->zero && !e->f->minus)
		di->size_zero = e->width - di->size_nbr - di->size_sign;
	di->size_space = (e->width - (e->precision > di->size_nbr ?
				e->precision : (di->size_nbr + di->size_zero)) - di->size_sign);
	init_char_di(di, nb, e);
	return (di);
}

void		free_di(t_di *di)
{
	free(di->space);
	di->space = NULL;
	free(di->sign);
	di->sign = NULL;
	free(di->zero);
	di->zero = NULL;
	free(di->nbr);
	di->nbr = NULL;
	free(di);
}

void		get_nbr(intmax_t nb, t_e *e)
{
	t_di		*di;

	di = init_di(nb, e);
	if (e->f->minus == 1)
	{
		e->bits_count += write(e->fd, di->sign, ft_strlen_p(di->sign));
		e->bits_count += write(e->fd, di->zero, ft_strlen_p(di->zero));
		e->bits_count += write(e->fd, di->nbr, ft_strlen_p(di->nbr));
		e->bits_count += write(e->fd, di->space, ft_strlen_p(di->space));
	}
	else
	{
		e->bits_count += write(e->fd, di->space, ft_strlen_p(di->space));
		e->bits_count += write(e->fd, di->sign, ft_strlen_p(di->sign));
		e->bits_count += write(e->fd, di->zero, ft_strlen_p(di->zero));
		e->bits_count += write(e->fd, di->nbr, ft_strlen_p(di->nbr));
	}
	free_di(di);
}
