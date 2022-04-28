/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:25:49 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 20:26:02 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void print_list(t_stack *head)
{
    t_stack *temp = head;
    while (temp != NULL)
    {
        printf("[%d] -> ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}*/

int	main(int argc, const char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		exit(1);
	if (argc < 2)
		exit(0);
	else
	{
		ft_init_struct(data);
		ft_parse_input(data, argc, argv);
	}
	ft_start_sort(data);
	free(data);
	data = NULL;
	return (0);
}
