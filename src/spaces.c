#include "../includes/fillit.h"

char	g_viz[27][27];

static void			init_viz(char **mat)
{
	int		i;
	int		j;

	while (i < 26)
	{
		while (j < 26)
		{
			mat[i][j] = 0;
			j++;
		}
		i++;
	}
}

static int			free(char **mat, int i, int j, int n)
{
	if (i < 0 || i > n || j < 0 || j > n || mat[i][j] != '.')
		return (0);
	return (1);
}

static int			lee(char **mat, int i, int j, int n)
{
	int		result;

	result = 0;
	if (g_viz[i][j])
		return (0);
	if (free(mat, i, j, n))
	{
		g_viz[i][j] = 1;
		return (1 + lee(mat, i + 1, j, n) +
				lee(mat, i - 1, j, n) +
				lee(mat, i, j + 1, n) +
				lee(mat, i, j - 1, n))
	}
	return (0);
}

int					count_spaces(char **mat, int n)
{
	int		i;
	int		j;
	int		result;

	init_viz(g_viz);
	result = 0;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (mat[i][j] = '.' && !g_viz[i][j])
				result += lee(mat, i, j, viz);
			j++;
		}
		i++;
	}
	return (result);
}
