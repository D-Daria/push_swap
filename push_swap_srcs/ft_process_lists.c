/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:33:34 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 20:34:53 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_size(t_stack *head)
{
	t_stack	*temp_head;
	int		count;

	count = 0;
	temp_head = head;
	while (temp_head != NULL)
	{
		count++;
		temp_head = temp_head->next;
	}
	return (count);
}

int	ft_is_list_sorted(t_stack *head)
{
	int		list_size;
	t_stack	*current;

	current = head;
	list_size = ft_list_size(head);
	if (list_size == 0 || list_size == 1)
		return (1);
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_push_listelem_front(t_stack **head, t_stack *new_node)
{
	new_node->next = *head;
	*head = new_node;
}

void	ft_push_listelem_back(t_stack **head, t_stack *new_node)
{
	t_stack	*temp;

	if (*head == NULL)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

t_stack	*ft_create_new_listelem(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
