/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:14:09 by skholodn          #+#    #+#             */
/*   Updated: 2016/11/29 10:47:21 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy_p(const char *dest, const char *src)
{
	int		i;
	char	*n_dest;

	i = 0;
	n_dest = (char *)dest;
	while (src[i])
	{
		n_dest[i] = src[i];
		i++;
	}
	n_dest[i] = '\0';
	return (n_dest);
}
