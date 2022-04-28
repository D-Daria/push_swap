/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:53:33 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/13 21:53:44 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_validate_input(int argc, const char **argv)
{
	int		arg_num;
	size_t	j;
	size_t	str_len;

	arg_num = 1;
	str_len = 0;
	while (arg_num < argc)
	{
		str_len = ft_strlen(argv[arg_num]);
		if (str_len == 0 && argc == 2)
			break ;
		j = 0;
		while (j < str_len)
		{
			if (ft_isdigit(argv[arg_num][j]) || (argv[arg_num][j] == ' ')
			|| (argv[arg_num][j] == '-' && ft_isdigit(argv[arg_num][j + 1])))
				j++;
			else
				ft_puterror("Error\n");
		}
		arg_num++;
	}
}
