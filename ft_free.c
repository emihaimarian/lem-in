/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:31:32 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:32:12 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_part_one(t_list **list)
{
	free((*list)->start);
	free((*list)->end);
	(*list)->i[5] = -1;
	while ((*list)->room[++(*list)->i[5]])
		free((*list)->room[(*list)->i[5]]);
	free((*list)->room);
	(*list)->i[5] = -1;
	while ((*list)->coord[++(*list)->i[5]])
		free((*list)->coord[(*list)->i[5]]);
	free((*list)->coord);
	(*list)->i[5] = -1;
	while ((*list)->finals[++(*list)->i[5]])
		free((*list)->finals[(*list)->i[5]]);
	free((*list)->finals);
	(*list)->i[5] = -1;
	while ((*list)->split[++(*list)->i[5]])
		free((*list)->split[(*list)->i[5]]);
	free((*list)->split);
}

void	ft_free_part_two(t_list **list)
{
	free((*list)->links);
	free((*list)->paths);
	free((*list)->tab);
	free((*list)->tmp_tab);
	free((*list)->i);
	free(*list);
}

void	ft_free_part_three(t_room **paths, t_node **start)
{
	t_room *delete_room;
	t_node *delete_node;
	t_link *delete_link;
	t_link *link;

	while (*paths)
	{
		delete_room = *paths;
		*paths = (*paths)->next;
		free(delete_room);
	}
	while (*start)
	{
		link = (*start)->adj;
		while (link)
		{
			delete_link = link;
			link = link->adj;
			free(delete_link);
		}
		delete_node = *start;
		*start = (*start)->next;
		free(delete_node);
	}
}
