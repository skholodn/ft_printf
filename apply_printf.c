/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:33:38 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 12:16:28 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	select_di(t_e *e, va_list ar)
{
	if (e->mod == 0 && e->spec != 'D')
		get_nbr(va_arg(ar, int), e);
	else if (e->mod == 1 && e->spec != 'D')
		get_nbr((char)va_arg(ar, int), e);
	else if (e->mod == 2 && e->spec != 'D')
		get_nbr((short)va_arg(ar, int), e);
	else if (e->mod == 3 || e->spec == 'D')
		get_nbr(va_arg(ar, long int), e);
	else if (e->mod == 4 && e->spec != 'D')
		get_nbr(va_arg(ar, long long int), e);
	else if (e->mod == 5 && e->spec != 'D')
		get_nbr(va_arg(ar, size_t), e);
	else if (e->mod == 6 && e->spec != 'D')
		get_nbr(va_arg(ar, intmax_t), e);
}

void	select_u(t_e *e, va_list ar)
{
	if (e->mod == 0 && e->spec == 'u')
		get_unbr(va_arg(ar, unsigned int), e);
	else if (e->mod == 1 && e->spec == 'u')
		get_unbr((unsigned char)va_arg(ar, unsigned int), e);
	else if (e->mod == 2 && e->spec == 'u')
		get_unbr((unsigned short int)va_arg(ar, unsigned int), e);
	else if (e->mod == 3 || e->spec == 'U')
		get_unbr(va_arg(ar, unsigned long int), e);
	else if (e->mod == 4 && e->spec == 'u')
		get_unbr(va_arg(ar, unsigned long long int), e);
	else if (e->mod == 5 && e->spec == 'u')
		get_unbr(va_arg(ar, size_t), e);
	else if (e->mod == 6 && e->spec == 'u')
		get_unbr(va_arg(ar, uintmax_t), e);
}

void	select_oxp(t_e *e, va_list ar)
{
	if (e->mod == 0 && e->spec != 'O' && e->spec != 'p')
		get_oxp(va_arg(ar, unsigned int), e);
	else if (e->mod == 1 && e->spec != 'O' && e->spec != 'p')
		get_oxp((unsigned char)va_arg(ar, unsigned int), e);
	else if (e->mod == 2 && e->spec != 'O' && e->spec != 'p')
		get_oxp((unsigned short int)va_arg(ar, unsigned int), e);
	else if (e->mod == 3 || e->spec == 'O' || e->spec == 'p')
		get_oxp(va_arg(ar, unsigned long int), e);
	else if (e->mod == 4 && e->spec != 'O' && e->spec != 'p')
		get_oxp(va_arg(ar, unsigned long long int), e);
	else if (e->mod == 5 && e->spec != 'O' && e->spec != 'p')
		get_oxp(va_arg(ar, size_t), e);
	else if (e->mod == 6 && e->spec != 'O' && e->spec != 'p')
		get_oxp(va_arg(ar, uintmax_t), e);
}

void	select_efga(t_e *e, va_list ar)
{
	if (e->mod != 7 && (e->spec == 'f' || e->spec == 'F'))
		get_f(va_arg(ar, double), e);
	else if (e->mod == 7 && (e->spec == 'f' || e->spec == 'F'))
		get_f(va_arg(ar, long double), e);
}

void	make_fprintf(t_e *e, va_list ar)
{
	if (e->spec == 's' && e->mod != 3)
		get_str(va_arg(ar, char *), e);
	else if (e->spec == 'c' || e->spec == 'C')
		get_char(va_arg(ar, int), e);
	else if (e->spec == 'd' || e->spec == 'i' || e->spec == 'D')
		select_di(e, ar);
	else if (e->spec == 'u' || e->spec == 'U')
		select_u(e, ar);
	else if (e->spec == 'o' || e->spec == 'x' || e->spec == 'O' ||
			e->spec == 'X' || e->spec == 'p')
		select_oxp(e, ar);
	else if (e->spec == 'S' || e->spec == 's')
		get_wstr(va_arg(ar, wchar_t*), e);
	else if (e->spec == 'n')
		get_n(va_arg(ar, int*), e);
	else if (e->spec == 'f' || e->spec == 'F')
		select_efga(e, ar);
	else if (e->spec == 'b' || e->spec == 'k' || e->spec == 'r')
		select_bonus(e, ar);
	else
		apply_width(e);
}
