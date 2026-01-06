/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:25:40 by aalmoman          #+#    #+#             */
/*   Updated: 2025/08/11 16:53:03 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mal;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	mal = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!mal)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mal[i] = f(i, s[i]);
		i++;
	}
	mal[i] = '\0';
	return (mal);
}
