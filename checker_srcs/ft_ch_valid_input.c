/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_valid_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:09:43 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/15 17:09:50 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ch_validate_input(int argc, const char **argv)
{
	int		arg_num;
	size_t	j;
	size_t	str_len;

	arg_num = 1;
	str_len = 0;
	while (arg_num < argc)
	{
		str_len = ft_strlen(argv[arg_num]);
		if (str_len == 0)
			ft_ch_puterror("Error\n");
		j = 0;
		while (j < str_len)
		{
			if (ft_isdigit(argv[arg_num][j]) || (argv[arg_num][j] == ' ')
			|| (argv[arg_num][j] == '-' && ft_isdigit(argv[arg_num][j + 1])))
				j++;
			else
				ft_ch_puterror("Error\n");
		}
		arg_num++;
	}
}
