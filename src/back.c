/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:01:29 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/16 14:03:54 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**a;
int			counter;
int			is_put[26];
int			g_cpos;

int			count_shapes(char **shapes)
{
	int		count;

	count = 0;
	while (shapes[count])
		count++;
	return (count);
}

int			check_solution(int n)
{
	int		index;

	index = 0;
	while (index < n)
	{
		printf("%d ", is_put[index]);
		if (!is_put[index++])
		{
			printf("\n");
			return (0);
		}
	}
	return (1);
}

void		go_next(char **mat, t_coord coords, int n)
{
	if (coords.j == n - 1)
	{
		if (coords.i == n - 1)
			return;
		coords.i += 1;
		coords.j = 0;
		back(mat, coords, n);
	}
	else
	{
		coords.j += 1;
		back(mat, coords, n);
	}
}

int			put_shape(char **mat, t_coord c, int n, char *shape)
{
	int		step;
	char	letter;

	step = 0;
	letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[g_cpos];
	if (mat[c.i][c.j] != '.')
		return (0);
	mat[c.i][c.j] = letter;
	while (shape[step])
	{
		if (shape[step] == 'U')
			c.i--;
		else if (shape[step] == 'D')
			c.i++;
		else if (shape[step] == 'L')
			c.j--;
		else if (shape[step] == 'R')
			c.j++;
		if (c.i >= 0 && c.i < n && c.j >= 0 && c.j < n &&
				mat[c.i][c.j] == '.')
			mat[c.i][c.j] = letter;
		else
			return (0);
		step++;
	}
	return (1);
}

int			clear_shape(char **mat, t_coord c, int n, char *shape)
{
	int		step;
	char	letter;

	step = 0;
	letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[g_cpos];
	if (mat[c.i][c.j] == letter)
		mat[c.i][c.j] = '.';
	while (shape[step])
	{
		if (shape[step] == 'U')
			c.i--;
		else if (shape[step] == 'D')
			c.i++;
		else if (shape[step] == 'L')
			c.j--;
		else if (shape[step] == 'R')
			c.j++;
		if (c.i >= 0 && c.i < n && c.j >= 0 && c.j < n &&
				mat[c.i][c.j] == letter)
			mat[c.i][c.j] = '.';
		step++;
	}
	return (1);
}

void		back(char **mat, t_coord coords, int n)
{
	int		tpos;

	g_cpos = 0;
	while (g_cpos < n)
	{
		if (!is_put[g_cpos])
		{
			if (put_shape(mat, coords, n, g_shapes[g_cpos]))
			{
				is_put[g_cpos] = 1;
				counter++;
				if (check_solution(count_shapes(g_shapes)))
				{
					print_matrix(mat, n);
					exit(0);
				}
				tpos = g_cpos;
				go_next(mat, coords, n);
				g_cpos = tpos;
				clear_shape(mat, coords, n, g_shapes[g_cpos]);
				is_put[g_cpos] = 0;
			}
			else
			{
				clear_shape(mat, coords, n, g_shapes[g_cpos]);
			}
		}
		g_cpos++;
	}
	go_next(mat, coords, n);
}
