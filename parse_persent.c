/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_persent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:14:39 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 13:41:29 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_flag(t_e *e, char c)
{
	if (c == '+')
		e->f->plus = 1;
	else if (c == '-')
		e->f->minus = 1;
	else if (c == ' ')
		e->f->space = 1;
	else if (c == '#')
		e->f->hash = 1;
	else if (c == '0')
		e->f->zero = 1;
	if (c == '+' || c == '-' || c == ' ' || c == '#' || c == '0' || c == '\'')
		return (1);
	return (0);
}

int		find_mod_mv(char **fmt)
{
	if (**fmt == 'h' || **fmt == 'l' || **fmt == 'z' || **fmt == 'j')
	{
		(*fmt)++;
		return (1);
	}
	return (0);
}

int		find_mod_mv_two(char **fmt)
{
	if (H_H || L_L)
	{
		(*fmt) += 2;
		return (1);
	}
	return (0);
}

int		find_mod(t_e *e, char **fmt)
{
	if (**fmt == 'h' && *(*fmt + 1) == 'h' && e->mod <= 1)
		e->mod = 1;
	else if (**fmt == 'h' && e->mod <= 2)
		e->mod = 2;
	else if (**fmt == 'l' && e->mod <= 3)
		e->mod = 3;
	else if (**fmt == 'l' && *(*fmt + 1) == 'l' && e->mod <= 4)
		e->mod = 4;
	else if (**fmt == 'z' && e->mod <= 5)
		e->mod = 5;
	else if (**fmt == 'j' && e->mod <= 6)
		e->mod = 6;
	else if (**fmt == 'L' && e->mod <= 7)
		e->mod = 7;
	if (find_mod_mv_two(fmt))
		return (1);
	else if (find_mod_mv(fmt))
		return (1);
	return (0);
}

int		find_conver(t_e *e, char c)
{
	int		i;

	i = 0;
	while (SPEC[i])
	{
		if (SPEC[i] == c ? e->spec = c : 0)
			return (1);
		i++;
	}
	return (0);
}
