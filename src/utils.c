/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:05:34 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/23 23:02:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_shapes(char **shapes)
{
	int		count;

	count = 0;
	while (shapes[count])
		count++;
	return (count);
}

char		**create_matrix(int n)
{
	int		index;
	char	**result;

	result = (char**)malloc(sizeof(char*) * n);
	index = 0;
	while (index < n)
		result[index++] = (char*)malloc(n);
	return (result);
}

void		init_matrix(char **mat, int n)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			mat[i][j] = '.';
			j++;
		}
		i++;
	}
}

void		print_matrix(char **mat, int n)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (mat[i][j] == 0)
				ft_putchar('0');
			else
				ft_putchar(mat[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}
