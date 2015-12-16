/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_project.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:13:05 by azaha             #+#    #+#             */
/*   Updated: 2015/12/16 11:14:41 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_elements(int fd)
{
	int		count;
	char	*line;
	char	*tetriminos;
	char	**elements;
	int 	ok;
	int		res;
	int 	index;

	ok = 1;
	count = 1;
	index = 0;
	line = ft_strdup("");
	tetriminos = ft_strdup("");
	if (!(elements = (char**)malloc(sizeof(char*) * 27)))
		exit_program();
 	while ((res = get_next_line(fd, &line)) || ok)
 	{
 		if (count % 5 == 0)
 		{
 			if (res != 0)
 				check_newline(line);
 			process_tetriminos(&elements[index], tetriminos);
			index++;
	 		free(tetriminos);
	 		tetriminos = ft_strdup("");
 		}
 		else
 		{
 			check_line(line);
 			tetriminos = save_line(tetriminos, line);
 		}
 		if (res == 0)
 			ok = 0;
 		count++;
 	}
 	elements[index] = 0;
	return (elements);
}
