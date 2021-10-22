CC				= 	gcc
CFLAGS			= 	-Wall -Wextra -Werror
NAME			= 	push_swap
BONUS_NAME			= 	checker
INCLUDES		= 	includes
SRCS_PATH		= 	./srcs/
BONUS_PATH		= 	./srcs_bonus/
LIBFT_PATH		= 	./libft/
MAND_MAIN		=	$(SRCS_PATH)main.c 
SRCS_FILES    	= 	$(SRCS_PATH)dlst_utils1.c $(SRCS_PATH)dlst_utils2.c $(SRCS_PATH)dlst_utils3.c \
					$(SRCS_PATH)operations1.c $(SRCS_PATH)operations2.c $(SRCS_PATH)operations3.c $(SRCS_PATH)output.c \
					$(SRCS_PATH)args_check.c $(SRCS_PATH)init.c $(SRCS_PATH)reverse_stack.c $(SRCS_PATH)find_pivots.c \
					$(SRCS_PATH)ans_cut.c $(SRCS_PATH)atob_qsort.c $(SRCS_PATH)a_3_algo_utils.c $(SRCS_PATH)btoa_qsort.c \
					$(SRCS_PATH)b_3_algo_utils.c $(SRCS_PATH)algo_456.c $(SRCS_PATH)algo_3.c $(SRCS_PATH)algo_2.c \
					$(SRCS_PATH)av_to_dlst.c $(SRCS_PATH)all_free.c $(SRCS_PATH)check_num_dup.c $(SRCS_PATH)ps_atoi.c
BONUS_MAIN    	= 	$(BONUS_PATH)main_bonus.c $(BONUS_PATH)operations1_bonus.c $(BONUS_PATH)operations2_bonus.c \
					$(BONUS_PATH)operations3_bonus.c $(BONUS_PATH)output_bonus.c $(BONUS_PATH)ans_check_bonus.c \
					$(BONUS_PATH)ps_gnl_bonus.c $(BONUS_PATH)ps_gnl_utils_bonus.c  
SRCS_OBJS		= 	$(SRCS_FILES:.c=.o) $(MAND_MAIN:.c=.o)
BONUS_OBJS		= 	$(SRCS_FILES:.c=.o) $(BONUS_MAIN:.c=.o)
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