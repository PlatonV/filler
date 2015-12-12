/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:01:29 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/12 15:27:46 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

char		**a;
int			counter;

char		**create_matrix(int n, int m)
{
	int		index;
	char	**result;

	result = (char**)malloc(sizeof(char*) * n);
	index = 0;
	while (index < m)
		result[index++] = (char*)malloc(m);
	return (result);
}

void		init_matrix(char **mat, int n, int m)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			mat[i][j] = '.';
			j++;
		}
		i++;
	}
}

void		print_matrix(char **mat, int n, int m)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			ft_putchar(mat[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void		go_next(char **mat, t_coord coords, int n, int m, char shape)
{
	if (coords.j == m - 1)
	{
		if (coords.i == n - 1)
			return;
		coords.i += 1;
		coords.j = 0;
		back(mat, coords, n, m, shape);
	}
	else
	{
		coords.j += 1;
		back(mat, coords, n, m, shape);
	}
}

void		back(char **mat, t_coord coords, int n, int m, char shape)
{
	if (counter < 4 && mat[coords.i][coords.j] != '.')
	{
		go_next(mat, coords, n, m, shape);
		return;
	}
	// put_shape
	mat[coords.i][coords.j] = '#';
	counter++;
	// check_solution
	if (counter == 4)
		print_matrix(mat, n, m);
	go_next(mat, coords, n, m, shape);
	// clear_shape
	mat[coords.i][coords.j] = '.';
	counter--;
	go_next(mat, coords, n, m, shape);
}

int			main()
{
	int		n = 5;
	int		m = 5;
	t_coord	c;

	c.i = 0;
	c.j = 0;
	a = create_matrix(n, m);
	init_matrix(a, n, m);
	back(a, c, n, m, 0);
	return (0);
}
