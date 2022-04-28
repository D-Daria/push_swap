/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:50:24 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 22:32:44 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three_process(t_stack **head, t_data *data)
{
	if ((*head)->value == data->max)
	{
		ft_ra_rb(data, 'a', 1);
		if ((*head)->value == data->mid)
			ft_sa_sb(data, 'a');
		return ;
	}
	if ((*head)->value == data->mid)
	{
		if ((*head)->next->value == data->max)
			ft_rra_rrb(data, 'a', 1);
		else if ((*head)->next->value == data->min)
			ft_sa_sb(data, 'a');
		return ;
	}
	if ((*head)->value == data->min && !(ft_is_list_sorted(*head)))
	{
		ft_sa_sb(data, 'a');
		ft_ra_rb(data, 'a', 1);
		return ;
	}
}

void	ft_sort_three(t_stack **head, t_data *data)
{
	int		*sorted_arr;

	data->a_size = ft_list_size(data->a_head);
	sorted_arr = ft_list_to_intarr(data, 'a');
	ft_find_sorted_specs(data, sorted_arr, 'a');
	free(sorted_arr);
	ft_sort_three_process(head, data);
}

void	ft_small_sort(t_data *data)
{
	int		*sorted_arr;

	data->a_size = ft_list_size(data->a_head);
	sorted_arr = ft_list_to_intarr(data, 'a');
	ft_find_sorted_specs(data, sorted_arr, 'a');
	free(sorted_arr);
	if (data->a_size == 2 && data->a_head->value > data->a_head->next->value)
		ft_sa_sb(data, 'a');
	else if (data->a_size == 3)
		ft_sort_three(&data->a_head, data);
	else if (data->a_size > 3)
	{
		ft_sort_less_ten(data);
		ft_sort_three(&data->a_head, data);
		while (data->b_head != NULL)
			ft_pa(data, 1);
	}
}
