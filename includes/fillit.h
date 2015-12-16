/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:01:55 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/16 14:53:24 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_coord
{
	int		i;
	int		j;
}					t_coord;

typedef	struct s_elem
{
	int i;
	int j;
	int index;
	int hash;
}				t_elem;

char	**g_shapes;
int		g_cshape;

void	process_tetriminos(char **this_element, char *tetriminos);
void	directions_back(char **this_element, char **matrix, char **aux, t_elem *anexe);
int		check_fd(int fd);
void	check_line(char *line);
void	check_newline(char *line);
void	exit_program();
char	*save_line(char *tetriminos, char *line);
char	**get_elements(int fd);
void	init_elem(t_elem *elem);
char	**create_matrix(int n);
void	init_matrix(char **mat, int n);
void	print_matrix(char **mat, int n);
int		put_shape(char **mat, t_coord c, int n, char *shape);
int		clear_shape(char **mat, t_coord c, int n, char *shape);
void	back(char **mat, int n, int shapei);
void	print_matrix(char **mat, int n);

#endif
