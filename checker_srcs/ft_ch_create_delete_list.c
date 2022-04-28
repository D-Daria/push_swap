/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_create_delete_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:08:52 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/14 16:23:02 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ch_delete_list(t_stack **head)
{
	t_stack	*next;

	if (*head != NULL)
	{
		while (*head != NULL)
		{
			next = (*head)->next;
			free(*head);
			*head = NULL;
			*head = next;
		}
	}
	free(*head);
	*head = NULL;
}

t_stack	*ft_ch_create_list(t_data *data)
{
	t_stack	*new_node;
	int		i;

	i = 0;
	while (i < data->count_args)
	{
		new_node = ft_ch_create_new_listelem(data->array_to_presort[i]);
		ft_ch_push_listelem_back(&data->a_head, new_node);
		new_node = NULL;
		i++;
	}
	return (data->a_head);
}
