/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:04:07 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 12:19:31 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_s		*c_init(t_e *e)
{
	t_s		*s;
	int		sz_space;

	s = malloc(sizeof(t_s));
	s->size_space = 0;
	if (e->width > 0)
		s->size_space = (e->width - 1);
	if (e->f->space && e->width > 0)
		s->size_space += 1;
	sz_space = s->size_space;
	s->space = ft_strnew_p((size_t)sz_space);
	while (--sz_space > -1)
	{
		if (e->f->minus || !e->f->zero)
			s->space[sz_space] = ' ';
		else
			s->space[sz_space] = '0';
	}
	return (s);
}

void	free_c(t_s *s)
{
	free(s->space);
	s->space = NULL;
	free(s);
}

void	get_char(int c, t_e *e)
{
	t_s *s;

	s = c_init(e);
	if (e->f->minus)
	{
		e->bits_count += write(e->fd, &c, 1);
		e->bits_count += write(e->fd, s->space, ft_strlen_p(s->space));
	}
	else
	{
		e->bits_count += write(e->fd, s->space, ft_strlen_p(s->space));
		e->bits_count += write(e->fd, &c, 1);
	}
	free_c(s);
}
