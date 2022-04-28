/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_a_rotations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:35:04 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 21:48:49 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bigger_val(t_stack **current_a, t_stack *b, int *a_val, int *r)
{
	while ((*current_a) != NULL)
	{
		*a_val = (*current_a)->value;
		if (b->value > (*current_a)->value)
		{
			*r += 1;
			if (b->value < (*current_a)->next->value)
				break ;
			(*current_a) = (*current_a)->next;
		}
		else
			break ;
	}
}

static int	ft_check_smaller(t_data *data, t_stack *b, int a_val)
{
	int		smaller_in_a_exists;
	t_stack	*a_temp;

	smaller_in_a_exists = 0;
	a_temp = data->a_head;
	while (a_temp != NULL && smaller_in_a_exists == 0)
	{
		if (a_temp->value < a_val && a_temp->value > b->value)
			smaller_in_a_exists = 1;
		a_temp = a_temp->next;
	}
	return (smaller_in_a_exists);
}

static void	ft_smaller_val(t_stack **a, t_stack *b, int a_val, int *r)
{
	while ((*a) != NULL)
	{
		if ((*a)->value < a_val && (*a)->value > b->value)
			break ;
		*r += 1;
		(*a) = (*a)->next;
	}
}

int	ft_count_a_rotations(t_data *data, t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	int		current_a_value;
	int		rotation;

	current_a = a;
	rotation = 0;
	ft_bigger_val(&current_a, b, &current_a_value, &rotation);
	if (ft_check_smaller(data, b, current_a_value) == 1)
		ft_smaller_val(&current_a, b, current_a_value, &rotation);
	if (current_a->up_down == -1)
	{
		rotation = data->a_size - rotation;
		rotation *= (-1);
	}
	return (rotation);
}
