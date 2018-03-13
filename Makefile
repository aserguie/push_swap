# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aserguie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/20 17:36:50 by aserguie          #+#    #+#              #
#    Updated: 2018/03/13 17:29:04 by aserguie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap

NAME_CH = checker

CC = gcc

FLAGS = -Werror -Wall -Wextra #-fsanitize=address

SRC = 	ft_set.c \
		ft_index.c	\
		ft_parse.c \
		ft_create_node_list.c \
		ft_create_node_cdll.c \
		ft_erase_node.c \
		ft_add_end_cdll.c \
		ft_push_back_cdll.c \
		ft_swap.c \
		ft_rotate.c \
		ft_rev_rotate.c \
		ft_pop_node_cdll.c \
		ft_is_numbers.c \
		ft_short.c \
		ft_long.c \
		ft_instruction.c \
		ft_limits.c \
		ft_atoi_l.c \
		ft_display_instruction.c \
		ft_target.c \
		ft_merge.c \
		ft_sorted.c \
		ft_display_stacks.c \
		ft_parse_flags.c \
		ft_free_set.c \
		ft_min_max.c

SRC_PS = push_swap.c \

SRC_CH = checker.c \
		 ft_check_commands.c

OBJ = $(SRC:%.c=%.o)

OBJ_PS = $(SRC_PS:%.c=%.o)

OBJ_CH = $(SRC_CH:%.c=%.o)

SRC_DIR = ./src/

INC_DIR  = ./inc/

HEADERS = $(INC_DIR)/push_swap.h $(LIB_DIR)/libft.h

LIB_DIR = ./libft

LIBFT = $(LIB_DIR)/libft.a

all : mklib $(NAME_PS) $(NAME_CH)

$(NAME_PS):$(LIBFT) $(OBJ) $(OBJ_PS) $(HEADERS)
	$(CC) $(FLAGS) -o $(NAME_PS) $(OBJ) $(OBJ_PS) $(LIBFT) -I$(INC_DIR) -I$(LIB_DIR)

$(NAME_CH):$(LIBFT) $(OBJ) $(OBJ_CH) $(HEADERS)
	$(CC) $(FLAGS) -o $(NAME_CH) $(OBJ) $(OBJ_CH) $(LIBFT) -I$(INC_DIR) -I$(LIB_DIR)

%.o:$(SRC_DIR)%.c $(HEADERS) $(LIBFT)
		$(CC) $(FLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIB_DIR)

mklib:
		make -C $(LIB_DIR) 

clean:
		rm -f $(OBJ) $(OBJ_PS) $(OBJ_CH)

fclean: clean
		rm -f $(NAME_PS)
		rm -f $(NAME_CH)

re: fclean all

clean_lib:
		rm -f $(OBJ) $(OBJ_PS) $(OBJ_CH)
		make clean -C $(LIB_DIR)

fclean_lib:clean
		rm -f $(NAME_PS)
		rm -f $(NAME_CH)
		make fclean -C $(LIB_DIR)

re_lib:fclean_lib all

.PHONY:all clean fclean re mklib
