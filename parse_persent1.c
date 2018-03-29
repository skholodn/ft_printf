/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_persent1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 10:37:35 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 13:42:59 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_precision(t_e *e, char **fmt)
{
	**fmt == '.' ? ((*fmt)++) : 0;
	e->precision = ft_atoi_p(*fmt);
	while (DIGIT(**fmt))
		(*fmt)++;
}

void	find_width(t_e *e, char **fmt)
{
	e->width = ft_atoi_p(*fmt);
	while (DIGIT(**fmt))
		(*fmt)++;
}

void	free_e(t_e *e)
{
	e->mod = 0;
	e->width = 0;
	e->dollar = 0;
	e->f->plus = 0;
	e->f->minus = 0;
	e->f->hash = 0;
	e->f->space = 0;
	e->f->zero = 0;
}

void	find_star(t_e *e, char **fmt, va_list ar)
{
	int		tmp;

	tmp = va_arg(ar, int);
	if (*(*fmt - 1) != '.')
		e->width = MOD(tmp);
	else if (*(*fmt - 1) == '.')
	{
		if (tmp >= 0)
			e->precision = MOD(tmp);
		else
		{
			e->precision = -1;
			(*fmt)++;
			return ;
		}
	}
	if (tmp < 0)
		e->f->minus = 1;
	(*fmt)++;
}

void	find_dollar(char **fmt, t_e *e)
{
	int		a;
	int		i;

	i = 0;
	if ((a = ft_atoi_p(*fmt)))
	{
		while (*(*fmt + i))
		{
			if (*(*fmt + i) == '$')
				break ;
			i++;
		}
		if (*(*fmt + i) == '$')
		{
			(*fmt) = ft_strchr_p(*fmt, '$') + 1;
			e->dollar = a;
		}
	}
}
