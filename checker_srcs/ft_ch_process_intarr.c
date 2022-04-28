/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_process_intarr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:03:09 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/14 17:39:31 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ch_check_duplicates(t_data *data)
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
				ft_ch_puterror("Error\n");
			}
			j++;
		}
		i++;
	}
}

void	ft_ch_process_intarr(t_data *data)
{
	ft_ch_check_duplicates(data);
	data->a_head = ft_ch_create_list(data);
	free(data->array_to_presort);
	data->array_to_presort = NULL;
}
