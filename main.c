/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 03:49:28 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:38:58 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_solve(t_list **list, t_node **node)
{
	t_node	*swap;
	t_room	*paths;
	t_room	*display;
	t_node	*start;
	t_room	*room;

	ft_solve_one(list, &start, &swap, node);
	ft_solve_two(list, node, &start, &swap);
	ft_solve_three(&start, list, node);
	ft_recursive_node(&start, list, &paths, "");
	ft_no_solition(list);
	ft_solve_four(list);
	ft_solve_five(list, &paths, &room, &display);
	ft_solve_two_ants(list, &paths, &room, &display);
	ft_solve_six(list, &room, &display);
	ft_free_part_one(list);
	ft_free_part_two(list);
	ft_free_part_three(&paths, &start);
}

void	ft_console(t_list **list, t_node **node)
{
	ft_ck_begin(list);
	ft_init_matrix(list);
	ft_build_matrix(list);
	ft_build_nodes(list);
	ft_find_start_end(list);
	ft_solve(list, node);
	exit(1);
}

int		main(void)
{
	char	*line;
	char	*str;
	t_list	*list;
	t_node	*node;

	ft_init_malloc(&line, &list);
	get_next_line(0, &line);
	str = ft_strdup(line);
	ft_printf("%s\n", str);
	ft_ck_ant_nb(&str, &list);
	while (1)
		ft_input(&line, &list, &node);
	return (0);
}
