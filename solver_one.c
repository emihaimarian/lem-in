/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:10:21 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:50:02 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_init_malloc(char **line, t_list **list)
{
	int i;

	i = -1;
	*line = NULL;
	*list = (t_list *)malloc(sizeof(t_list));
	(*list)->start_count = 0;
	(*list)->end_count = 0;
	(*list)->ants = 0;
	(*list)->links_count = 0;
	(*list)->i = (int *)malloc(sizeof(int) * 10);
	(*list)->room = (char **)malloc(sizeof(char *) * 1024);
	(*list)->coord = (char **)malloc(sizeof(char *) * 4096);
	(*list)->links = (char ***)malloc(sizeof(char **) * 1024);
	while (++i < 9)
		(*list)->i[i] = 0;
}

void	ft_build_nodes(t_list **list)
{
	int m;

	(*list)->i[5] = 0;
	while ((*list)->i[5] < (*list)->i[7])
	{
		(*list)->i[6] = 0;
		m = 0;
		if (!((*list)->paths[(*list)->i[5]] = \
			(int *)malloc(sizeof(int) * (*list)->i[7])))
			ft_exit_list(list);
		while ((*list)->i[6] < (*list)->i[7])
		{
			(*list)->paths[(*list)->i[5]][(*list)->i[6]] = -1;
			if ((*list)->tab[(*list)->i[5]][(*list)->i[6]] == 1)
			{
				(*list)->paths[(*list)->i[5]][m] = (*list)->i[6];
				m++;
			}
			(*list)->i[6]++;
		}
		(*list)->i[5]++;
	}
}

void	ft_init_matrix(t_list **list)
{
	if (!((*list)->tab = (int **)malloc(sizeof(int *) * (*list)->i[7])) || \
		!((*list)->paths = (int **)malloc(sizeof(int *) * (*list)->i[7])))
		ft_exit_list(list);
	(*list)->i[5] = 0;
	while ((*list)->i[5] < (*list)->i[7])
	{
		(*list)->i[6] = 0;
		if (!((*list)->tab[(*list)->i[5]] = \
			(int *)malloc(sizeof(int) * (*list)->i[7])))
			ft_exit_list(list);
		while ((*list)->i[6] < (*list)->i[7])
		{
			(*list)->tab[(*list)->i[5]][(*list)->i[6]] = 0;
			(*list)->i[6]++;
		}
		(*list)->i[5]++;
	}
}

void	ft_build_matrix(t_list **list)
{
	int		x[2];

	(*list)->i[6] = 0;
	while ((*list)->i[6] < (*list)->links_count)
	{
		(*list)->i[5] = -1;
		while (++(*list)->i[5] < (*list)->i[7])
			if (!ft_strcmp((*list)->room[(*list)->i[5]], \
				(*list)->links[(*list)->i[6]][0]))
			{
				x[0] = (*list)->i[5];
				break ;
			}
		(*list)->i[5] = -1;
		while (++(*list)->i[5] < (*list)->i[7])
			if (!ft_strcmp((*list)->room[(*list)->i[5]], \
				(*list)->links[(*list)->i[6]][1]))
			{
				x[1] = (*list)->i[5];
				break ;
			}
		(*list)->tab[x[1]][x[0]] = 1;
		(*list)->tab[x[0]][x[1]] = 1;
		(*list)->i[6]++;
	}
}

void	ft_find_start_end(t_list **list)
{
	(*list)->i[5] = -1;
	if (!((*list)->tmp_tab = (int *)malloc(sizeof(int) * (*list)->i[7])))
		ft_exit_list(list);
	while (++(*list)->i[5] < (*list)->i[7])
		(*list)->tmp_tab[(*list)->i[5]] = -1;
	(*list)->start_count = 0;
	(*list)->end_count = 0;
	while ((*list)->start_count < (*list)->i[7])
	{
		if (!ft_strcmp((*list)->start, (*list)->room[(*list)->start_count]))
			break ;
		(*list)->start_count++;
	}
	while ((*list)->end_count < (*list)->i[7])
	{
		if (!ft_strcmp((*list)->end, (*list)->room[(*list)->end_count]))
			break ;
		(*list)->end_count++;
	}
}
