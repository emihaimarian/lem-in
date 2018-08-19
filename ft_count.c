/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:24:32 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:31:41 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_count_split(char ***split)
{
	int i;

	i = 0;
	while ((*split)[i])
		i++;
	if (i != 3)
	{
		ft_del_split(split);
		return (0);
	}
	return (1);
}

void	ft_count_split_links(char ***split)
{
	int i;

	i = 0;
	while ((*split)[i])
		i++;
	if (i != 2)
	{
		ft_del_split(split);
		exit(1);
	}
	if (!ft_strcmp((*split)[0], (*split)[1]))
		exit(0);
}

void	ft_count_lines(char **str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '-')
			count++;
		i++;
	}
	if (count > 1)
		exit(1);
}
