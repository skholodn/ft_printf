/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_persent2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 10:41:58 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 13:44:02 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_dollar(va_list ar, va_list tmp, int i)
{
	va_copy(ar, tmp);
	while (--i)
		va_arg(ar, int);
}

void	parse_persent(t_e *e, char **fmt, va_list ar, va_list tmp)
{
	(*fmt)++;
	while (**fmt)
	{
		find_dollar(fmt, e);
		if (find_flag(e, **fmt))
			(*fmt)++;
		else if (find_mod(e, fmt))
			;
		else if (**fmt == '.')
			find_precision(e, fmt);
		else if (**fmt == '*')
			find_star(e, fmt, ar);
		else if (DIGIT(**fmt))
			find_width(e, fmt);
		else if (find_conver(e, **fmt) || (e->spec = *(*fmt)))
			break ;
	}
	if (e->dollar)
		apply_dollar(ar, tmp, e->dollar);
	(*fmt) += 1;
	if (e->spec != '\0')
		make_fprintf(e, ar);
	free_e(e);
}
