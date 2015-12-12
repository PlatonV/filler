/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_project.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:13:05 by azaha             #+#    #+#             */
/*   Updated: 2015/12/10 13:13:07 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	exit_program()		/* Exit program if an error occurs */
{
	ft_putstr("error\n");
	exit(1);
}

int		check_fd(int fd)	/* verificare daca s-a citit fd */
{
	if (fd == -1)
		return(0);
	return(1);
}

void	check_right_down(char **this_element, char **matrix, int i, int j, int *hash)	/* verificare recursiv de la urmatoarea pozitie de dupa '#' in dreapta si in jos */
{
	if (matrix[i][j + 1] == '#')
	{
		(*hash)++;
		**this_element = 'R';
		(*this_element)++;
		check_right_down(this_element, matrix, i, j, hash);
		**this_element = 'L';
	}
	if (matrix[i + 1][j + 1] == '#')
	{
		(*hash)++;
		**this_element = 'D';
		(*this_element)++;
		check_right_down(this_element, matrix, i, j, hash);
		**this_element = 'U';
	}
}

void	check_down_left(char **this_element, char **matrix, int i, int j, int *hash)	/* verificare recursiv de la pozitia de sub primul '#' in jos si in stanga*/
{
	if (matrix[i + 1][j] == '#')
	{
		(*hash)++;
		**this_element = 'D';
		(*this_element)++;
		check_down_left(this_element, matrix, i, j, hash);
		**this_element = 'U';
	}
	if (matrix[i + 1][j - 1] == '#')
	{
		(*hash)++;
		**this_element = 'L';
		(*this_element)++;
		check_down_left(this_element, matrix, i, j, hash);
		**this_element = 'R';
	}
}

char	*get_directions(char **element, char **matrix)		/* incercare de a crea stringul cu directiile */
{
	int		i;
	int		j;
	int		k;
	int		hash;
	char	*this_element;

	i = 0;
	j = 0;
	k = 0;
	hash = 1;
	/*while (matrix[i] != 0)
	{
		while (matrix[i][j] != '.' || matrix[i][j] != '\0')
		{*/
			check_right_down(&this_element, matrix, i, j, &hash);
			check_down_left(&this_element, matrix, i, j, &hash);
			/*j++;
		}
		i++;
	}*/
	if (hash != 4)
		exit_program();
	*element = this_element;
	return(*element);
}

char	*process_tetriminos(char **element, char *tetriminos)		/* transformare string tetriminos in matrice si cautare primul '#' */
{
	char **matrix;

	matrix = ft_strsplit(tetriminos, '*');
	*element = ft_memalloc(sizeof(ft_strlen(*matrix)) + 1);
	while (*matrix != 0)
	{
		while (**matrix != '\0')
		{	
			if (**matrix == '#')
				return(get_directions(element, matrix));
			(*matrix)++;
		}
		matrix++;
	}
	return(0);
}

char	*save_line(char *tetriminos, char *line)	/* salveaza fiecare linie citita cu get_next_line intr-un string (tetriminos) care este trimis mai departe si procesat */
{
	char *aux;

	aux = ft_strjoin(tetriminos, line);
	aux = ft_strjoin(aux, "*");
	free(tetriminos);
	tetriminos = aux;
	return(tetriminos);
}

void	check_line(char *line)		/* verificare daca linia este valida */
{
	if (ft_strlen(line) != 4)
		exit_program();
 	if (!ft_strchr(line, '.') && !ft_strchr(line, '#'))
		exit_program();
}

int		check_newline(char *line, int count)		/* verificare daca intre matricile cu tetriminos exista newline */
{
	if (count % 5 == 0 && line[0] != '\0')
		exit_program();
	if (count % 5 == 0)
		return(1);
	return(0);
}

char	**get_elements(int fd)		/* parcurge fd linie cu linie, salvare matrice  */
{
	int		count;
	int		coloana;
	char	*line;
	char	*tetriminos;
	char	**elements;

	line = NULL;
	count = 1;
	coloana = 0;
	if (!(elements = (char**)malloc(sizeof(char*) * 27)))
		exit_program();
 	while (get_next_line(fd, &line))
 	{
 		check_line(line);
 		if (check_newline(line, count))
 		{
 			*elements = process_tetriminos(elements, tetriminos);
			(*elements)++;
 			free(tetriminos);
 		}
 		else
 			tetriminos = save_line(tetriminos, line);
 		coloana++;
 		count++;
 	}
	return (elements);
}

void	fillit(char **elements)		/* pentru verificare validari */
{
	int		coloana;

	coloana = 0;
	while (elements[coloana] != 0)
	{
		printf("%s\n", elements[coloana]);
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
	return(0);
}