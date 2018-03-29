/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:48:09 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 18:58:37 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr_p(const char *s, int c)
{
	char	*ps;

	ps = (char *)s;
	while (*ps)
		if (*ps++ == (char)c)
			return (ps - 1);
	if ((char)c == '\0')
		return (ps);
	return (NULL);
}
