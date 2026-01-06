/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:25:09 by aalmoman          #+#    #+#             */
/*   Updated: 2025/08/15 01:19:22 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		l;
	char	*dup;

	l = 0;
	while (s[l])
		l++;
	dup = (char *)malloc(sizeof(char) * (l + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
