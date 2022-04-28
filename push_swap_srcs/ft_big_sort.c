/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:28:43 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 21:38:32 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_mix(t_data *data)
{
	while (data->a_score > 0 && data->b_score > 0)
	{
		ft_rr(data, 1);
		data->b_score--;
		data->a_score--;
	}
	while (data->a_score < 0 && data->b_score < 0)
	{
		ft_rrr(data, 1);
		data->a_score++;
		data->b_score++;
	}
}

void	ft_rotate_single(t_data *data)
{
	while (data->b_score > 0)
	{
		ft_ra_rb(data, 'b', 1);
		data->b_score--;
	}
	while (data->b_score < 0)
	{
		ft_rra_rrb(data, 'b', 1);
		data->b_score++;
	}
	while (data->a_score > 0)
	{
		ft_ra_rb(data, 'a', 1);
		data->a_score--;
	}
	while (data->a_score < 0)
	{
		ft_rra_rrb(data, 'a', 1);
		data->a_score++;
	}
}

void	ft_choose_rotations(t_data *data)
{
	ft_rotate_mix(data);
	ft_rotate_single(data);
	ft_pa(data, 1);
}

static void	ft_big_push_to_b(t_data *data)
{
	while (data->a_size > 3)
	{
		if (data->a_head->value != data->max && data->a_head->value != data->mid
			&& data->a_head->value != data->min)
		{
			ft_pb(data, 1);
			if (data->b_head->value > data->mid)
				ft_ra_rb(data, 'b', 1);
		}
		else
			ft_ra_rb(data, 'a', 1);
	}
	ft_sort_three(&data->a_head, data);
	ft_ra_rb(data, 'a', 1);
}

void	ft_big_sort(t_data *data)
{
	int	*sorted_arr;

	data->a_size = ft_list_size(data->a_head);
	sorted_arr = ft_list_to_intarr(data, 'a');
	ft_find_sorted_specs(data, sorted_arr, 'a');
	free(sorted_arr);
	ft_big_push_to_b(data);
	ft_big_sort_process(data);
}
