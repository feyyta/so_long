# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 19:37:38 by parallels         #+#    #+#              #
#    Updated: 2025/03/12 23:20:22 by mcastrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME				= so_long

# Directories
PRINTF 				= ft_printf/libftprintf.a
MLX_PATH			= mlx/
MLX					= $(MLX_PATH)/libmlx.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -g3 #-fsanitize=address
RM					= rm -f

# Source Files
SRCS	=		$(SRC_DIR)parsing.c \
				$(SRC_DIR)keyboard.c \
				$(SRC_DIR)path.c\
				$(SRC_DIR)initgame.c \
				$(SRC_DIR)errorfree.c \
				$(SRC_DIR)so_long.c \
				$(SRC_DIR)valid.c 


# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ					= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Include directories
INCLUDES			= -I$(INC) -I$(MLX_PATH)

# Libraries
LIBS = -L./lib -lft -L./mlx -lmlx -lX11 -lXext -lm

# Colors
GREEN   			= "\\033[32m"
YELLOW  			= "\\033[33m"
NC      			= "\\033[0m"

# Progress Bar
TOTAL_FILES 		:= $(words $(SRCS))
CURRENT_FILE 		:= 0

define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "\r$(YELLOW)Compiling so_long... [%-$(TOTAL_FILES)s] %d/%d $(NC)" \
	$$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES)  ]; then echo ""; fi
endef

# SO_LONG ASCII Art
SO_LONG_LOGO = "\033[5;36m\
███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗  \n\
██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝  \n\
███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗ \n\
╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║ \n\
███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝ \n\
╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝  \n\
\033[0m"


# Build rules
start:				
					@make all

$(PRINTF):
					@make -C ./ft_printf -s

$(MLX):
					@make -C $(MLX_PATH) -s

all: 				$(NAME)

$(NAME): 			$(OBJ) $(PRINTF) $(MLX)
					@printf "\n"
					@printf $(SO_LONG_LOGO)
					@echo "$(GREEN)Linking objects to create executable...$(NC)"
					@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) -o $(NAME)
					@echo "$(GREEN)Executable $(NAME) created!$(NC)"

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
					$(call progress_bar)

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./ft_printf --no-print-directory
					@make clean -C $(MLX_PATH) --no-print-directory

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(PRINTF)
					@$(RM) $(MLX)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re