/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_init_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:05:07 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/15 17:05:18 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_ch_init_struct(t_data *data)
{
	data->a_head = NULL;
	data->b_head = NULL;
	data->a_size = 0;
	data->b_size = 0;
	data->count_args = 0;
}
