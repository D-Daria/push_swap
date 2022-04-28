/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:29:21 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 21:48:28 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min_move_elem(t_data *data, t_stack *stack_b, int (*f)(int))
{
	t_stack	*min_move_elem;
	t_stack	*current;

	current = stack_b;
	min_move_elem = stack_b;
	if (data->b_size == 1)
		return (min_move_elem);
	while (current != NULL)
	{
		if (((*f)(min_move_elem->move) + (*f)(min_move_elem->a_score))
		> (*f)(current->move) + (*f)(current->a_score))
			min_move_elem = current;
		current = current->next;
	}
	return (min_move_elem);
}

void	ft_process_score(t_data *data)
{
	int		rotation;
	t_stack	*current_a;
	t_stack	*current_b;
	t_stack	*min_move_elem;

	current_a = data->a_head;
	current_b = data->b_head;
	rotation = 0;
	while (current_b != NULL)
	{
		rotation = ft_count_a_rotations(data, current_a, current_b);
		current_b->a_score = rotation;
		current_b = current_b->next;
	}
	min_move_elem = ft_find_min_move_elem(data, data->b_head, &ft_abs);
	data->b_score = min_move_elem->move;
	data->a_score = min_move_elem->a_score;
}

void	ft_set_moves(t_stack *stack, int lst_size)
{
	int		i;
	int		half;
	t_stack	*temp;

	i = -1;
	half = lst_size / 2;
	temp = stack;
	while (++i <= half)
	{
		temp->move = i;
		temp->up_down = 1;
		temp = temp->next;
	}
	if (lst_size % 2 == 0)
		i--;
	while (--i > 0)
	{
		temp->move = i * (-1);
		temp->up_down = -1;
		temp = temp->next;
	}
}

void	ft_big_sort_process(t_data *data)
{
	int	min_pos;

	while (data->b_size != 0)
	{
		ft_set_moves(data->b_head, data->b_size);
		ft_set_moves(data->a_head, data->a_size);
		ft_process_score(data);
		ft_choose_rotations(data);
	}
	min_pos = ft_list_indx_min(data, data->min, 'a');
	if (min_pos < (data->a_size / 2))
	{
		while (data->a_head->value != data->min)
			ft_ra_rb(data, 'a', 1);
	}
	else
		while (data->a_head->value != data->min)
			ft_rra_rrb(data, 'a', 1);
}
