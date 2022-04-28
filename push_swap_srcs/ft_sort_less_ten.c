/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_less_ten.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:51:06 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 21:51:54 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_less_ten_process(t_data *data, int *min, int *half)
{
	int	index_of_min;

	while (*min != data->a_head->value)
	{
		index_of_min = ft_list_indx_min(data, *min, 'a');
		*half = (ft_list_size(data->a_head) / 2);
		if (index_of_min < *half)
			ft_ra_rb(data, 'a', 1);
		else
			ft_rra_rrb(data, 'a', 1);
	}
}

void	ft_sort_less_ten(t_data *data)
{
	int		min;
	int		half;
	t_stack	*a_following;

	min = 0;
	half = 0;
	a_following = NULL;
	while (data->a_size > 3)
	{
		min = ft_find_list_min(data, 'a');
		a_following = data->a_head->next;
		if (data->a_head->value != min && a_following->value == min
			&& a_following != NULL)
			ft_sa_sb(data, 'a');
		ft_sort_less_ten_process(data, &min, &half);
		if (data->a_head->value == min)
			ft_pb(data, 1);
	}
}
