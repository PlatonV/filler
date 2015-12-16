/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:01:29 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/16 15:30:40 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**a;
int			counter;
int			is_put[26];

int			count_shapes(char **shapes)
{
	int		count;

	count = 0;
	while (shapes[count])
		count++;
	return (count);
}

t_coord		try_put(char **mat, int n, int shapei, int var)
{
	int		i;
	int		j;
	t_coord	c;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c.i = i;
			c.j = j;
			g_cshape = shapei;
			print_matrix(mat, n);
			if (put_shape(mat, c, n, g_shapes[shapei]))
				if (!(var--))
					return (c);
			clear_shape(mat, c, n, g_shapes[shapei]);
			j++;
		}
		i++;
	}
	c.i = -1;
	c.j = -1;
	return (c);
}

void		back(char **mat, int n, int shapei)
{
	int		var;
	t_coord	c;

	var = 0;
	c = try_put(mat, n, shapei, var);
	while (c.i != -1 && c.j != -1)
	{
		if (shapei == count_shapes(g_shapes))
		{
			print_matrix(mat, n);
			exit(0);
		}
		back(mat, n, shapei + 1);
		clear_shape(mat, c, n, g_shapes[shapei]);
		var++;
		c = try_put(mat, n, shapei, var);
	}
}
