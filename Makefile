### COMPILATION ###
C      = gcc
FLAGS  = -Wall -Wextra -Werror

### EXECUTABLE ###
NAME   = fractol

### INCLUDES ###
LIBFT  = libft
OBJ_PATH  = obj
INC = -I./include -I./libft
SRC_PATH  = src

### SOURCES ###
SOURCES =	main.c				\
			ft_mlx.c			\
			ft_fractol.c		\
			ft_color.c			\
			ft_parse_check.c	\
			deal_events.c		\
			ft_table_int.c		\
			ft_table_flt.c


### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###

all: obj_dir $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Creating library$(NOC)"
	@echo "$(CYAN)  Generating library objects$(NOC)"
	@make -C $(LIBFT)
	@echo "$(CYAN)  Generating fractol program objects$(NOC)"
	@$(CC) $(FLAGS) -L $(LIBFT) -lft -o $@ $(OBJS) -framework OpenGL -framework AppKit -lmlx
	@echo "$(RED)FDF successfully compiled$(NOC)"

obj_dir:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "  $(GREEN)[$(CC) - $(FLAGS)]$(NOC) $(YELLOW)in progress ...: $(WHITE)$(notdir $^) $(RED)->$(NOC) $(notdir $@)"
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<

norme :
	@echo "$(CYAN)Does the fdf source files are normed ?$(NOC)"
	@norminette -R CheckForbiddenSourceHeader $(SRCS)
	@echo "$(CYAN)Does the header files are normed ?$(NOC)"
	@norminette -R CheckForbiddenSourceHeader $(INC)
	@echo "$(CYAN)Does the library files are normed ?$(NOC)"
	@make norme -C $(LIBFT)

clean:
	@echo "$(CYAN)Supressing libraries objects$(NOC)"
	@make clean -C $(LIBFT)
	@echo "$(RED)  Libraries objects destroyed$(NOC)"
	@echo "$(CYAN)Supressing fdf objects$(NOC)"
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)  fractol objects destroyed$(NOC)"

fclean: clean
	@echo "$(CYAN)Supressing fractol binary & static library$(NOC)"
	@make fclean -C $(LIBFT)
	@echo "$(RED)  Static library destroyed$(NOC)"
	@rm -f $(NAME)
	@echo "$(RED)  fractol binary destroyed$(NOC)"

re: fclean
	@$(MAKE) all -j

.PHONY: re, fclean, clean, obj_dir, norme
