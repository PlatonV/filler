/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:59:53 by azaha             #+#    #+#             */
/*   Updated: 2015/12/11 14:59:55 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../fillit.h"
#include <stdio.h>

static	char	**allocate_matrix(int line, int col)
{
	int i;

	i = 0;
	char **matrix;

	matrix = (char**)malloc(sizeof(char*) * line + 1);
	while (i < line)
	{
		matrix[i] = ft_memalloc(col + 1);
		ft_memset(matrix[i], '0', col);
		i++;
	}
	matrix[i] = 0;
	return(matrix);
}

void	process_tetriminos(char **this_element, char *tetriminos)
{
	char **aux;
	char **matrix;
	t_elem anexe;

	init_elem(&anexe);
	matrix = ft_strsplit(tetriminos, '*');
	aux = allocate_matrix(6, 6);
	*this_element = ft_memalloc(10);
	while (matrix[anexe.i] != 0)
	{
		anexe.j = 0;
		while (matrix[anexe.i][anexe.j] != '\0')
		{	
			if (matrix[anexe.i][anexe.j] == '#')
			{
				aux[anexe.i + 1][anexe.j + 1] = '1';
				directions_back(this_element, matrix, aux, &anexe);
			}
			else
				**aux = '0';
			anexe.j++;
		}
		anexe.i++;
	}
	if (anexe.hash != 4)
		exit_program();
	init_elem(&anexe);
	free(matrix);
	free(aux);
}