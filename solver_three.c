/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:29:37 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:50:38 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_solve_three(t_node **start, t_list **list, t_node **node)
{
	*start = *node;
	while (*start)
	{
		if ((*start)->n == (*list)->start_count)
			break ;
		*start = (*start)->next;
	}
	(*list)->i[5] = 0;
	while ((*list)->i[5] < (*list)->i[7])
	{
		free((*list)->coord[(*list)->i[5]]);
		(*list)->i[5]++;
	}
	(*list)->finals = (char **)malloc(sizeof(char *) * 1024);
}

void	ft_solve_four(t_list **list)
{
	while ((*list)->i[5] < (*list)->i[9])
	{
		(*list)->tmp_tab[(*list)->i[5]] = \
			ft_strlen((*list)->finals[(*list)->i[5]]);
		(*list)->i[5]++;
	}
	(*list)->tmp_tab[(*list)->i[5]] = -1;
	(*list)->i[5] = 0;
	(*list)->i[6] = (*list)->tmp_tab[0];
	while ((*list)->tmp_tab[(*list)->i[5]] != -1)
	{
		if ((*list)->tmp_tab[(*list)->i[5]] < (*list)->i[6])
		{
			(*list)->i[2] = (*list)->i[5];
			(*list)->i[6] = (*list)->tmp_tab[(*list)->i[5]];
		}
		(*list)->i[5]++;
	}
	(*list)->split = ft_strsplit((*list)->finals[(*list)->i[2]], '-');
	(*list)->i[5] = 0;
	ft_print_bonus(list);
}

void	ft_solve_one_ant(t_list **list)
{
	(*list)->i[6] = 0;
	if ((*list)->ants == 1)
	{
		while ((*list)->split[++(*list)->i[6]])
			ft_printf("L%d-%s\n", 1, (*list)->split[(*list)->i[6]]);
		exit(1);
	}
}

void	ft_solve_five(t_list **list, t_room **paths, \
			t_room **room, t_room **display)
{
	(*list)->i[5] = 0;
	(*list)->tmp_tab = (int *)malloc(sizeof(int) * (*list)->i[9]);
	(*list)->i[5] = 1;
	*room = (t_room *)malloc(sizeof(t_room));
	(*room)->past = NULL;
	*paths = *room;
	while ((*list)->split[(*list)->i[5]])
	{
		(*room)->str = (*list)->split[(*list)->i[5]];
		(*room)->current = -1;
		if ((*list)->split[(*list)->i[5] + 1] != NULL)
		{
			(*room)->next = (t_room *)malloc(sizeof(t_room));
			*display = *room;
			*room = (*room)->next;
			(*room)->past = *display;
			(*room)->next = NULL;
		}
		(*list)->i[5]++;
	}
	ft_solve_one_ant(list);
	(*list)->i[6] = 2;
	(*list)->i[1] = 1;
}

void	ft_solve_two_ants(t_list **list, t_room **paths, \
			t_room **room, t_room **display)
{
	if ((*list)->ants == 2)
	{
		ft_printf("L%d-%s\n", 1, (*list)->split[1]);
		while ((*list)->split[(*list)->i[6]])
		{
			ft_printf("L%d-%s L%d-%s \n", 1, (*list)->split[(*list)->i[6]], \
				2, (*list)->split[(*list)->i[1]]);
			(*list)->i[6]++;
			(*list)->i[1]++;
		}
		ft_printf("L%d-%s\n", 2, (*list)->split[(*list)->i[1]]);
		exit(1);
	}
	(*list)->i[0] = --(*list)->i[5];
	*room = *paths;
	(*room)->current = 1;
	ft_printf("L%d-%s\n", (*room)->current, (*room)->str);
	(*list)->ants--;
	*display = *room;
	*room = *paths;
}
