/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_printable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:56:25 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 13:35:34 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	noprt_f(char c, t_e *e)
{
	if (c == 1)
		e->bits_count += (int)write(e->fd, NP_SOH, ft_strlen_p(NP_SOH));
	else if (c == 2)
		e->bits_count += (int)write(e->fd, NP_STX, ft_strlen_p(NP_STX));
	else if (c == 3)
		e->bits_count += (int)write(e->fd, NP_ETX, ft_strlen_p(NP_ETX));
	else if (c == 4)
		e->bits_count += (int)write(e->fd, NP_EOT, ft_strlen_p(NP_EOT));
	else if (c == 5)
		e->bits_count += (int)write(e->fd, NP_ENQ, ft_strlen_p(NP_ENQ));
	else if (c == 6)
		e->bits_count += (int)write(e->fd, NP_ACK, ft_strlen_p(NP_ACK));
	else if (c == 7)
		e->bits_count += (int)write(e->fd, NP_BEL, ft_strlen_p(NP_BEL));
	else if (c == 8)
		e->bits_count += (int)write(e->fd, NP_BS, ft_strlen_p(NP_BS));
	else if (c == 9)
		e->bits_count += (int)write(e->fd, NP_HT, ft_strlen_p(NP_HT));
	else if (c == 10)
		e->bits_count += (int)write(e->fd, NP_LF, ft_strlen_p(NP_LF));
}

void	noprt_s(char c, t_e *e)
{
	if (c == 11)
		e->bits_count += (int)write(e->fd, NP_VT, ft_strlen_p(NP_VT));
	else if (c == 12)
		e->bits_count += (int)write(e->fd, NP_FF, ft_strlen_p(NP_FF));
	else if (c == 13)
		e->bits_count += (int)write(e->fd, NP_CR, ft_strlen_p(NP_CR));
	else if (c == 14)
		e->bits_count += (int)write(e->fd, NP_SO, ft_strlen_p(NP_SO));
	else if (c == 15)
		e->bits_count += (int)write(e->fd, NP_SI, ft_strlen_p(NP_SI));
	else if (c == 16)
		e->bits_count += (int)write(e->fd, NP_DLE, ft_strlen_p(NP_DLE));
	else if (c == 17)
		e->bits_count += (int)write(e->fd, NP_DC1, ft_strlen_p(NP_DC1));
	else if (c == 18)
		e->bits_count += (int)write(e->fd, NP_DC2, ft_strlen_p(NP_DC2));
	else if (c == 19)
		e->bits_count += (int)write(e->fd, NP_DC3, ft_strlen_p(NP_DC3));
	else if (c == 20)
		e->bits_count += (int)write(e->fd, NP_DC4, ft_strlen_p(NP_DC4));
}

void	noprt_t(char c, t_e *e)
{
	if (c == 21)
		e->bits_count += (int)write(e->fd, NP_NAK, ft_strlen_p(NP_NAK));
	else if (c == 22)
		e->bits_count += (int)write(e->fd, NP_SYN, ft_strlen_p(NP_SYN));
	else if (c == 23)
		e->bits_count += (int)write(e->fd, NP_ETB, ft_strlen_p(NP_ETB));
	else if (c == 24)
		e->bits_count += (int)write(e->fd, NP_CAN, ft_strlen_p(NP_CAN));
	else if (c == 25)
		e->bits_count += (int)write(e->fd, NP_EM, ft_strlen_p(NP_EM));
	else if (c == 26)
		e->bits_count += (int)write(e->fd, NP_SUB, ft_strlen_p(NP_SUB));
	else if (c == 27)
		e->bits_count += (int)write(e->fd, NP_ESC, ft_strlen_p(NP_ESC));
	else if (c == 28)
		e->bits_count += (int)write(e->fd, NP_FS, ft_strlen_p(NP_FS));
	else if (c == 29)
		e->bits_count += (int)write(e->fd, NP_GS, ft_strlen_p(NP_GS));
	else if (c == 30)
		e->bits_count += (int)write(e->fd, NP_RS, ft_strlen_p(NP_RS));
	else if (c == 31)
		e->bits_count += (int)write(e->fd, NP_US, ft_strlen_p(NP_US));
}

void	noprtswitch(char c, t_e *e)
{
	if (c < 11)
		noprt_f(c, e);
	else if (c < 21)
		noprt_s(c, e);
	else if (c < 32)
		noprt_t(c, e);
}

void	get_noprint(char *str, t_e *e)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str > 32)
		{
			e->bits_count += (int)write(e->fd, NP_CHAR, ft_strlen_p(NP_CHAR));
			return ;
		}
		noprtswitch(*str, e);
		str++;
	}
	e->bits_count += (int)write(e->fd, NP_NULL, ft_strlen_p(NP_NULL));
}
