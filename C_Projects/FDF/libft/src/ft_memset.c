/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:06:59 by agesp             #+#    #+#             */
/*   Updated: 2018/11/09 11:41:57 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*save;

	i = 0;
	save = (char*)b;
	while (i < len)
	{
		save[i] = (char)(c);
		i++;
	}
	b = save;
	return (b);
}
