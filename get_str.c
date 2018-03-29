/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:04:37 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 13:25:18 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_s		*str_init(char *arg, t_e *e)
{
	t_s		*s;
	int		sz_space;

	s = malloc(sizeof(t_s));
	s->size_space = 0;
	s->size_str = (arg == NULL ? 6 : (int)ft_strlen_p(arg));
	if (e->precision < s->size_str && e->precision != -1)
		s->size_str = e->precision;
	s->str = ft_strnew_p((size_t)s->size_str);
	s->str = (arg == NULL ? NULLSTR : BASICSTR);
	if (e->width > s->size_str)
		s->size_space = (e->width - s->size_str);
	sz_space = s->size_space;
	s->space = ft_strnew_p((size_t)sz_space);
	while (--sz_space != -1)
	{
		if (e->f->minus || !e->f->zero)
			s->space[sz_space] = ' ';
		else
			s->space[sz_space] = '0';
	}
	return (s);
}

void	free_str(t_s *s)
{
	ft_strdel_p(&s->str);
	free(s->space);
	s->str = NULL;
	free(s);
}

void	get_str(char *arg, t_e *e)
{
	t_s		*s;

	s = str_init(arg, e);
	if (arg && e->f->minus)
	{
		e->bits_count += write(e->fd, s->str, ft_strlen_p(s->str));
		e->bits_count += write(e->fd, s->space, ft_strlen_p(s->space));
	}
	else
	{
		e->bits_count += write(e->fd, s->space, ft_strlen_p(s->space));
		e->bits_count += write(e->fd, s->str, ft_strlen_p(s->str));
	}
	free_str(s);
}
