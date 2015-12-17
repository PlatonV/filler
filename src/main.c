/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:02:31 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/17 19:41:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_n(int count)
{
	int		i;

	i = 1;
	while (i * i <= count * 4)
		i++;
	return (i);
}

void	fillit()
{
	char		**mat;
	int			n;

	n = get_n(count_shapes(g_shapes));
	mat = create_matrix(n);
	init_matrix(mat, n);
	back(mat, n, 0);
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
