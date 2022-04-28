/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:40:35 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/16 13:10:47 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack {
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data {
	t_stack	*a_head;
	t_stack	*b_head;
	int		*array_to_presort;
	int		a_size;
	int		b_size;
	int		count_args;
}			t_data;

/*ft_ch_parce_input.c*/
void	ft_ch_parse_input(t_data *data, int argc, const char **argv);

/*ft_ch_init_struct.c*/
void	ft_ch_init_struct(t_data *data);

/*ft_ch_valid_input.c*/
void	ft_ch_validate_input(int argc, const char **argv);

/*ft_ch_utils.c*/
int		ft_ch_count_values(char const *str, char c);
void	ft_ch_puterror(const char *error);
void	ft_ch_free_split(char **split_string);

/*ft_ch_process_intarr.c*/
void	ft_ch_process_intarr(t_data *data);
void	ft_ch_check_duplicates(t_data *data);

/*ft_create_delete_list.c*/
void	ft_ch_delete_list(t_stack **head);
t_stack	*ft_ch_create_list(t_data *data);

/*ft_ch_process_lists.c*/
int		ft_ch_list_size(t_stack *head);
int		ft_ch_is_list_sorted(t_stack *head);
void	ft_ch_push_listelem_front(t_stack **head, t_stack *new_node);
void	ft_ch_push_listelem_back(t_stack **head, t_stack *new_node);
t_stack	*ft_ch_create_new_listelem(int value);

/*ft_read_actions.c*/
void	ft_ch_read_actions(int fd, t_data *data);

/*ft_ch_validate_actions.c*/
void	ft_ch_validate_actions(t_data *data, char *line);

/*ft_ch_operations_mix.c*/
void	ft_sa_sb(t_data *data, char stack, int to_write);
void	ft_ra_rb(t_data *data, char stack, int to_write);
void	ft_rra_rrb(t_data *data, char stack, int to_write);
void	ft_rr(t_data *data, int to_write);
void	ft_rrr(t_data *data, int to_write);

/*ft_ch_operations_push.c*/
void	ft_pa(t_data *data, int to_write);
void	ft_pb(t_data *data, int to_write);
void	ft_ss(t_data *data);

/*ft_ch_actions.c*/
void	ft_swap(t_stack **head);
void	ft_rotate(t_stack **head);
void	ft_reverse_rotate(t_stack **head);

/*ft_ch_output.c*/
void	ft_ch_output(t_data *data);

#endif