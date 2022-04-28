/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_read_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:35:42 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/15 17:06:29 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ch_read_actions(int fd, t_data *data)
{
	char	*line;

	line = NULL;
	data->a_size = ft_ch_list_size(data->a_head);
	data->b_size = ft_ch_list_size(data->b_head);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_ch_validate_actions(data, line);
		free(line);
		line = NULL;
	}
}
