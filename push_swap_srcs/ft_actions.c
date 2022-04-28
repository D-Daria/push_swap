/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:26:40 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/14 12:30:26 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_from_list_to_list(t_stack **from, t_stack **to)
{
	t_stack	*new;

	new = NULL;
	if (from != NULL && to == NULL)
		*to = ft_create_new_listelem((*from)->value);
	else
	{
		if (*from != NULL)
		{
			new = ft_create_new_listelem((*from)->value);
			if (new == NULL)
				return ;
			ft_push_listelem_front(to, new);
			*from = (*from)->next;
		}
	}
}

void	ft_swap(t_stack **head)
{
	int		first_value;
	int		next_value;
	t_stack	*temp;

	if ((*head) == NULL)
		return ;
	if ((*head)->next != NULL)
	{
		temp = *head;
		first_value = (*head)->value;
		next_value = (*head)->next->value;
		(*head)->value = next_value;
		(*head)->next->value = first_value;
		(*head) = temp;
	}
}

void	ft_rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*current;

	if ((*head) == NULL)
		return ;
	if (ft_list_size((*head)) < 2)
		return ;
	current = *head;
	while (current->next != NULL)
		current = current->next;
	first = *head;
	*head = first->next;
	first->next = NULL;
	current->next = first;
}

void	ft_reverse_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*current;

	last = NULL;
	if ((*head) == NULL)
		return ;
	if (ft_list_size((*head)) < 2)
		return ;
	current = *head;
	while (current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = *head;
	*head = last;
}
