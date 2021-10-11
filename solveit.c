/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:48:18 by coder             #+#    #+#             */
/*   Updated: 2021/10/10 22:56:59 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <unistd.h>

int	ft_check_rt_visibility(int row, int col, int **map, int *skyscrappers);
int	ft_check_lf_visibility(int row, int col, int **map, int *skyscrappers);
int	ft_check_up_visibility(int row, int col, int **map, int *skyscrappers);
int	ft_check_dn_visibility(int row, int col, int **map, int *skyscrappers);
int	ft_check_dn_visibility(int row, int col, int **map, int *skyscrappers);
int	ft_heap(int row, int col, int **map, int *skyscrappers);
int	**ft_make_map(void);

int	**findsolution(int *skyscrappers, int *err)
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

void	printarr(int **response)
{
	int		i;
	int		j;
	char	a;

	i = 0;
	j = 0;
	a = '0';
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			a = response[i][j] + '0';
			write(1, &a, 1);
			if (j != 3)
			{
				write(1, " ", 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	makearr(char **argv, int *skyscrapers, int *err, int *arr)
{
	while (argv[1][arr[0]] != '\0')
	{
		if (argv[1][arr[0]] >= '1' && argv[1][arr[0]] <= '4')
		{
			arr[3] = argv[1][arr[0]] - '0';
			skyscrapers[arr[1]] = arr[3];
			if (arr[1] != 0 && arr[2] == 1 || argv[1][0] == ' ')
			{
				*err = 1;
				return (0);
			}
			arr[2] = 1;
			arr[1]++;
		}
		else if (argv[1][arr[0]] == ' ' && arr[2] == 1 &&
					arr[1] != 16)
			arr[2] = 0;
		else
		{
			*err = 1;
			return (0);
		}
		arr[0]++;
	}
}

int	populatearr(char **argv, int *skyscrapers, int *err)
{
	int	arrc[4];

	arrc[0] = 0;
	arrc[1] = 0;
	arrc[2] = 0;
	arrc[3] = 0;
	makearr(argv, skyscrapers, err, arrc);
	if (arrc[1] != 16)
		*err = 1;
}

int	main(int argc, char **argv)
{
	int	err;
	int	skyscrapers[16];
	int	**response;

	if (argc != 2)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	err = 0;
	populatearr(argv, skyscrapers, &err);
	if (err == 1)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	response = findsolution(skyscrapers, &err);
	if (err == 1)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	printarr(response);
	free(response);
	return (0);
}
