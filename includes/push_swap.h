/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:55:05 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/02/16 13:11:11 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft.h"

/*# include "stdio.h"*/

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack {
	int				value;
	int				move;
	int				up_down;
	int				a_score;
	int				b_score;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data {
	t_stack	*a_head;
	t_stack	*b_head;
	int		*array_to_presort;
	int		a_size;
	int		b_size;
	int		a_score;
	int		b_score;
	int		count_args;
	int		max;
	int		mid;
	int		min;
	int		quater;
	int		max_index;
	int		mid_index;
	int		min_index;
}			t_data;

void print_list(t_stack *head);

/*ft_init_struct.ct*/
void	ft_init_struct(t_data *data);

/*ft_parce_input.c*/
void	ft_parse_input(t_data *data, int argc, const char **argv);
void	ft_parse_multiple_args(t_data *data, int argc, const char **arg_str);
void	ft_parse_single_arg(t_data *data, const char *arg_str);

/*ft_validate_input.c*/
void	ft_validate_input(int argc, const char **argv);

/*ft_utils.c*/
int		ft_abs(int value);
int		ft_count_values(char const *str, char c);
void	ft_free_split(char **split_string);

/*ft_errors.c*/
void	ft_puterror(const char *error);

/*ft_process_intarr.c*/
void	ft_process_intarr(t_data *data);
void	ft_check_duplicates(t_data *data);
int		ft_is_intarr_sorted(t_data *data);

/*ft_create_delete_list.c*/
t_stack	*ft_create_list(t_data *data);
void	ft_delete_list(t_stack **head);

/*ft_process_lists.c*/
int		ft_list_size(t_stack *head);
int		ft_is_list_sorted(t_stack *head);
void	ft_push_listelem_front(t_stack **head, t_stack *new_node);
void	ft_push_listelem_back(t_stack **head, t_stack *new_node);
t_stack	*ft_create_new_listelem(int value);

/*ft_start_sort.c*/
void	ft_start_sort(t_data *data);

/*ft_small_sort.c*/
void	ft_small_sort(t_data *data);
void	ft_sort_three(t_stack **head, t_data *data);

/*ft_sort_less_ten.c*/
void	ft_sort_less_ten(t_data *data);

/*ft_big_sort.c*/
void	ft_big_sort(t_data *data);
void	ft_big_sort_process(t_data *data);
void	ft_choose_rotations(t_data *data);
void	ft_rotate_single(t_data *data);
void	ft_rotate_mix(t_data *data);

/*ft_big_sort_process.c*/
void	ft_big_sort_process(t_data *data);
void	ft_set_moves(t_stack *stack, int lst_size);
void	ft_process_score(t_data *data);
t_stack	*ft_find_min_move_elem(t_data *data, t_stack *stack_b, int (*f)(int));

/*ft_count_a_rotations.c*/
int		ft_count_a_rotations(t_data *data, t_stack *a, t_stack *b);

/*ft_presort.c*/
int		*ft_list_to_intarr(t_data *data, char stack);
t_stack	*ft_choose_list(t_data *data, char stack, int *lst_size);
void	ft_presort(int *arr_to_sort, int count);

/*ft_specs.c*/
void	ft_find_sorted_specs(t_data *data, int *arr, char stack);
int		ft_find_list_min(t_data *data, char stack);
int		ft_find_list_max(t_data *data, char stack);
int		ft_list_indx_min(t_data *data, int min, char stack);
int		ft_list_indx_max(t_data *data, int max, char stack);

/*ft_operations_mix.c*/
void	ft_sa_sb(t_data *data, char stack);
void	ft_ra_rb(t_data *data, char stack, int to_write);
void	ft_rra_rrb(t_data *data, char stack, int to_write);
void	ft_rr(t_data *data, int to_write);
void	ft_rrr(t_data *data, int to_write);

/*ft_operations_push.c*/
void	ft_pa(t_data *data, int to_write);
void	ft_pb(t_data *data, int to_write);

/*ft_actions.c*/
void	ft_swap(t_stack **head);
void	ft_rotate(t_stack **head);
void	ft_reverse_rotate(t_stack **head);
void	ft_push_from_list_to_list(t_stack **from, t_stack **to);

#endif
