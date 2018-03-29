/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:37:07 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/01 15:11:41 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew_p(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((str = malloc(size + 1)) == NULL)
		return (NULL);
	while (i < size + 1)
		str[i++] = '\0';
	return (str);
}
