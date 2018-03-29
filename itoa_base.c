/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:47:14 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 13:29:56 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_make_str(uintmax_t value, uintmax_t base, char *str, int *i)
{
	static char	*a = "0123456789ABCDEF";

	if (value >= base)
		u_make_str(value / base, base, str, i);
	str[(*i)++] = a[MOD(value % base)];
}

char	*u_itoa_base(uintmax_t value, uintmax_t base)
{
	char	*str;
	int		i;

	if (base < 2 || base > 16 || !(str = ft_strnew_p(60)))
		return (0);
	i = 0;
	u_make_str(value, base, str, &i);
	str[i] = '\0';
	return (str);
}

void	itoa_float(t_e *e, t_float *f, int i)
{
	f->size_dot = (f->size_presigion || e->f->hash) ? 1 : 0;
	f->total_size = f->size_sign + f->size_exponenta + f->size_dot
		+ f->size_presigion;
	if (e->f->zero && e->width > f->total_size && !e->f->minus)
	{
		f->size_width_len = e->width - f->total_size;
		f->total_size = e->width;
	}
	f->str = ft_strnew_p((size_t)f->total_size);
	f->s = f->str;
	if (f->sign != 0)
	{
		*f->str = f->sign;
		f->str++;
		i++;
	}
	while ((f->size_width_len - f->size_sign) > i++)
	{
		*f->str = '0';
		f->str++;
	}
}

char	*itoa_double(long double val, t_e *e)
{
	t_float	*f;

	f = init_float(&val, e);
	itoa_float(e, f, 0);
	put_nb_str(f->round_nb, &f->str);
	if (f->size_dot)
	{
		*f->str = '.';
		f->str++;
	}
	if (f->size_presigion > 0 && f->size_presigion < 16)
		round_me_d(MOD(val) - (long double)f->round_nb, e, f->str);
	else
		round_me(MOD(val) - (long double)f->round_nb, e, f->str);
	return (f->s);
}
