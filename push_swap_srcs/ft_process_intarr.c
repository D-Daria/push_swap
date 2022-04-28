/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_intarr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:33:09 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 20:33:22 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_intarr_sorted(t_data *data)
{
	int	i;

	if (data->count_args == 0 || data->count_args == 1)
		return (1);
	i = 1;
	while (i < data->count_args)
	{
		if (data->array_to_presort[i - 1] > data->array_to_presort[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_duplicates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->count_args - 1)
	{
		j = i + 1;
		while (j < data->count_args)
		{
			if (data->array_to_presort[i] == data->array_to_presort[j])
			{
				free(data->array_to_presort);
				data->array_to_presort = NULL;
				ft_puterror("Error\n");
			}
			j++;
		}
		i++;
	}
}

void	ft_process_intarr(t_data *data)
{
	ft_check_duplicates(data);
	if (ft_is_intarr_sorted(data) == 1)
	{
		free(data->array_to_presort);
		data->array_to_presort = NULL;
		exit(0);
	}
	else
	{
		data->a_head = ft_create_list(data);
		free(data->array_to_presort);
		data->array_to_presort = NULL;
	}
}
