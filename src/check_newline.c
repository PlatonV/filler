/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:01:58 by azaha             #+#    #+#             */
/*   Updated: 2015/12/16 11:15:15 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_newline(char *line)		/* verificare daca intre matricile cu tetriminos exista newline */
{
	if (line[0] != '\0')
		exit_program();
}
