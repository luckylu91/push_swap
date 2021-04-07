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
# SRCS =  $(addprefix src/checker/, checker.c operations/_test_ops.c \
# 		operations/parse_operation.coperations/push.c operations/rotate.c \
# 		operations/rotate_reverse.coperations/swap.c)
# SRCS += $(addprefix src/common/, args_to_list.c errors.c free.c \
# 		repeating_numbers.c)
# SRCS += $(addprefix src/get_next_line/, get_next_line.c get_next_line_bonus.c \
# 		get_next_line_utils.cget_next_line_utils_bonus.c)
# SRCS += $(addprefix src/pswap/, mapping.c orbit.c orbit_str.c)
SRCS_PS =$(addprefix src/pswap/, compute_trans.c create_permut.c destroy_permut.c \
        copy_array.c compute_bij.c bubble_sort.c destroy_paths.c print_orbit.c \
        orbit.c compute_indices.c orbit_str.c update_paths.c)
OBJS_PS =$(SRCS_PS:%.c=%.o)
SRCS_CHK =$(addprefix src/checker/, checker.c check_ok.c read_execute.c)
OBJS_CHK =$(SRCS_CHK:%.c=%.o)
SRCS_COM =$(addprefix src/get_next_line/, get_next_line_utils.c get_next_line.c)
SRCS_COM +=$(addprefix src/operations/, rotate_reverse.c push.c rotate.c \
        parse_operation.c swap.c)
SRCS_COM +=$(addprefix src/common/, errors.c is_sorted_lst.c lstrev_array.c \
        args_to_list.c repeating_numbers.c print_stacks.c free.c)
OBJS_COM =$(SRCS_COM:%.c=%.o)
OBJS_CHK =	$(OBJS_COM) $(SRCS_CHK:%.c=%.o)
OBJS_PS =	$(OBJS_COM) $(SRCS_PS:%.c=%.o)

all:	libft checker

%.o:	%.c
	gcc -c -o $@ $< $(CFLAGS) $(IFLAGS)

checker:	$(OBJS_CHK)
	gcc -o $@ $^ $(LFLAGS)

push_swap:	$(OBJS_PS)
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
