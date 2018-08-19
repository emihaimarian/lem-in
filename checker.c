/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:28:04 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:30:55 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_ck_begin(t_list **list)
{
	int i;

	i = 0;
	while ((*list)->links[i])
	{
		if (!ft_strcmp((*list)->start, (*list)->links[i][0]) || \
			!ft_strcmp((*list)->start, (*list)->links[i][1]))
			break ;
		i++;
	}
	(i == (*list)->links_count) ? ft_exit_list(list) : 0;
	i = 0;
	while ((*list)->links[i])
	{
		if (!ft_strcmp((*list)->end, (*list)->links[i][0]) || \
			!ft_strcmp((*list)->end, (*list)->links[i][1]))
			break ;
		i++;
	}
	(i == (*list)->links_count) ? ft_exit_list(list) : 0;
}

void	ft_ck_ant_nb(char **line, t_list **list)
{
	char *str;

	str = ft_strtrim(*line);
	if (str[(*list)->i[5]] == '\0')
	{
		free(str);
		ft_exit_list(list);
	}
	while (str[(*list)->i[5]])
	{
		if (!ft_isdigit(str[(*list)->i[5]]))
		{
			free(str);
			ft_exit_list(list);
		}
		(*list)->i[5]++;
	}
	(*list)->ants = ft_atoi(str);
	free(str);
	((*list)->ants < 1) ? ft_exit_list(list) : 0;
}

void	ft_ck_split(char ***split, t_list **list)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if ((*split)[0][0] == 'L')
	{
		ft_del_split(split);
		ft_exit_list(list);
	}
	while (j <= 2)
	{
		i = 0;
		while ((*split)[j][i])
		{
			if (!ft_isdigit((*split)[j][i]))
			{
				ft_del_split(split);
				ft_exit_list(list);
			}
			i++;
		}
		j++;
	}
}
