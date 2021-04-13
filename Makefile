# SUBDIRS = $(shell find .. -type d | grep -Ev "(.git|.vscode)")
# IFLAGS = $(addprefix -I, $(SUBDIRS))
LIBFT_DIR =	src/libft
CFLAGS =	-Wall -Wextra # -Werror
LFLAGS =	-L$(LIBFT_DIR) -lft
IFLAGS =	-I$(LIBFT_DIR) -Iincludes
DBFLAGS =	-g3 -fsanitize=address
# SRCS_PS =$(addprefix src/pswap/, push_swap.c)
SRCS_PS =$(addprefix src/pswap/, push_swap.c)
SRCS_PS +=$(addprefix src/pswap/algo/, go_to_first_rem.c push_while_rem.c)
SRCS_PS +=$(addprefix src/pswap/destroy/, destroy_paths.c destroy_permut.c)
SRCS_PS +=$(addprefix src/pswap/init/, bubble_sort.c chose_path.c compute_bij.c \
        compute_indices.c compute_spots.c compute_trans.c copy_array.c \
        create_permut.c select_remaining.c update_all_paths.c update_paths.c)
SRCS_PS +=$(addprefix src/pswap/operations/, nrotate.c push.c rotate.c \
        rotate_reverse.c swap.c)
SRCS_PS +=$(addprefix src/pswap/utils/, utils.c utils_lst.c utils_test.c)
OBJS_PS =$(SRCS_PS:%.c=%.o)
SRCS_CHK =$(addprefix src/checker/, check_ok.c checker.c read_execute.c)
OBJS_CHK =$(SRCS_CHK:%.c=%.o)
SRCS_COM =$(addprefix src/common/, args_to_stacks.c errors.c free.c handle_args.c \
        is_sorted_lst.c lstrev_array.c print_list.c print_stacks.c \
        repeating_numbers.c)
SRCS_COM +=$(addprefix src/get_next_line/, get_next_line.c get_next_line_utils.c)
SRCS_COM +=$(addprefix src/operations/, parse_operation.c push.c rotate.c \
        rotate_reverse.c swap.c)
OBJS_COM =$(SRCS_COM:%.c=%.o)
OBJS_CHK =	$(OBJS_COM) $(SRCS_CHK:%.c=%.o)
OBJS_PS =	$(OBJS_COM) $(SRCS_PS:%.c=%.o)

all:	libft checker

%.o:	%.c
	gcc -c -o $@ $< $(CFLAGS) $(IFLAGS)

checker: libft $(OBJS_CHK)
	gcc -o $@ $^ $(LFLAGS)

push_swap: libft $(OBJS_PS)
	gcc -o $@ $^ $(LFLAGS)

libft:
	make -C $(LIBFT_DIR) bonus

_test_chk_%:	_test_chk_%.c $(filter-out %/checker.o, $(OBJS_CHK)) libft
	gcc $< -o $@ $(filter-out %/checker.o, $(OBJS_CHK)) $(IFLAGS) $(LFLAGS)

_test_ps_%:	_test_ps_%.c $(filter-out %/push_swap.o, $(OBJS_PS)) libft
	gcc $< -o $@ $(filter-out %/push_swap.o, $(OBJS_PS)) $(IFLAGS) $(LFLAGS) $(DBFLAGS)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS_CHK)
	rm -f $(OBJS_PS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	rm -f checker

re:	fclean all

.PHONY:	all libft clean fclean re
