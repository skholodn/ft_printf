/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:38:34 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 13:40:28 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strstr_stop(const char *str, const char *to_find)
{
	int		a;
	int		b;
	size_t	len;

	a = 0;
	b = 0;
	len = ft_strlen_p(to_find);
	while (len--)
	{
		if (to_find[b++] != str[a++])
			return (0);
	}
	return (1);
}

int		parse_color_inside(t_e *e, char *fmt)
{
	if (ft_strstr_stop(fmt, DARK_GRAY_COLOR))
		return ((int)write(e->fd, DARK_GRAY, ft_strlen_p(DARK_GRAY)));
	else if (ft_strstr_stop(fmt, LIGHT_RED_COLOR))
		return ((int)write(e->fd, LIGHT_RED, ft_strlen_p(LIGHT_RED)));
	else if (ft_strstr_stop(fmt, LIGHT_GREEN_COLOR))
		return ((int)write(e->fd, LIGHT_GREEN, ft_strlen_p(LIGHT_GREEN)));
	else if (ft_strstr_stop(fmt, LIGHT_YELLOW_COLOR))
		return ((int)write(e->fd, LIGHT_YELLOW, ft_strlen_p(LIGHT_YELLOW)));
	else if (ft_strstr_stop(fmt, LIGHT_BLUE_COLOR))
		return ((int)write(e->fd, LIGHT_BLUE, ft_strlen_p(LIGHT_BLUE)));
	else if (ft_strstr_stop(fmt, LIGHT_MAGENTA_COLOR))
		return ((int)write(e->fd, LIGHT_MAGENTA, ft_strlen_p(LIGHT_MAGENTA)));
	else if (ft_strstr_stop(fmt, LIGHT_CYAN_COLOR))
		return ((int)write(e->fd, LIGHT_CYAN, ft_strlen_p(LIGHT_CYAN)));
	else if (ft_strstr_stop(fmt, WHITE_COLOR))
		return ((int)write(e->fd, WHITE, ft_strlen_p(WHITE)));
	else if (ft_strstr_stop(fmt, EOC_COLOR))
		return ((int)write(e->fd, EOC, ft_strlen_p(EOC)));
	else if (ft_strstr_stop(fmt, GRAY_COLOR))
		return ((int)write(e->fd, GRAY, ft_strlen_p(GRAY)));
	return (0);
}

int		parse_color(t_e *e, char *fmt, va_list ar)
{
	if (ft_strstr_stop(fmt, BLACK_COLOR))
		return ((int)write(e->fd, BLACK, ft_strlen_p(BLACK)));
	else if (ft_strstr_stop(fmt, RED_COLOR))
		return ((int)write(e->fd, RED, ft_strlen_p(RED)));
	else if (ft_strstr_stop(fmt, GREEN_COLOR))
		return ((int)write(e->fd, GREEN, ft_strlen_p(GREEN)));
	else if (ft_strstr_stop(fmt, BROWN_COLOR))
		return ((int)write(e->fd, BROWN, ft_strlen_p(BROWN)));
	else if (ft_strstr_stop(fmt, BLUE_COLOR))
		return ((int)write(e->fd, BLUE, ft_strlen_p(BLUE)));
	else if (ft_strstr_stop(fmt, MAGENTA_COLOR))
		return ((int)write(e->fd, MAGENTA, ft_strlen_p(MAGENTA)));
	else if (ft_strstr_stop(fmt, CYAN_COLOR))
		return ((int)write(e->fd, CYAN, ft_strlen_p(CYAN)));
	else if (parse_color_inside(e, fmt))
		return (1);
	else if (ft_strstr_stop(fmt, "{fd}"))
	{
		e->fd = va_arg(ar, int);
		return (1);
	}
	return (0);
}

void	find_color(t_e *e, char **fmt, va_list ar)
{
	if (!parse_color(e, *fmt, ar))
	{
		e->bits_count += write(1, "{", 1);
		(*fmt)++;
	}
	else
		*fmt = ft_strchr_p(*fmt, '}') + 1;
}
