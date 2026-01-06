/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:23:55 by aalmoman          #+#    #+#             */
/*   Updated: 2025/08/11 16:51:16 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		target;
	size_t				i;

	i = 0;
	p = s;
	target = (unsigned char)c;
	while (n--)
	{
		if (p[i] == target)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
