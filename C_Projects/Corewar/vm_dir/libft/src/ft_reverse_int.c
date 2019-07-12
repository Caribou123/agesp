/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:32:38 by pfragnou          #+#    #+#             */
/*   Updated: 2019/04/12 13:32:39 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int		ft_reverse_int(int nb, uint8_t bits)
{
	return (bits == 16 ?
		nb = (nb >> 8) | (nb << 8)
		: (nb >> 24) | (nb >> 8 & 0xFF00) | (nb << 8 & 0xFF0000) | (nb << 24));
}