/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:20:33 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:54:45 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_validation_links_two(char ***split, t_list **list)
{
	int i;

	i = 0;
	while (i < (*list)->i[7])
	{
		if (!ft_strcmp((*split)[0], (*list)->room[i]))
			break ;
		i++;
	}
	(i == (*list)->i[7]) ? ft_exit_list(list) : 0;
	i = 0;
	while (i < (*list)->i[7])
	{
		if (!ft_strcmp((*split)[1], (*list)->room[i]))
			break ;
		i++;
	}
	(i == (*list)->i[7]) ? ft_exit_list(list) : 0;
}

void	ft_validation_links(char **line, t_list **list)
{
	char **split;

	ft_count_lines(line);
	split = ft_strsplit(*line, '-');
	ft_count_split_links(&split);
	ft_validation_links_two(&split, list);
	if (!((*list)->links[(*list)->links_count] = \
		(char **)malloc(sizeof(char *) * 2)))
		ft_exit_list(list);
	if (!((*list)->links[(*list)->links_count][0] = \
		(char *)malloc(sizeof(char) * ft_strlen(split[0]) + 1)))
		ft_exit_list(list);
	if (!((*list)->links[(*list)->links_count][1] = \
		(char *)malloc(sizeof(char) * ft_strlen(split[1]) + 1)))
		ft_exit_list(list);
	(*list)->links[(*list)->links_count][0] = ft_strdup(split[0]);
	(*list)->links[(*list)->links_count][1] = ft_strdup(split[1]);
	(*list)->links_count++;
}

int		ft_links(char **line, t_list **list)
{
	(!(*list)->start_count || !(*list)->end_count) ?
		ft_exit_list(list) : 0;
	while (1)
	{
		if (ft_strchr(*line, '-'))
			ft_validation_links(line, list);
		else if (!ft_strcmp(*line, "\0"))
			return (1);
		else if ((*list)->links_count > 0)
			ft_exit_list(list);
		get_next_line(0, line);
		ft_printf("%s\n", *line);
		if ((*line)[0] == '#')
			return (1);
	}
	return (0);
}

int		ft_valid_input(char **line, t_list **list)
{
	if ((*line)[0] == '#')
		return (1);
	else if (ft_rooms(line, list))
		return (1);
	else if (ft_links(line, list))
		return (1);
	else
		return (0);
}

void	ft_input(char **line, t_list **list, t_node **node)
{
	get_next_line(0, line);
	ft_printf("%s\n", *line);
	if (!ft_strcmp(*line, "\0"))
		ft_console(list, node);
	else if ((*line)[0] == '#' && (*line)[1] == '#' && (*line)[2] == 's' && \
		(*line)[3] == 't' && (*line)[4] == 'a' && (*line)[5] == 'r' && \
		(*line)[6] == 't' && (*line)[7] == '\0')
		ft_start(line, list);
	else if ((*line)[0] == '#' && (*line)[1] == '#' && (*line)[2] == 'e' && \
		(*line)[3] == 'n' && (*line)[4] == 'd' && (*line)[5] == '\0')
		ft_end(line, list);
	else if (!ft_valid_input(line, list))
		ft_exit_list(list);
}
