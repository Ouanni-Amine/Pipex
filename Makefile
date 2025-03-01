dir_src = src/
src_tools = src/tools/

dir_bonus = bonus/
bonus_tools = bonus/tools_bonus/
dir_GNL = GNL/

SRC = $(dir_src)first_child.c  $(dir_src)first_child_helper.c  $(dir_src)pipex.c  $(dir_src)second_child.c  $(dir_src)second_child_helper.c

TOOLS_SRC = $(src_tools)cleanup_exit.c  $(src_tools)ft_memcpy.c  $(src_tools)ft_putstr_fd.c  $(src_tools)ft_splitV2.c  $(src_tools)ft_strdup.c  $(src_tools)ft_strjoin.c \
			$(src_tools)ft_strlen.c  $(src_tools)ft_strncmp.c  $(src_tools)ft_strtrim.c  $(src_tools)global_func.c  $(src_tools)ft_strchr.c


BONUS = $(dir_bonus)excute_cmd_bonus.c  $(dir_bonus)pipe_process_bonus.c  $(dir_bonus)pipex_bonus.c

TOOLS_BONUS = $(bonus_tools)check_cleanup_bonus.c  $(bonus_tools)ft_pustr_fd_bonus.c  $(bonus_tools)ft_strcmp_bonus.c  $(bonus_tools)ft_strtrim_bonus.c  $(bonus_tools)ft_strchr_bonus.c \
			$(bonus_tools)check_cleanup2_bonus.c  $(bonus_tools)ft_memcpy_bonus.c  $(bonus_tools)ft_splitV2_bonus.c  $(bonus_tools)ft_strncmp_bonus.c  $(bonus_tools)input_output_handle_bonus.c

GNL = $(dir_GNL)get_next_line.c  $(dir_GNL)get_next_line_utils.c


OBJS = $(SRC:.c=.o)
OBJT = $(TOOLS_SRC:.c=.o)

OBJB = $(BONUS:.c=.o)
OBJBT = $(TOOLS_BONUS:.c=.o)
OBJBG = $(GNL:.c=.o)

NAME = pipex
NAME_BONUS = pipex_bonus
CFLAGS = -Wall -Wextra -Werror
CC = CC
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(OBJT)
		$(CC) $(CFLAGS) $^ -o $@

$(dir_src)%.o : $(dir_src)%.c $(dir_src)pipex.h
		$(CC) $(CFLAGS) -c $< -o $@

$(src_tools)%.o : $(src_tools)%.c $(dir_src)pipex.h
		$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJB) $(OBJBG) $(OBJBT)
		$(CC) $(CFLAGS) $^ -o $@

$(dir_bonus)%.o : $(dir_bonus)%.c $(dir_bonus)pipex_bonus.h $(dir_GNL)get_next_line.h
		$(CC) $(CFLAGS) -c $< -o $@

$(dir_GNL)%.o : $(dir_GNL)%.c $(dir_GNL)get_next_line.h
		$(CC) $(CFLAGS) -c $< -o $@

$(bonus_tools)%.o : $(bonus_tools)%.c $(dir_bonus)pipex_bonus.h $(dir_GNL)get_next_line.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJT) $(OBJB) $(OBJBG) $(OBJBT)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean
