/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:00:33 by azaha             #+#    #+#             */
/*   Updated: 2015/12/11 13:00:35 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

void	fillit(char **elements)
{
	int		coloana;

	coloana = 0;
	while (elements[coloana] != 0)
	{
		ft_putstr(elements[coloana]);
		ft_putstr("\n");
		coloana++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**elements;

	elements = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc == 2 && check_fd(fd) == 1)
	{
		elements = get_elements(fd);
		fillit(elements);
	}
	close(fd);
	return(0);
}