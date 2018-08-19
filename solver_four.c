/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:30:41 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:44:34 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_solve_six_one(t_list **list, t_room **room, t_room **display)
{
	*room = *display;
	while (*room)
	{
		ft_printf("L%d-%s ", ++(*room)->current, (*room)->str);
		*room = (*room)->past;
	}
	ft_printf("\n");
	if ((*list)->ants-- == 1)
		while (1)
		{
			if (*display == NULL)
				break ;
			*display = (*display)->past;
			*room = *display;
			(*list)->i[6] = (*list)->i[0];
			while (*room)
			{
				ft_printf("L%d-%s ", (*room)->current, \
				(*list)->split[(*list)->i[6]--]);
				*room = (*room)->past;
			}
			ft_printf("\n");
		}
}

void	ft_solve_six_two(t_list **list, t_room **room)
{
	(*room)->next->current = (*room)->current;
	if ((*list)->i[6] != 0)
	{
		(*list)->ants++;
		(*list)->i[6] = 0;
	}
	(*list)->i[5] = 0;
	*room = (*room)->next;
	while (*room)
	{
		if ((*room)->past != NULL)
		{
			(*room)->past->current = (*room)->current + 1;
			(*list)->i[5]++;
			ft_printf("L%d-%s ", (*room)->current, (*room)->str);
		}
		else
		{
			ft_printf("L%d-%s ", (*room)->current, (*room)->str);
			(*list)->i[5]++;
			break ;
		}
		*room = (*room)->past;
	}
	ft_printf("\n");
}

void	ft_solve_six_three(t_list **list, t_room **room, t_room **display)
{
	(*list)->i[6] = (*list)->i[5];
	(*list)->i[1] = (*list)->i[5];
	(*list)->i[2] = (*list)->i[5]++;
	while (--(*list)->i[5] != 1)
		*room = (*room)->next;
	(*list)->i[3] = (*list)->i[5];
	*display = *room;
	while ((*list)->i[1] != (*list)->i[0])
	{
		while ((*list)->i[6] && *room)
		{
			ft_printf("L%d-%s ", (*list)->i[5]++, \
			(*room)->next->str);
			*room = (*room)->past;
			(*list)->i[6]--;
		}
		ft_printf("\n");
		*display = (*display)->next;
		*room = *display;
		(*list)->i[5] = (*list)->i[3];
		(*list)->i[6] = (*list)->i[2];
		(*list)->i[1]++;
	}
	(*list)->i[5] = (*list)->i[6];
	*display = *room;
}

void	ft_solve_six_four(t_list **list, t_room **room, t_room **display)
{
	(*list)->i[3] = 2;
	(*list)->i[2] = 2;
	(*list)->i[4] = 0;
	while (1)
	{
		(*list)->i[6] = --(*list)->i[5];
		if ((*list)->i[6] == 0)
			break ;
		(*list)->i[3] = (*list)->i[2]++;
		(*list)->i[1] = (*list)->i[6];
		(*list)->i[4] = (*list)->i[0];
		*room = *display;
		while ((*list)->i[6] != 0)
		{
			ft_printf("L%d-%s ", (*list)->i[3]++, \
			(*list)->split[(*list)->i[4]--]);
			*room = (*room)->past;
			(*list)->i[6]--;
		}
		*room = (*room)->past;
		ft_printf("\n");
		*display = (*display)->past;
		if (*display == NULL)
			break ;
	}
}

void	ft_solve_six(t_list **list, t_room **room, t_room **display)
{
	while (*room && (*list)->ants != 1)
	{
		while ((*room)->current != 1)
			*room = (*room)->next;
		if ((*room)->next == NULL)
		{
			if ((*list)->split[2] != NULL)
				(*list)->ants--;
			*display = *room;
			while ((*list)->ants)
				ft_solve_six_one(list, room, display);
			break ;
		}
		ft_solve_six_two(list, room);
		(*list)->ants--;
		if ((*list)->ants == 1)
		{
			ft_solve_six_three(list, room, display);
			ft_solve_six_four(list, room, display);
		}
	}
}
