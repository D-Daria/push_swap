/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:42:04 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/15 17:04:45 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		ft_ch_init_struct(data);
		ft_ch_parse_input(data, argc, argv);
	}
	ft_ch_read_actions(0, data);
	ft_ch_output(data);
	if (data->a_head != NULL)
		ft_ch_delete_list(&data->a_head);
	if (data->b_head != NULL)
		ft_ch_delete_list(&data->b_head);
	free(data);
	data = NULL;
	return (0);
}
