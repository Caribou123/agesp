/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:53:42 by agesp             #+#    #+#             */
/*   Updated: 2019/02/20 14:02:42 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/ft_printf.h"
typedef struct	s_lem
{
	int		start;
	int		end;
	char	*instr;
}				t_lem;

int		input_check(char *str);

#endif
