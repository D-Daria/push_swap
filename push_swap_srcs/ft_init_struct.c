/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:30:52 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 20:30:54 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_struct(t_data *data)
{
	data->a_head = NULL;
	data->b_head = NULL;
	data->a_size = 0;
	data->b_size = 0;
	data->a_score = 0;
	data->b_score = 0;
	data->count_args = 0;
	data->max = 0;
	data->min = 0;
	data->mid = 0;
	data->quater = 0;
	data->max_index = 0;
	data->mid_index = 0;
	data->min_index = 0;
}
