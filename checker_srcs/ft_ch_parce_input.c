/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_parce_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:39:58 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/15 17:07:59 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_ch_count_args(t_data *data, int argc, const char **arg_str)
{
	int	count_digits;
	int	i;

	i = 1;
	count_digits = 0;
	while (i < argc)
	{
		count_digits += ft_ch_count_values(arg_str[i], ' ');
		i++;
	}
	data->count_args = count_digits;
	if (data->count_args == 0)
		exit(0);
	data->array_to_presort = malloc(sizeof(int) * data->count_args);
	if (data->array_to_presort == NULL)
		exit(1);
}

static void	ft_ch_fill_arr(t_data *data, int argc, const char **arg_str, int *i)
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
		while (j < ft_ch_count_values(arg_str[*i], ' '))
		{
			value = ft_atoll(split_str[j]);
			if (value > INT_MAX || value < INT_MIN)
				ft_ch_puterror("Error\n");
			data->array_to_presort[k++] = value;
			j += 1;
		}
		ft_ch_free_split(split_str);
		*i += 1;
	}
}

static void	ft_ch_multiple_args(t_data *data, int argc, const char **arg_str)
{
	int	i;

	ft_ch_count_args(data, argc, arg_str);
	i = 1;
	ft_ch_fill_arr(data, argc, arg_str, &i);
}

static void	ft_ch_single_arg(t_data *data, const char *arg_str)
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
			ft_ch_puterror("Error\n");
		while (arg_str[i] == ' ')
			i++;
		while (arg_str[i] == '-' || ft_isdigit(arg_str[i]))
			i++;
		data->array_to_presort[j++] = value;
	}
}

void	ft_ch_parse_input(t_data *data, int argc, const char **argv)
{
	ft_ch_validate_input(argc, argv);
	if (argc == 2)
	{
		data->count_args = ft_ch_count_values(argv[1], ' ');
		if (data->count_args == 0)
			exit(0);
		data->array_to_presort = malloc(sizeof(int) * data->count_args);
		if (data->array_to_presort == NULL)
			exit(1);
		ft_ch_single_arg(data, argv[1]);
	}
	else if (argc > 2)
		ft_ch_multiple_args(data, argc, argv);
	ft_ch_process_intarr(data);
}
