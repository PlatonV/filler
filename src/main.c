/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:02:31 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/16 14:56:39 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit()
{
	char		**mat;
	t_coord		c;

	mat = create_matrix(4);
	init_matrix(mat, 4);
	c.i = 0;
	c.j = 0;
	back(mat, 4, 0);
}

int		main(int argc, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2 && check_fd(fd) == 1)
	{
		g_shapes = get_elements(fd);
		fillit();
	}
	close(fd);
	return(0);
}
