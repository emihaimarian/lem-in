/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 03:50:06 by mienache          #+#    #+#             */
/*   Updated: 2017/01/26 01:33:28 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"
# include "libft/ft_printf.h"

void	ft_console(t_list **list, t_node **node);
void	ft_solve(t_list **list, t_node **node);
void	ft_ck_begin(t_list **list);
void	ft_ck_ant_nb(char **line, t_list **list);
void	ft_ck_split(char ***split, t_list **list);
int		ft_count_split(char ***split);
void	ft_count_split_links(char ***split);
void	ft_count_lines(char **str);
void	ft_start_two(char **line, t_list **list);
void	ft_start(char **line, t_list **list);
void	ft_end_two(char **line, t_list **list);
void	ft_end(char **line, t_list **list);
int		ft_rooms(char **line, t_list **list);
void	ft_input(char **line, t_list **list, t_node **node);
int		ft_valid_input(char **line, t_list **list);
int		ft_links(char **line, t_list **list);
void	ft_validation_links(char **line, t_list **list);
void	ft_validation_links_two(char ***split, t_list **list);
void	ft_init_malloc(char **line, t_list **list);
void	ft_build_nodes(t_list **list);
void	ft_init_matrix(t_list **list);
void	ft_build_matrix(t_list **list);
void	ft_find_start_end(t_list **list);
void	ft_recursive_node(t_node **node, t_list **list, \
			t_room **room, char *str);
void	ft_solve_one(t_list **list, t_node **start, \
			t_node **swap, t_node **node);
void	ft_solve_two_one(t_node **start, t_link **link, \
			t_link **way, t_node **swap);
void	ft_solve_two_two(t_link **way, t_link **link, t_node **swap);
void	ft_solve_two(t_list **list, t_node **node, \
			t_node **start, t_node **swap);
void	ft_solve_three(t_node **start, t_list **list, t_node **node);
void	ft_solve_four(t_list **list);
void	ft_solve_one_ant(t_list **list);
void	ft_solve_five(t_list **list, t_room **paths, \
			t_room **room, t_room **display);
void	ft_solve_two_ants(t_list **list, t_room **paths, \
			t_room **room, t_room **display);
void	ft_solve_six_one(t_list **list, t_room **room, t_room **display);
void	ft_solve_six_two(t_list **list, t_room **room);
void	ft_solve_six_three(t_list **list, t_room **room, t_room **display);
void	ft_solve_six_four(t_list **list, t_room **room, t_room **display);
void	ft_solve_six(t_list **list, t_room **room, t_room **display);
void	ft_free_part_one(t_list **list);
void	ft_free_part_two(t_list **list);
void	ft_free_part_three(t_room **paths, t_node **start);
void	ft_no_solition(t_list **list);
void	ft_del_split(char ***split);
void	ft_exit_list(t_list **list);
void	ft_print_bonus(t_list **list);

#endif
