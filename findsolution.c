/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findsolution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:49:54 by coder             #+#    #+#             */
/*   Updated: 2021/10/10 22:59:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_check_rt_visibility(int row, int col, int **map, int *skyscrappers);
int	ft_check_lf_visibility(int row, int col, int **map, int *skyscrappers);
int	ft_check_up_visibility(int row, int col, int **map, int *skyscrappers);
int	ft_check_dn_visibility(int row, int col, int **map, int *skyscrappers);

int	**ft_make_map(void)
{
	int	**map;
	int	counter;

	map = malloc(8 * 4);
	counter = 0;
	while (counter < 4)
	{
		map[counter] = malloc(4 * 4);
		counter++;
	}
	return (map);
}

int	ft_check_repetition(int row, int col, int **map)
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

int	ft_check_map(int row, int col, int **map, int *skyscrappers)
{
	if (!ft_check_repetition(row, col, map))
		return (0);
	if (!ft_check_up_visibility(row, col, map, skyscrappers))
		return (0);
	if (!ft_check_dn_visibility(row, col, map, skyscrappers))
		return (0);
	if (!ft_check_rt_visibility(row, col, map, skyscrappers))
		return (0);
	if (!ft_check_lf_visibility(row, col, map, skyscrappers))
		return (0);
	return (1);
}

int	ft_heap(int row, int col, int **map, int *skyscrappers)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map[col][row] = i + 1;
		if (ft_check_map(row, col, map, skyscrappers))
		{
			if (row == 3 && col == 3)
			{
				return (1);
			}
			else if (ft_heap((1 + row) % 4, col + row / 3, map, skyscrappers))
			{
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	**ft_find_solution(int *skyscrappers, int *err)
{
	int	**map;
	int	res;

	map = ft_make_map();
	res = ft_heap(0, 0, map, skyscrappers);
	if (res == 0)
	{
		*err = 1;
	}
	return (map);
}
