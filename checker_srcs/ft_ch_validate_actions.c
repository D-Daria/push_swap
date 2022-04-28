/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_validate_actions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:24:53 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/15 17:09:31 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_ch_validate_actions_push(t_data *data, char *line, int *check)
{
	if (ft_strcmp(line, "pa\n") == 0)
	{
		ft_pa(data, 0);
		*check = 1;
	}
	else if (ft_strcmp(line, "pb\n") == 0)
	{
		ft_pb(data, 0);
		*check = 1;
	}
}

static void	ft_ch_validate_actions_mix(t_data *data, char *line, int *check)
{
	if (ft_strcmp(line, "rr\n") == 0)
	{
		ft_rr(data, 0);
		*check = 1;
	}
	else if (ft_strcmp(line, "rrr\n") == 0)
	{
		ft_rrr(data, 0);
		*check = 1;
	}
	else if (ft_strcmp(line, "ss\n") == 0)
	{
		ft_ss(data);
		*check = 1;
	}
}

static void	ft_ch_validate_actions_a(t_data *data, char *line, int *check)
{
	if (ft_strcmp(line, "sa\n") == 0)
	{
		ft_sa_sb(data, 'a', 0);
		*check = 1;
	}
	else if (ft_strcmp(line, "ra\n") == 0)
	{
		ft_ra_rb(data, 'a', 0);
		*check = 1;
	}
	else if (ft_strcmp(line, "rra\n") == 0)
	{
		ft_rra_rrb(data, 'a', 0);
		*check = 1;
	}
}

static void	ft_ch_validate_actions_b(t_data *data, char *line, int *check)
{
	if (ft_strcmp(line, "sb\n") == 0)
	{
		ft_sa_sb(data, 'b', 0);
		*check = 1;
	}
	if (ft_strcmp(line, "rrb\n") == 0)
	{
		ft_rra_rrb(data, 'b', 0);
		*check = 1;
	}
	else if (ft_strcmp(line, "rb\n") == 0)
	{
		ft_ra_rb(data, 'b', 0);
		*check = 1;
	}
}

void	ft_ch_validate_actions(t_data *data, char *line)
{
	int	check;

	check = 0;
	ft_ch_validate_actions_push(data, line, &check);
	ft_ch_validate_actions_a(data, line, &check);
	ft_ch_validate_actions_b(data, line, &check);
	ft_ch_validate_actions_mix(data, line, &check);
	if (check == 0)
		ft_ch_puterror("Error\n");
}
