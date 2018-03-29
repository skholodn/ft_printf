/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_printf1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:24:17 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 13:34:16 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup_p(const char *src)
{
	int		lng;
	char	*copy;

	lng = 0;
	while (src[lng])
		lng++;
	copy = (char *)malloc(sizeof(char) * (lng + 1));
	if (!copy)
		return (0);
	ft_strcpy_p(copy, src);
	return (copy);
}

void	ft_strdel_p(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

void	get_if_oxp(uintmax_t *nb, t_e *e, t_oxp *oxp)
{
	if (e->precision > e->width || e->precision > oxp->size_nbr)
		oxp->size_zero = ((P_N_X < 0 ? 0 : P_N_X)
				- (GET_O ? oxp->size_prefix : 0));
	else if ((e->precision < e->width) && e->f->zero && !e->f->minus)
		oxp->size_zero = (W_N_X < 0 ? 0 : W_N_X - oxp->size_prefix);
	if ((e->precision < e->width) && (oxp->size_nbr < e->width)
			&& (!e->f->zero || e->f->minus))
		oxp->size_space = (e->width
				- (e->precision < oxp->size_nbr ? P_Z : P_PRE) - P_P);
	else if ((e->precision > e->width)
			&& (oxp->size_nbr < e->precision) && e->f->zero)
		oxp->size_space = (e->precision - oxp->size_nbr);
	(void)nb;
}

void	select_bonus(t_e *e, va_list ar)
{
	if (e->spec == 'b')
		get_noprint(va_arg(ar, char *), e);
	else if (e->spec == 'k')
		get_iso_data(va_arg(ar, long), e);
	else if (e->spec == 'r')
		get_binary(va_arg(ar, int), e);
}

void	free_wstr(t_s *s)
{
	free(s->str);
	s->str = NULL;
	free(s->space);
	s->space = NULL;
	free(s);
}
