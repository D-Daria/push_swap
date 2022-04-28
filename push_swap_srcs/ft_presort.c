/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:32:26 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 20:32:56 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_presort_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_presort(int *arr_to_sort, int count)
{
	int	i;
	int	j;

	i = 0;
	if (arr_to_sort == NULL)
		exit(0);
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (arr_to_sort[j] > arr_to_sort[j + 1])
			{
				ft_presort_swap(&arr_to_sort[j],
					&arr_to_sort[j + 1]);
			}
			j++;
		}
		i++;
	}
}

t_stack	*ft_choose_list(t_data *data, char stack, int *lst_size)
{
	t_stack	*current;

	current = NULL;
	if (stack == 'a')
	{
		current = data->a_head;
		*lst_size = data->a_size;
	}
	else if (stack == 'b')
	{
		current = data->b_head;
		*lst_size = data->b_size;
	}
	return (current);
}

int	*ft_list_to_intarr(t_data *data, char stack)
{
	t_stack	*current;
	int		current_list_size;
	int		count;
	int		*sorted_arr;

	current = ft_choose_list(data, stack, &current_list_size);
	sorted_arr = malloc(sizeof(int) * current_list_size);
	if (sorted_arr == NULL)
		return (NULL);
	count = 0;
	while (count < current_list_size)
	{
		sorted_arr[count] = current->value;
		current = current->next;
		count++;
	}
	ft_presort(sorted_arr, current_list_size);
	return (sorted_arr);
}
