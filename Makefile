CC				= 	gcc
CFLAGS			= 	-Wall -Wextra -Werror
NAME			= 	push_swap
BONUS_NAME		= 	checker
INCLUDES		= 	includes
SRCS_PATH		= 	./srcs/
BONUS_PATH		= 	./srcs_bonus/
LIBFT_PATH		= 	./libft/
MANDATORY_MAIN	=	$(SRCS_PATH)/main.c
SRCS_FILES    	= 	dlst_utils1.c dlst_utils2.c dlst_utils3.c \
					operations1.c operations2.c operations3.c \
					output.c args_check.c init.c reverse_stack.c \
					find_pivots.c ans_cut.c atob_qsort.c \
					a_3_algo_utils.c btoa_qsort.c b_3_algo_utils.c \
					algo_456.c algo_3.c algo_2.c av_to_dlst.c \
					all_free.c check_num_dup.c ps_atoi.c
BONUS_FILES    	= 	main_bonus.c operations1_bonus.c operations2_bonus.c \
					operations3_bonus.c output_bonus.c ans_check_bonus.c \
					ps_gnl_bonus.c ps_gnl_utils_bonus.c
SRCS			= 	$(addprefix $(SRCS_PATH)/, $(SRCS_FILES))
B_SRCS			= 	$(addprefix $(BONUS_PATH)/, $(BONUS_FILES))
SRCS_OBJS		= 	$(MANDATORY_MAIN:.c=.o) $(SRCS:.c=.o)
BONUS_OBJS		= 	$(B_SRCS:.c=.o) $(SRCS:.c=.o)
LIBFTMAKE		= 	$(MAKE) -C $(LIBFT_PATH)
LIBFTFLAG		= 	-L$(LIBFT_PATH) -lft

all:			$(NAME)

$(NAME):		$(SRCS_OBJS)
				$(LIBFTMAKE)
				$(CC) $(CFLAGS) $(SRCS_OBJS) $(LIBFTFLAG) -o $(NAME)

lib:
				$(LIBFTMAKE)

.c.o:
				$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
				$(LIBFTMAKE) clean
				$(RM) $(SRCS_OBJS) $(BONUS_OBJS)

fclean:			clean
				$(LIBFTMAKE) fclean
				$(RM) $(NAME) $(BONUS_NAME) $(SRCS_PATH)$(SRCS_OBJS) $(BONUS_PATH)$(BONUS_OBJS)

re:				fclean all

bonus:			$(NAME) $(BONUS_OBJS)
				$(LIBFTMAKE)
				$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFTFLAG) -o $(BONUS_NAME)

.PHONY:			all clean fclean bonus lib mlx re