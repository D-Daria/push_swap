/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:52:07 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 21:52:46 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_indx_max(t_data *data, int max, char stack)
{
	t_stack	*current;
	int		index_max;

	current = NULL;
	if (stack == 'a')
		current = data->a_head;
	else if (stack == 'b')
		current = data->b_head;
	index_max = 1;
	while (current->next)
	{
		if (current->value == max)
			return (index_max);
		current = current->next;
		index_max++;
	}
	return (-1);
}

int	ft_list_indx_min(t_data *data, int min, char stack)
{
	t_stack	*current;
	int		index_min;

	current = NULL;
	if (stack == 'a')
		current = data->a_head;
	else if (stack == 'b')
		current = data->b_head;
	index_min = 1;
	while (current)
	{
		if (current->value <= min)
			return (index_min);
		current = current->next;
		index_min++;
	}
	return (-1);
}

int	ft_find_list_min(t_data *data, char stack)
{
	t_stack	*current;
	int		min;

	current = NULL;
	if (stack == 'a')
		current = data->a_head;
	else if (stack == 'b')
		current = data->b_head;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	ft_find_list_max(t_data *data, char stack)
{
	t_stack	*current;
	int		max;

	current = NULL;
	if (stack == 'a')
		current = data->a_head;
	else if (stack == 'b')
		current = data->b_head;
	max = current->value;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	ft_find_sorted_specs(t_data *data, int *arr, char stack)
{
	int	count;
	int	quater;

	count = 0;
	if (stack == 'a')
		count = data->a_size;
	else if (stack == 'b')
		count = data->b_size;
	if (count > 10)
	{
		quater = (count / 4);
		data->quater = arr[quater];
	}
	data->min = arr[0];
	data->max = arr[count - 1];
	data->mid = arr[count / 2];
}
