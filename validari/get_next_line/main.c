/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 20:46:19 by azaha             #+#    #+#             */
/*   Updated: 2015/12/11 20:50:00 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	line = ft_memalloc(100);
	
	get_next_line(fd, &line);
	printf("%s\n", line);
	return(0);
}
