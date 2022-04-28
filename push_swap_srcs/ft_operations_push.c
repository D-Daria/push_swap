/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:31:30 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 20:31:43 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_data *data, int to_write)
{
	t_stack	*temp;

	if (data->b_head == NULL)
		return ;
	if (data->b_size > 0)
	{
		data->b_size--;
		data->a_size++;
	}
	temp = data->b_head;
	data->b_head = data->b_head->next;
	temp->next = data->a_head;
	data->a_head = temp;
	if (to_write == 1)
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_data *data, int to_write)
{
	t_stack	*temp;

	if (data->a_head == NULL)
		return ;
	if (data->a_size > 0)
	{
		data->a_size--;
		data->b_size++;
	}
	temp = data->a_head;
	data->a_head = data->a_head->next;
	temp->next = data->b_head;
	data->b_head = temp;
	if (to_write == 1)
		ft_putstr_fd("pb\n", 1);
}
