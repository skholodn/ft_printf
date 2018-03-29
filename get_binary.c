/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:57:01 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 12:50:02 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_binary(unsigned char c, t_e *e)
{
	char	*bit;
	int		count;
	int		i;

	i = 0;
	count = 128;
	bit = ft_strnew_p(8);
	while (i < 8)
	{
		if (c >= count)
		{
			bit[i] = '1';
			c -= count;
		}
		else
			bit[i] = '0';
		if (!(c % count))
			c = 0;
		count /= 2;
		i++;
	}
	e->bits_count = (int)write(e->fd, bit, ft_strlen_p(bit));
	free(bit);
}
