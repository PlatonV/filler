/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:01:29 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/12 16:32:15 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

char		**a;
int			counter;

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
//			ft_putchar(mat[i][j]);
//			ft_putchar(' ');
			j++;
		}
//		ft_putchar('\n');
		i++;
	}
}

void		go_next(char **mat, t_coord coords, int n, char shape)
{
	if (coords.j == n - 1)
	{
		if (coords.i == n - 1)
			return;
		coords.i += 1;
		coords.j = 0;
		back(mat, coords, n, shape);
	}
	else
	{
		coords.j += 1;
		back(mat, coords, n, shape);
	}
}

void		back(char **mat, t_coord coords, int n, char shape)
{
	if (counter < n && mat[coords.i][coords.j] != '.')
	{
		go_next(mat, coords, n, shape);
		return;
	}
	// put_shape
	mat[coords.i][coords.j] = '1' + counter;
	counter++;
	// check_solution
	if (counter == n)
		print_matrix(mat, n);
	if (coords.i != 4 || coords.j != 4)
		go_next(mat, coords, n, shape);
	// clear_shape
	mat[coords.i][coords.j] = '.';
	counter--;
	if (coords.i != 4 || coords.j != 4)
		go_next(mat, coords, n, shape);
}

int			main()
{
	int		n = 6;
	t_coord	c;

	c.i = 0;
	c.j = 0;
	a = create_matrix(n);
	init_matrix(a, n);
	back(a, c, n, 0);
	return (0);
}
