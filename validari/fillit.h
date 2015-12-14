/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:07:22 by azaha             #+#    #+#             */
/*   Updated: 2015/12/11 18:07:24 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef	struct s_elem
{
	int i;
	int j;
	int index;
	int hash;
}				t_elem;

void	process_tetriminos(char **this_element, char *tetriminos);
void	directions_back(char **this_element, char **matrix, char **aux, t_elem *anexe);
int		check_fd(int fd);
void	check_line(char *line);
void	check_newline(char *line);
void	exit_program();
char	*save_line(char *tetriminos, char *line);
char	**get_elements(int fd);
void	init_elem(t_elem *elem);

#endif