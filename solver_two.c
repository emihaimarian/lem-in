/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:17:03 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:52:23 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_recursive_node(t_node **node, t_list **list, \
			t_room **room, char *str)
{
	t_link *link;

	if ((*node)->status == 1)
		return ;
	str = ft_strjoin(str, (*list)->room[(*node)->n]);
	(*list)->coord[(*list)->i[8]++] = str;
	str = ft_strjoin(str, "-");
	(*list)->coord[(*list)->i[8]++] = str;
	link = (*node)->adj;
	while (link)
	{
		(*node)->status = 1;
		if (link->next->n == (*list)->end_count)
		{
			str = ft_strjoin(str, (*list)->end);
			(*list)->finals[(*list)->i[9]++] = str;
		}
		else
			ft_recursive_node(&link->next, list, room, str);
		link = link->adj;
		(*node)->status = 0;
	}
}

void	ft_solve_one(t_list **list, t_node **start, \
			t_node **swap, t_node **node)
{
	(*list)->i[5] = -1;
	(*list)->i[6] = 0;
	while (++(*list)->i[5] < (*list)->i[7])
	{
		*start = (t_node *)malloc(sizeof(t_node));
		(*start)->n = (*list)->i[5];
		(*start)->status = 0;
		(*start)->next = NULL;
		(*start)->adj = NULL;
		if ((*list)->i[6] == 0)
		{
			*node = *start;
			*swap = *start;
			(*list)->i[6]++;
		}
		else
		{
			(*swap)->next = *start;
			*swap = *start;
		}
	}
	*start = *node;
}

void	ft_solve_two_one(t_node **start, t_link **link, \
			t_link **way, t_node **swap)
{
	(*start)->adj = *link;
	(*link)->next = *swap;
	*way = *link;
}

void	ft_solve_two_two(t_link **way, t_link **link, t_node **swap)
{
	(*way)->adj = *link;
	*way = *link;
	(*link)->next = *swap;
}

void	ft_solve_two(t_list **list, t_node **node, \
			t_node **start, t_node **swap)
{
	t_link	*link;
	t_link	*way;

	while (*start)
	{
		(*list)->i[5] = -1;
		while ((*list)->paths[(*start)->n][++(*list)->i[5]] != -1)
		{
			*swap = *node;
			while (*swap)
			{
				if ((*list)->paths[(*start)->n][(*list)->i[5]] == (*swap)->n)
				{
					link = (t_link *)malloc(sizeof(t_link));
					link->adj = NULL;
					if ((*list)->i[5] == 0)
						ft_solve_two_one(start, &link, &way, swap);
					else
						ft_solve_two_two(&way, &link, swap);
				}
				*swap = (*swap)->next;
			}
		}
		*start = (*start)->next;
	}
}
