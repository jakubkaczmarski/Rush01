/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:50:20 by coder             #+#    #+#             */
/*   Updated: 2021/10/10 22:49:30 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_check_rt_visibility(int row, int col, int **map, int *skyscrappers);
int	ft_check_lf_visibility(int row, int col, int **map, int *skyscrappers);
int	ft_check_up_visibility(int row, int col, int **map, int *skyscrappers);
int	ft_check_dn_visibility(int row, int col, int **map, int *skyscrappers);

int	ft_check_rt_visibility(int row, int col, int **map, int *skyscrappers)
{
	int	visibile;
	int	max;
	int	i;

	i = 3;
	visibile = 0;
	max = 0;
	if (row != 3 || skyscrappers[12 + col] == 0)
	{
		return (1);
	}
	while (i >= 0)
	{
		if (map[col][i] > max)
		{
			max = map[col][i];
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

int	ft_check_lf_visibility(int row, int col, int **map, int *skyscrappers)
{
	int	visibile;
	int	max;
	int	i;

	i = 0;
	visibile = 0;
	max = 0;
	while (i <= row)
	{
		if (map[col][i] > max)
		{
			max = map[col][i];
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

int	ft_check_up_visibility(int row, int col, int **map, int *skyscrappers)
{
	int	visibile;
	int	max;
	int	i;

	i = 0;
	visibile = 0;
	max = 0;
	while (i <= col)
	{
		if (map[i][row] > max)
		{
			max = map[i][row];
			visibile++;
		}
		if (visibile > skyscrappers[row])
			return (0);
		i++;
	}
	if (visibile != skyscrappers[row] && col == 3)
		return (0);
	return (1);
}

int	ft_check_dn_visibility(int row, int col, int **map, int *skyscrappers)
{
	int	max;
	int	i;
	int	visible;

	max = 0;
	i = 3;
	visible = 0;
	if (col != 3 || skyscrappers[4 + row] == 0)
	{
		return (1);
	}
	while (i >= 0)
	{
		if (map[i][row] > max)
		{
			max = map[i][row];
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
