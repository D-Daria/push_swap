/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:11:40 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/15 15:14:18 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (ft_ch_list_size((*head)) < 2)
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
	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	current = *head;
	while (current->next->next != NULL)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = *head;
	*head = last;
}
