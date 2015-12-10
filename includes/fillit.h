/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:01:55 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/10 15:03:02 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_coord
{
	int		i;
	int		j;
}					t_coord;

void		ft_putchar(char c);
void		back(char **mat, t_coord coords, int n, int m, char shape);

#endif
