/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:01:29 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/17 19:35:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		back(char **mat, int n, int shapei)
{
	t_coord		c;

	c.i = 0;
	while (c.i < n)
	{
		c.j = 0;
		while (c.j < n)
		{
			g_cshape = shapei;
			if (put_shape(mat, c, n, g_shapes[shapei]))
			{
				if (shapei + 1 == count_shapes(g_shapes))
				{
					print_matrix(mat, n);
					exit(0);
				}
				back(mat, n, shapei + 1);
			}
			g_cshape = shapei;
			clear_shape(mat, c, n, g_shapes[shapei]);
			c.j++;
		}
		c.i++;
	}
}
