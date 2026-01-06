/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:26:05 by aalmoman          #+#    #+#             */
/*   Updated: 2025/08/14 18:35:08 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	fronttrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j] && s1[i] != set[j])
			j++;
		if (!set[j])
			break ;
		i++;
	}
	return (i);
}

size_t	endtrim(char const *s1, char const *set, size_t start)
{
	size_t	end;
	size_t	j;

	end = 0;
	while (s1[end])
		end++;
	while (end > start)
	{
		j = 0;
		while (set[j] && s1[end - 1] != set[j])
			j++;
		if (!set[j])
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = fronttrim(s1, set);
	end = endtrim(s1, set, start);
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
