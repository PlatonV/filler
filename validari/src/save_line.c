/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:02:21 by azaha             #+#    #+#             */
/*   Updated: 2015/12/11 13:02:22 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../fillit.h"

char	*save_line(char *tetriminos, char *line)	/* salveaza fiecare linie citita cu get_next_line intr-un string (tetriminos) care este trimis mai departe si procesat */
{
	char *aux;

	aux = ft_strjoin(tetriminos, line);
	aux = ft_strjoin(aux, "*");
	free(tetriminos);
	tetriminos = aux;
	return(tetriminos);
}
