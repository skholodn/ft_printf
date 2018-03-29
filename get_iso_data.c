/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iso_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:24:23 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 13:21:28 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_iso(int *ymd)
{
	char	*iso;

	iso = ft_strnew_p(10);
	iso[0] = (char)((ymd[0] / 1000) + '0');
	iso[1] = (char)(((ymd[0] / 100) % 10) + '0');
	iso[2] = (char)(((ymd[0] / 10) % 10) + '0');
	iso[3] = (char)((ymd[0] % 10) + '0');
	iso[4] = '-';
	iso[5] = (char)((ymd[1] / 10) + '0');
	iso[6] = (char)((ymd[1] % 10) + '0');
	iso[7] = '-';
	iso[8] = (char)((ymd[2] / 10) + '0');
	iso[9] = (char)((ymd[2] % 10) + '0');
	return (iso);
}

int		check_isodate(int *ymd)
{
	static int	dinm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int			check;

	check = 0;
	if (!(ymd[0] % 400) || (ymd[0] % 100 != 0 && ymd[0] % 4 == 0))
		dinm[1] = 29;
	if (ymd[1] < 13)
	{
		if (ymd[2] <= dinm[ymd[1] - 1])
			check = 1;
	}
	if (check == 1)
		return (1);
	return (0);
}

int		err_isodate(void)
{
	write(1, "<WRONG ISO DATA FORMAT>", 23);
	return (1);
}

void	char_iso(long date, t_e *e)
{
	char	*isod;
	int		ymd[3];

	ymd[0] = 0;
	ymd[1] = 0;
	ymd[2] = 0;
	ymd[2] = (int)(date % (long)100);
	date /= 100;
	ymd[1] = (int)(date % (long)100);
	date /= 100;
	ymd[0] = (int)date;
	if (!check_isodate(ymd))
	{
		if (err_isodate())
			return ;
	}
	isod = str_iso(ymd);
	e->bits_count = (int)write(e->fd, isod, ft_strlen_p(isod));
	free(isod);
}

void	get_iso_data(long date, t_e *e)
{
	if (date < 19000101 || date > 30001231)
	{
		if (err_isodate())
			return ;
	}
	char_iso(date, e);
}
