# SUBDIRS = $(shell find .. -type d | grep -Ev "(.git|.vscode)")
# IFLAGS = $(addprefix -I, $(SUBDIRS))
LIBFT_DIR = libft
CFLAGS = -Wall -Wextra # -Werror
LFLAGS = -L$(LIBFT_DIR) -lft
IFLAGS = -I$(LIBFT_DIR)
CHK_SRCS = $(addprefix src_checker/, checker.c errors.c free.c)
CHK_OBJS = $(CHK_SRCS:%.c=%.o)

all:	libft checker

%.o:	%.c
	gcc -c -o $@ $< $(CFLAGS) $(IFLAGS)

checker:	$(CHK_OBJS)
	gcc -o $@ $^ $(LFLAGS)

libft:
	make -C $(LIBFT_DIR) bonus

_%:	_%.c libft
	gcc $< $(SRCS) -o $@ $(IFLAGS) $(LFLAGS)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(CHK_OBJS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	rm -f checker

re:	fclean all

.PHONY:	all libft clean fclean re
