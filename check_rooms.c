/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_start_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:22:34 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:29:14 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_start_two(char **line, t_list **list)
{
	if ((*list)->start_count > 1)
	{
		free((*list)->start);
		ft_exit_list(list);
	}
	get_next_line(0, line);
	ft_printf("%s\n", *line);
	while (1)
	{
		if ((*line)[0] == '#' && (*line)[1] == '#' && (*line)[2] == 'e' && \
			(*line)[3] == 'n' && (*line)[4] == 'd' && (*line)[5] == '\0')
			ft_exit_list(list);
		else if ((*line)[0] == '#')
		{
			get_next_line(0, line);
			ft_printf("%s\n", *line);
		}
		else
			break ;
	}
}

void	ft_start(char **line, t_list **list)
{
	char	**split;
	int		i;

	i = 0;
	(*list)->start_count++;
	ft_start_two(line, list);
	(!ft_strchr(*line, ' ')) ? ft_exit_list(list) : 0;
	split = ft_strsplit(*line, ' ');
	if (!ft_count_split(&split))
		ft_exit_list(list);
	ft_ck_split(&split, list);
	(*list)->start = ft_strdup(split[0]);
	(*list)->room[(*list)->i[7]] = ft_strdup(split[0]);
	(*list)->coord[(*list)->i[7]] = ft_strjoin(split[1], split[2]);
	ft_del_split(&split);
	while (i < (*list)->i[7])
		(!ft_strcmp((*list)->room[(*list)->i[7]], (*list)->room[i]) || \
		!ft_strcmp((*list)->coord[(*list)->i[7]], (*list)->coord[i])) ?
			ft_exit_list(list) : i++;
	(*list)->i[7]++;
}

void	ft_end_two(char **line, t_list **list)
{
	if ((*list)->end_count > 1)
	{
		free((*list)->end);
		ft_exit_list(list);
	}
	get_next_line(0, line);
	ft_printf("%s\n", *line);
	while (1)
	{
		if ((*line)[0] == '#' && (*line)[1] == '#' && (*line)[2] == 's' && \
			(*line)[3] == 't' && (*line)[4] == 'a' && (*line)[5] == 'r' && \
			(*line)[6] == 't' && (*line)[7] == '\0')
			ft_exit_list(list);
		else if ((*line)[0] == '#')
		{
			get_next_line(0, line);
			ft_printf("%s\n", *line);
		}
		else
			break ;
	}
}

void	ft_end(char **line, t_list **list)
{
	char	**split;
	int		i;

	i = 0;
	(*list)->end_count++;
	ft_end_two(line, list);
	(!ft_strchr(*line, ' ')) ? ft_exit_list(list) : 0;
	split = ft_strsplit(*line, ' ');
	if (!ft_count_split(&split))
		ft_exit_list(list);
	ft_ck_split(&split, list);
	(*list)->end = ft_strdup(split[0]);
	(*list)->room[(*list)->i[7]] = ft_strdup(split[0]);
	(*list)->coord[(*list)->i[7]] = ft_strjoin(split[1], split[2]);
	ft_del_split(&split);
	while (i < (*list)->i[7])
		(!ft_strcmp((*list)->room[(*list)->i[7]], (*list)->room[i]) || \
		!ft_strcmp((*list)->coord[(*list)->i[7]], (*list)->coord[i])) ?
			ft_exit_list(list) : i++;
	(*list)->i[7]++;
}

int		ft_rooms(char **line, t_list **list)
{
	char	**split;
	int		i;

	i = 0;
	if (ft_strchr(*line, ' '))
	{
		split = ft_strsplit(*line, ' ');
		if (!ft_count_split(&split))
			return (0);
		ft_ck_split(&split, list);
		(*list)->room[(*list)->i[7]] = ft_strdup(split[0]);
		(*list)->coord[(*list)->i[7]] = ft_strjoin(split[1], split[2]);
		ft_del_split(&split);
		while (i < (*list)->i[7])
			(!ft_strcmp((*list)->room[(*list)->i[7]], (*list)->room[i]) || \
			!ft_strcmp((*list)->coord[(*list)->i[7]], (*list)->coord[i])) ?
				ft_exit_list(list) : i++;
		(*list)->i[7]++;
		return (1);
	}
	return (0);
}
