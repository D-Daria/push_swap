/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_mix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:31:18 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 20:31:20 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_data *data, char stack)
{
	if (stack == 'a')
	{
		ft_swap(&data->a_head);
		ft_putstr_fd("sa\n", 1);
	}
	else if (stack == 'b')
	{
		ft_swap(&data->b_head);
		ft_putstr_fd("sb\n", 1);
	}
}

void	ft_ra_rb(t_data *data, char stack, int to_write)
{
	if (stack == 'a')
	{
		if (data->a_size < 2)
			return ;
		ft_rotate(&data->a_head);
		if (to_write == 1)
			ft_putstr_fd("ra\n", 1);
	}
	else if (stack == 'b')
	{
		if (data->b_size < 2)
			return ;
		ft_rotate(&data->b_head);
		if (to_write == 1)
			ft_putstr_fd("rb\n", 1);
	}
}

void	ft_rra_rrb(t_data *data, char stack, int to_write)
{
	if (stack == 'a')
	{
		if (ft_list_size((data->a_head)) < 2)
			return ;
		ft_reverse_rotate(&data->a_head);
		if (to_write == 1)
			ft_putstr_fd("rra\n", 1);
	}
	else if (stack == 'b')
	{
		if (ft_list_size((data->b_head)) < 2)
			return ;
		ft_reverse_rotate(&data->b_head);
		if (to_write == 1)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_rr(t_data *data, int to_write)
{
	if (ft_list_size((data->a_head)) < 2)
		return ;
	ft_rotate(&data->a_head);
	if (ft_list_size((data->b_head)) < 2)
		return ;
	ft_rotate(&data->b_head);
	if (to_write == 1)
		ft_putstr_fd("rr\n", 1);
}

void	ft_rrr(t_data *data, int to_write)
{
	if (ft_list_size((data->a_head)) < 2)
		return ;
	ft_reverse_rotate(&data->a_head);
	if (ft_list_size((data->b_head)) < 2)
		return ;
	ft_reverse_rotate(&data->b_head);
	if (to_write == 1)
		ft_putstr_fd("rrr\n", 1);
}
