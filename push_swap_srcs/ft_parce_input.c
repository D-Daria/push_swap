/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:31:53 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/15 16:10:28 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_count_args(t_data *data, int argc, const char **arg_str)
{
	int	count_digits;
	int	i;

	i = 1;
	count_digits = 0;
	while (i < argc)
	{
		count_digits += ft_count_values(arg_str[i], ' ');
		i++;
	}
	data->count_args = count_digits;
	data->array_to_presort = malloc(sizeof(int) * data->count_args);
	if (data->array_to_presort == NULL)
		exit(1);
}

static void	ft_fill_arr(t_data *data, int argc, const char **arg_str, int *i)
{
	char		**split_str;
	long long	value;
	int			j;
	int			k;

	k = 0;
	while (*i < argc)
	{
		split_str = ft_split(arg_str[*i], ' ');
		j = 0;
		while (j < ft_count_values(arg_str[*i], ' '))
		{
			value = ft_atoll(split_str[j]);
			if (value > INT_MAX || value < INT_MIN)
				ft_puterror("Error\n");
			data->array_to_presort[k++] = value;
			j += 1;
		}
		ft_free_split(split_str);
		*i += 1;
	}
}

void	ft_parse_multiple_args(t_data *data, int argc, const char **arg_str)
{
	int	i;

	ft_count_args(data, argc, arg_str);
	i = 1;
	ft_fill_arr(data, argc, arg_str, &i);
}

void	ft_parse_single_arg(t_data *data, const char *arg_str)
{
	size_t		i;
	size_t		str_len;
	long long	value;
	int			j;

	i = 0;
	j = 0;
	value = 0;
	str_len = ft_strlen(arg_str);
	while (i < str_len)
	{
		value = ft_atoll(arg_str + i);
		if (value > INT_MAX || value < INT_MIN)
			ft_puterror("Error\n");
		while (arg_str[i] == ' ')
			i++;
		while (arg_str[i] == '-' || ft_isdigit(arg_str[i]))
			i++;
		data->array_to_presort[j++] = value;
	}
}

void	ft_parse_input(t_data *data, int argc, const char **argv)
{
	ft_validate_input(argc, argv);
	if (argc == 2)
	{
		data->count_args = ft_count_values(argv[1], ' ');
		data->array_to_presort = malloc(sizeof(int) * data->count_args);
		if (data->array_to_presort == NULL)
			exit(1);
		ft_parse_single_arg(data, argv[1]);
	}
	else if (argc > 2)
		ft_parse_multiple_args(data, argc, argv);
	ft_process_intarr(data);
}
