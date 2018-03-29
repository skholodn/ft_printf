/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:49:25 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 12:25:31 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_nb_str(uintmax_t nb, char **str)
{
	if (nb >= 10)
	{
		put_nb_str(nb / 10, str);
		put_nb_str(nb % 10, str);
	}
	else
	{
		**str = (char)(nb + '0');
		(*str)++;
	}
}

void	round_me_d(long double nb, t_e *e, char *str)
{
	long double	nb_len;
	int			if_prec;

	if_prec = e->precision;
	while (if_prec > 0 && if_prec-- > 0)
		nb *= 10;
	nb_len = fraction_nb(nb);
	if_prec = e->precision - get_size_nb((uintmax_t)nb_len);
	while (if_prec > 0 && if_prec-- > 0)
	{
		*str = '0';
		str++;
	}
	put_nb_str(nb_len, &str);
}

void	round_me(long double nb, t_e *e, char *str)
{
	int		if_prec;
	int		i;

	if_prec = e->precision;
	while (if_prec > 0)
	{
		nb *= 10;
		if (if_prec == 1)
			nb = fraction_nb(nb);
		i = (int)nb;
		*str = i + '0';
		nb = nb - i;
		str++;
		if_prec--;
	}
}

t_float	*init_float(long double *val, t_e *e)
{
	t_float	*f;

	f = malloc(sizeof(t_float));
	f->size_sign = 0;
	f->sign = 0;
	if (*val < 0 || (1 / *val) < 0)
	{
		*val = MOD(*val);
		f->sign = '-';
	}
	else if (e->f->plus)
		f->sign = '+';
	else if (e->f->space)
		f->sign = ' ';
	if (f->sign == ' ' || f->sign == '-' || f->sign == '+')
		f->size_sign = 1;
	if (e->precision == 0)
		*val = fraction_nb(*val);
	f->round_nb = (long long)MOD(*val);
	f->size_exponenta = get_size_nb(f->round_nb);
	f->size_width_len = 0;
	f->size_presigion = e->precision;
	return (f);
}

void	get_f(long double nb, t_e *e)
{
	char	*res;

	res = NULL;
	if (e->f->minus)
		e->f->zero = 0;
	if (e->precision == -1)
		e->precision = 6;
	if (nb != nb)
		res = (e->spec == 'f') ? ft_strdup_p("nan") : ft_strdup_p("NAN");
	else if (nb == -0.1 / 0.0)
		res = (e->spec == 'f') ? ft_strdup_p("-inf") : ft_strdup_p("-INF");
	else if (nb == 0.1 / 0.0)
		res = (e->spec == 'f') ? ft_strdup_p("inf") : ft_strdup_p("INF");
	if (res == NULL)
		res = itoa_double(nb, e);
	e->bits_count += write(e->fd, res, ft_strlen_p(res));
	free(res);
}
