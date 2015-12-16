/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:50:21 by azaha             #+#    #+#             */
/*   Updated: 2015/12/16 11:15:02 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const int	line[4] = {-1, 0, 1, 0};
const int	col[4] = {0, 1, 0, -1};

static	void	put_direction_letter_op(char **this_element, int pos, t_elem *anexe)
{
	if (pos == 2)
		(*this_element)[anexe->index] = 'U';
	if (pos == 3)
		(*this_element)[anexe->index] = 'R';
	if (pos == 0)
		(*this_element)[anexe->index] = 'D';
	if (pos == 1)
		(*this_element)[anexe->index] = 'L';
}

static	void	put_direction_letter(char **this_element, int pos, t_elem *anexe)
{
	if (pos == 0)
		(*this_element)[anexe->index] = 'U';
	if (pos == 1)
		(*this_element)[anexe->index] = 'R';
	if (pos == 2)
		(*this_element)[anexe->index] = 'D';
	if (pos == 3)
		(*this_element)[anexe->index] = 'L';
}
void			directions_back(char **this_element, char **matrix, char **aux, t_elem *anexe)
{
	int		pos;
	int 	pp;

	pos = 0;
	while (pos < 4)
	{
		if (anexe->i + line[pos] >= 0 && anexe->j + col[pos] >= 0 
			&& anexe->i + line[pos] < 4 && anexe->j + col[pos] < 4 
			&& matrix[anexe->i + line[pos]][anexe->j + col[pos]] == '#')
		{
			if(aux[anexe->i + 1 + line[pos]][anexe->j + 1 + col[pos]] != '1')
			{
				pp = 1;
				anexe->hash++;
				aux[anexe->i + 1 + line[pos]][anexe->j + 1 + col[pos]] = '1';
				put_direction_letter(this_element, pos, anexe);
				anexe->index++;
				anexe->i += line[pos];
				anexe->j += col[pos];
				directions_back(this_element, matrix, aux, anexe);
			}
			if(pp == 1 && anexe->hash < 4)
			{
				anexe->i -= line[pos];
				anexe->j -= col[pos];
				put_direction_letter_op(this_element, pos, anexe);
				anexe->index++;
				pp = 0;
			}
		}
		pos++;
	}
	(*this_element)[anexe->index] = '\0';
}








/*
		printf("i:%d | j:%d | pos:%d | hash:%d | conditie_1:%d | conditie_2:%d\n ", anexe->i, anexe->j, pos, anexe->hash, (anexe->i + line[pos] >= 0 && anexe->j + col[pos] >= 0 && anexe->i + line[pos] < 4 && anexe->j + col[pos] < 4 
			&& matrix[anexe->i + line[pos]][anexe->j + col[pos]] == '#'), anexe->i + line[pos] < 4 && anexe->j + col[pos] < 4);

static	void	put_recursive_letter(char *this_element, t_elem *anexe)
{
	if ((this_element[anexe->index - 1]) == 'D')
		this_element[anexe->index] = 'U';
	if ((this_element[anexe->index - 1]) == 'U')
		this_element[anexe->index] = 'D';
	if ((this_element[anexe->index - 1]) == 'L')
		this_element[anexe->index] = 'R';
	if ((this_element[anexe->index - 1]) == 'R')
		this_element[anexe->index] = 'L';
}
*/
