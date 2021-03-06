/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:25:22 by kecosmon          #+#    #+#             */
/*   Updated: 2019/02/22 15:25:32 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int lens1;

	i = 0;
	lens1 = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[lens1 + i] = s2[i];
		i++;
	}
	s1[lens1 + i] = '\0';
	return (s1);
}
