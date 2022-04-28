# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 16:03:20 by mrhyhorn          #+#    #+#              #
#    Updated: 2022/03/11 14:17:59 by mrhyhorn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

SRCS_MDIR = push_swap_srcs/
SRCS_BDIR = checker_srcs/

SRCS_MF =  push_swap.c\
		ft_actions.c ft_big_sort_process.c\
		ft_big_sort.c ft_count_a_rotations.c\
		ft_create_delete_list.c ft_errors.c\
		ft_init_struct.c\
		ft_operations_mix.c ft_operations_push.c\
		ft_parce_input.c ft_presort.c\
		ft_process_intarr.c ft_process_lists.c\
		ft_small_sort.c\
		ft_sort_less_ten.c ft_specs.c\
		ft_start_sort.c ft_utils.c\
		ft_validate_input.c

SRCS_BF = checker.c\
		ft_ch_actions.c ft_ch_create_delete_list.c\
		ft_ch_init_struct.c ft_ch_operations_mix.c\
		ft_ch_operations_push.c ft_ch_output.c\
		ft_ch_parce_input.c ft_ch_process_intarr.c\
		ft_ch_process_lists.c ft_ch_read_actions.c\
		ft_ch_utils.c ft_ch_valid_input.c\
		ft_ch_validate_actions.c

SRCS_M = $(addprefix $(SRCS_MDIR), $(SRCS_MF))
OBJS_M = $(patsubst %.c,%.o, $(SRCS_M))
D_FILES_M = $(patsubst %.c,%.d, $(SRCS_M))

SRCS_B = $(addprefix $(SRCS_BDIR), $(SRCS_BF))
OBJS_B = $(patsubst %.c,%.o, $(SRCS_B))
D_FILES_B = $(patsubst %.c,%.d, $(SRCS_B))

INCLUDES = -I includes/ -I libft/libft_includes/

DIR_LIB = libft/
LIBFT = ./libft/libft.a
LIB_A = -L./libft/ -lft
LIB = libft.a
LIB_SOURCE = $(addprefix $(DIR_LIB), $(LIB))

#colors
RED 	= 	\033[0;31m
GREEN 	= 	\033[0;32m
BLUE	=	\033[0;34m
BREAK 	= 	\033[0m

OPFLAGS = -O2
CFLAGS = -Wall -Wextra -Werror
SANIT_FLAGS = gcc -g -fsanitize=address $(CFLAGS)

.PHONY : all bonus clean fclean sanit_m sanit_b re lib

all : lib $(NAME) $(NAME_B)

lib :
	make -C libft/

$(NAME) : $(OBJS_M) $(LIBFT)
	gcc $(CFLAGS) $(OPFLAGS) $(OBJS_M) $(LIB_A) -o $(NAME)
	@echo "$(GREEN)$(NAME) was created$(BREAK)"

bonus : $(NAME_B)

$(NAME_B) : $(OBJS_B) $(LIBFT)
	gcc $(CFLAGS) $(OPFLAGS) $(OBJS_B) $(LIB_A) -o $(NAME_B)
	@echo "$(GREEN)$(NAME_B) was created$(BREAK)"

%.o : %.c
	gcc $(CFLAGS) $(OPFLAGS) $(INCLUDES) -c $< -o $@ -MD

clean :
	make -C libft/ $@
	rm -f $(OBJS_M) $(OBJS_B) $(D_FILES_M) $(D_FILES_B)
	@echo "$(BLUE)objs were deleted$(BREAK)"

fclean : clean
	make -C libft/ $@
	@echo "$(RED)$(LIB) was deleted$(BREAK)"
	rm -f $(NAME) $(NAME_B)
	@echo "$(RED)$(NAME) was deleted$(BREAK)"
	rm -f $(NAME_B)
	@echo "$(RED)$(NAME_B) was deleted$(BREAK)"

re : fclean all

sanit_m :
	$(SANIT_FLAGS) $(OBJS_M) $(LIB_A) -o $(NAME)

sanit_b :
	$(SANIT_FLAGS) $(OBJS_B) $(LIB_A) -o $(NAME_B)

include $(wildcard $(D_FILES_M))
include $(wildcard $(D_FILES_B))