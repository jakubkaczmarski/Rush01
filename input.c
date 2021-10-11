/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:49:43 by coder             #+#    #+#             */
/*   Updated: 2021/10/10 20:52:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_argc(int argc)
{
	if (argc == 2)
		return (1);
	else
		return (0);
}

int	ft_check_argv(char *input)
{
	int	values;
	int	spaces;

	values = 0;
	spaces = 1;
	while (values <= 30)
	{
		if (input[values] < '1' || input[values] > '4')
			return (0);
		values += 2;
	}
	while (spaces <= 29)
	{
		if (input[spaces] != ' ')
			return (0);
		spaces += 2;
	}
	if (input[31] != '\0')
		return (0);
	return (1);
}

int	ft_check_input_format(int argc, char *argv1)
{
	if (ft_check_argc(argc) && ft_check_argv(argv1))
		return (0);
	else
		return (1);
}

void	ft_fill_array(char *argv1, int *array)
{
	int	input_i;
	int	array_i;

	input_i = 0;
	array_i = 0;
	while (input_i <= 30)
	{
		array[array_i] = argv1[input_i] - '0';
		input_i += 2;
		array_i += 1;
	}
}
