/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:52:56 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 21:53:01 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_start_sort(t_data *data)
{
	if (data->count_args <= 10)
		ft_small_sort(data);
	else if (data->count_args > 10)
		ft_big_sort(data);
	if (data->a_head != NULL)
		ft_delete_list(&data->a_head);
	if (data->b_head != NULL)
		ft_delete_list(&data->b_head);
}
