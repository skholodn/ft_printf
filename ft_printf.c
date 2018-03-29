/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:49:56 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 12:30:17 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fl	*init_flags(void)
{
	t_fl	*flag;

	flag = malloc(sizeof(t_fl));
	flag->plus = 0;
	flag->minus = 0;
	flag->hash = 0;
	flag->space = 0;
	flag->zero = 0;
	return (flag);
}

t_e		*env_init(int bits)
{
	t_e		*env;

	env = (t_e *)malloc(sizeof(t_e));
	env->bits_count = bits;
	env->mod = 0;
	env->width = 0;
	env->precision = -1;
	env->dollar = 0;
	env->spec = 0;
	env->f = init_flags();
	env->dollar = 0;
	env->fd = 1;
	return (env);
}

void	str_cpy(t_e *e, char **fmt)
{
	while (1)
	{
		if (**fmt == '%' || **fmt == '{' || **fmt == 0)
			return ;
		e->bits_count += write(1, *fmt, 1);
		(*fmt)++;
	}
}

int		ft_vsprintf(int bits_count, char *fmt, va_list ar)
{
	t_e		*e;
	int		bits;
	va_list	tmp;

	va_copy(tmp, ar);
	e = env_init(bits_count);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			parse_persent(e, &fmt, ar, tmp);
			if (e->spec == '\0')
				return (0);
		}
		else if ('{' == *fmt)
			find_color(e, &fmt, ar);
		else
			str_cpy(e, &fmt);
	}
	bits = e->bits_count;
	free(e->f);
	free(e);
	return (bits);
}

int		ft_printf(char *fmt, ...)
{
	va_list	ar;
	int		bits_count;

	bits_count = 0;
	if (fmt == NULL)
		return (-1);
	va_start(ar, fmt);
	bits_count = ft_vsprintf(bits_count, fmt, ar);
	va_end(ar);
	return (bits_count);
}
