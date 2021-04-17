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
# SRCS_PS =$(addprefix src/pswap/, merge.c sort.c)
# SRCS_PS +=$(addprefix src/pswap/utils/, utils.c)
# SRCS_PS +=$(addprefix src/pswap/operations/, rotate_reverse.c push.c rotate.c \
#         swap.c)
# OBJS_PS =$(SRCS_PS:%.c=%.o)
# SRCS_CHK =$(addprefix src/checker/, checker.c check_ok.c read_execute.c)
# OBJS_CHK =$(SRCS_CHK:%.c=%.o)
# SRCS_COM =$(addprefix src/get_next_line/, get_next_line_utils.c get_next_line.c)
# SRCS_COM +=$(addprefix src/operations/, rotate_reverse.c push.c rotate.c \
#         parse_operation.c swap.c)
# SRCS_COM +=$(addprefix src/common/, errors.c handle_args.c is_sorted_lst.c \
#         lstrev_array.c args_to_stacks.c repeating_numbers.c print_stacks.c free.c)
# OBJS_COM =$(SRCS_COM:%.c=%.o)
# OBJS_CHK =	$(OBJS_COM) $(SRCS_CHK:%.c=%.o)
# OBJS_PS =	$(OBJS_COM) $(SRCS_PS:%.c=%.o)
SRCS_COM =$(addprefix src/get_next_line/, get_next_line_utils.c get_next_line.c)
SRCS_COM +=$(addprefix src/pswap_old/, merge.c sort.c)
SRCS_COM +=$(addprefix src/pswap_old/utils/, utils.c)
SRCS_COM +=$(addprefix src/pswap_old/operations/, rotate_reverse.c push.c rotate.c \
        swap.c)
SRCS_COM +=$(addprefix src/operations/, rotate_reverse.c push.c rotate.c \
        parse_operation.c swap.c)
SRCS_COM +=$(addprefix src/common/, errors.c handle_args.c is_sorted_lst.c \
        lstrev_array.c args_to_stacks.c repeating_numbers.c print_stacks.c free.c)
SRCS_CHK =$(addprefix src/checker/, checker.c check_ok.c read_execute.c)
SRCS_PS =$(addprefix src/pswap/, recursion.c groupstacks.c merge_group.c)
SRCS_PS +=$(addprefix src/pswap/utils/, utils.c)
OBJS_COM = $(SRCS_COM:src/%.c=obj/%.o)
OBJS_CHK = $(OBJS_COM) $(SRCS_CHK:src/%.c=obj/%.o)
OBJS_PS = $(OBJS_COM) $(SRCS_PS:src/%.c=obj/%.o)
DIRS = src/get_next_line src/pswap src/pswap/utils src/checker src/operations src/common
OBJ_DIRS = $(DIRS:src/%=obj/%)


all:	libft checker

checker: $(OBJS_CHK)
	gcc -o $@ $^ $(LFLAGS)

push_swap: $(OBJS_PS)
	gcc -o $@ $^ $(LFLAGS)

libft:
	make -C $(LIBFT_DIR) bonus

_test_chk_%:	test/_test_chk_%.c $(OBJS_CHK) libft
	gcc $< $(SRCS) -o test/$@ $(OBJS_CHK) $(IFLAGS) $(LFLAGS)

_test_ps_%:	test/_test_ps_%.c $(OBJS_PS) libft
	gcc $< $(SRCS) -o test/$@ $(OBJS_PS) $(IFLAGS) $(LFLAGS) $(DBFLAGS)

obj/%.o:	obj/%.c
	gcc -c -o $@ $< $(CFLAGS) $(IFLAGS)

$(OBJS_CHK):	$(OBJ_DIRS) libft
$(OBJS_PS):		$(OBJ_DIRS) libft
$(OBJS_COM):	$(OBJ_DIRS) libft

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS_CHK)
	rm -f $(OBJS_PS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	rm -f checker

re:	fclean all

.PHONY:	all libft clean fclean re
