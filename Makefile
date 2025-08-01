# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 14:44:17 by diade-so          #+#    #+#              #
#    Updated: 2025/08/01 00:53:21 by diade-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                               Compiler & Flags                               #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra -g3 -ffast-math
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES = -I./libft/includes -I./includes -I$(MLX_DIR)

# **************************************************************************** #
#                                 Target Name                                  #
# **************************************************************************** #

NAME = fractol

# **************************************************************************** #
#                                 Directories                                  #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
MLX_DIR = ./minilibx-linux
BONUS_DIR = bonus

# **************************************************************************** #
#                                Source Files                                  #
# **************************************************************************** #

SRC = $(addprefix $(SRC_DIR)/, main.c init.c parse.c print.c window.c draw.c \
      	fractal.c mouse.c)

SHARED = init.c parse.c print.c window.c draw.c fractal.c

BONUS_SRC = $(addprefix $(BONUS_DIR)/, main_bonus.c mouse_bonus.c)

# **************************************************************************** #
#                                Object Files                                  #
# **************************************************************************** #

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

SHARED_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SHARED:.c=.o)))

BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRC:.c=.o)))

ALL_BONUS_OBJ = $(BONUS_OBJ) $(SHARED_OBJ)

# **************************************************************************** #
#                                    Libft                                     #
# **************************************************************************** #

LIBFT = $(LIBFT_DIR)/libft.a

# **************************************************************************** #
#                                   Rules                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

bonus: $(ALL_BONUS_OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDES) $(ALL_BONUS_OBJ) $(LIBFT) $(MLX_FLAGS) \
		-o fractol_bonus

clean:
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) fractol_bonus

re: fclean all

.PHONY: all clean fclean re bonus
