/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:48:03 by agesp             #+#    #+#             */
/*   Updated: 2019/02/13 13:17:15 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			is_solo(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		return (0);
	return (1);
}

char		**get_solo(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' && str[i + 1] && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (NULL);
		i++;
	}
	return (ft_strsplit(str, ' '));
}

char		**create_tab(int ac, char **av)
{
	char	**tab;

	if (ac == 2 && is_solo(av[1]))
		return (NULL);
	if (ac == 3 && is_solo(av[2]) && (!ft_strcmp(av[1], "-v")
				|| !ft_strcmp(av[1], "-w")))
		return (get_solo(av[2]));
	if (ac == 3 && (!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "-w")))
		tab = ft_strsplit(av[2], ' ');
	else if (ac == 2 && (ft_strcmp(av[1], "-v")
				|| ft_strcmp(av[1], "-w")))
		tab = ft_strsplit(av[1], ' ');
	else
		tab = NULL;
	return (tab);
}

static int	is_tab_ok(int tab[], int size, char **tab2)
{
	int i;
	int j;

	i = 0;
	if (!ft_strcmp(tab2[0], "-v")
			|| !ft_strcmp(tab2[0], "-w")
			|| !ft_strcmp(tab2[1], "-v")
			|| !ft_strcmp(tab2[1], "-w"))
		size -= 1;
	size -= tab2[0][0] == '.' || tab2[0][0] == '/' ? 1 : 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j == i)
				j++;
			if (j != size && tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			is_input_ok(int ac, char **av)
{
	int		i;
	int		tab[ac - 1];
	char	*save;
	int		j;

	i = av[0] && (av[0][0] == '/' || av[0][0] == '.') ? 1 : 0;
	save = NULL;
	j = 0;
	if (!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "-w"))
		i++;
	if (i == ac)
		return (0);
	while (i < ac)
	{
		if ((!(tab[j] = ft_atoi(av[i])) && av[i][0] != '0'))
			return (0);
		save = ft_itoa_base(tab[j++], 10, 'a');
		if (save[0] != av[i++][0])
		{
			save ? free(save) : do_nothing();
			return (0);
		}
		free(save);
	}
	return (is_tab_ok(tab, ac, av));
}
