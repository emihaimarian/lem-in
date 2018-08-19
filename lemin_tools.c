/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:19:03 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:33:59 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_no_solition(t_list **list)
{
	if ((*list)->i[9] == 0)
	{
		ft_printf("No possible solution!\n");
		exit(1);
	}
}

void	ft_print_bonus(t_list **list)
{
	while ((*list)->split[(*list)->i[5]])
	{
		ft_printf("\e[38;5;22;1;3m 🐜   [%s]\e[0m =>", \
			(*list)->split[(*list)->i[5]]);
		(*list)->i[5]++;
	}
	ft_printf("\n\n");
}

void	ft_del_split(char ***split)
{
	int i;

	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		i++;
	}
	free(*split);
}

void	ft_exit_list(t_list **list)
{
	int i;

	i = 0;
	while (i < (*list)->i[7])
	{
		free((*list)->room[i]);
		free((*list)->coord[i]);
		i++;
	}
	free((*list)->room);
	free((*list)->coord);
	ft_printf("Error\n");
	exit(1);
}
