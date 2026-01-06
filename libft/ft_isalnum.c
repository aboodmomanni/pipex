/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:23:22 by aalmoman          #+#    #+#             */
/*   Updated: 2025/08/15 00:17:58 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int test)
{
	if (ft_isdigit(test) || ft_isalpha(test))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
