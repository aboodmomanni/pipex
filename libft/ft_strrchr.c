/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:25:55 by aalmoman          #+#    #+#             */
/*   Updated: 2025/08/13 00:17:26 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
	{
		return ((char *)(&s[i]));
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(&s[i]));
		}
		i--;
	}
	return (NULL);
}
