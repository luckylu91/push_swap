# SUBDIRS = $(shell find .. -type d | grep -Ev "(.git|.vscode)")
# IFLAGS = $(addprefix -I, $(SUBDIRS))
LIBFT_DIR =	src/libft
CFLAGS =	-Wall -Wextra # -Werror
CHK_DIR =	src/checker
PS_DIR =	src/pswap
COMMON_DIR =	src/common
OP_DIR =	src/operations
GNL_DIR =	src/get_next_line
LFLAGS =	-L$(LIBFT_DIR) -lft
IFLAGS =	-I$(LIBFT_DIR) -I$(CHK_DIR) -I$(PS_DIR) -I$(COMMON_DIR) -I$(GNL_DIR) -I$(OP_DIR)
DBFLAGS =	-g3 -fsanitize=address
SRCS_PS =$(addprefix src/pswap/, push_swap.c)
SRCS_PS +=$(addprefix src/pswap/orbit/, print_orbit.c orbit.c orbit_str.c)
SRCS_PS +=$(addprefix src/pswap/utils/, utils.c)
SRCS_PS +=$(addprefix src/pswap/destroy/, destroy_permut.c destroy_paths.c)
SRCS_PS +=$(addprefix src/pswap/init/, compute_trans.c create_permut.c \
        select_remaining.c copy_array.c chose_path.c compute_bij.c \
        update_all_paths.c bubble_sort.c compute_indices.c update_paths.c)
OBJS_PS =$(SRCS_PS:%.c=%.o)
SRCS_CHK =$(addprefix src/checker/, check_ok.o checker.o read_execute.o checker.c \
        args_to_stacks.c args_to_stacks.o check_ok.c read_execute.c)
OBJS_CHK =$(SRCS_CHK:%.c=%.o)
SRCS_COM =$(addprefix src/get_next_line/, get_next_line_utils.c get_next_line.c \
        get_next_line_utils.o get_next_line.o)
SRCS_COM +=$(addprefix src/operations/, rotate_reverse.c swap.o push.c rotate.c \
        parse_operation.c parse_operation.o rotate.o rotate_reverse.o swap.c push.o)
SRCS_COM +=$(addprefix src/common/, free.o errors.c print_stacks.o is_sorted_lst.c \
        lstrev_array.c is_sorted_lst.o errors.o lstrev_array.o repeating_numbers.c \
        repeating_numbers.o print_stacks.c free.c)
OBJS_COM =$(SRCS_COM:%.c=%.o)
OBJS_CHK =	$(OBJS_COM) $(SRCS_CHK:%.c=%.o)
OBJS_PS =	$(OBJS_COM) $(SRCS_PS:%.c=%.o)

all:	libft checker

%.o:	%.c
	gcc -c -o $@ $< $(CFLAGS) $(IFLAGS)

$(OBJS_CHK):	libft

$(OBJS_ps):		libft

checker: $(OBJS_CHK)
	gcc -o $@ $^ $(LFLAGS)

push_swap: $(OBJS_PS)
	gcc -o $@ $^ $(LFLAGS)

libft:
	make -C $(LIBFT_DIR) bonus

_test_chk_%:	_test_chk_%.c $(OBJS_CHK) libft
	gcc $< $(SRCS) -o $@ $(OBJS_CHK) $(IFLAGS) $(LFLAGS)

_test_ps_%:	_test_ps_%.c $(OBJS_PS) libft
	gcc $< $(SRCS) -o $@ $(OBJS_PS) $(IFLAGS) $(LFLAGS)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS_CHK)
	rm -f $(OBJS_PS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	rm -f checker

re:	fclean all

.PHONY:	all libft clean fclean re
