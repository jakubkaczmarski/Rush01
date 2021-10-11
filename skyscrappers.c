/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkForScyscrapers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:32:33 by coder             #+#    #+#             */
/*   Updated: 2021/10/10 22:50:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	repetitioncheck(int row, int col, int **map)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (map[col][i] == map[col][row])
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < col)
	{
		if (map[i][row] == map[col][row])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	checkrowforskyscrapersr(int row, int col, int **map, int *skyscrappers)
{
	int	visibile;
	int	maxval;
	int	i;

	i = 3;
	visibile = 0;
	maxval = 0;
	if (row != 3 || skyscrappers[12 + col] == 0)
	{
		return (1);
	}
	while (i >= 0)
	{
		if (map[col][i] > maxval)
		{
			maxval = map[col][i];
			visibile++;
		}
		i--;
	}
	if (visibile != skyscrappers[12 + col])
	{
		return (0);
	}
	return (1);
}

int	checkrowforskyscrapersl(int row, int col, int **map, int *skyscrappers)
{
	int	visibile;
	int	maxval;
	int	i;

	i = 0;
	visibile = 0;
	maxval = 0;
	while (i <= row)
	{
		if (map[col][i] > maxval)
		{
			maxval = map[col][i];
			visibile++;
		}
		if (visibile > skyscrappers[8 + col])
		{
			return (0);
		}
		i++;
	}
	if (visibile != skyscrappers[8 + col] && row == 3)
	{
		return (0);
	}
	return (1);
}

int	checkcolforskyscrapersu(int row, int col, int **map, int *skyscrappers)
{
	int	visibile;
	int	maxval;
	int	i;

	i = 0;
	visibile = 0;
	maxval = 0;
	while (i <= col)
	{
		if (map[i][row] > maxval)
		{
			maxval = map[i][row];
			visibile++;
		}
		if (visibile > skyscrappers[row])
		{
			return (0);
		}
		i++;
	}
	if (visibile != skyscrappers[row] && col == 3)
	{
		return (0);
	}
	return (1);
}

int	checkcolforskyscrapersd(int row, int col, int **map, int *skyscrappers)
{
	int	maxval;
	int	i;
	int	visible;

	maxval = 0;
	i = 3;
	visible = 0;
	if (col != 3 || skyscrappers[4 + row] == 0)
	{
		return (1);
	}
	while (i >= 0)
	{
		if (map[i][row] > maxval)
		{
			maxval = map[i][row];
			visible++;
		}
		i--;
	}
	if (visible != skyscrappers[4 + row])
	{
		return (0);
	}
	return (1);
}
