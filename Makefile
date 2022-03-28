# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 08:17:15 by ldutriez          #+#    #+#              #
#    Updated: 2022/03/26 00:59:09 by ldutriez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Cub3D
BONUS_NAME	= Cub3D_bonus

CC =		gcc

SRC_DIR = 	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d) \
			$(shell find libs/libft/includes -type d) \
			$(shell find libs/graphical_lib/includes -type d)
			
LIB_DIR =	libs/libft libs/graphical_lib
OBJ_DIR = 	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# List de toute les library a linker au projet (le nom - le lib et - le .a)
LIB = ft LGL
FRAMEWORK = OpenGL Appkit

#SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

SRC =	cub3d_check_manager.c cub3d_check_manager_utils.c cub3d_draw_block.c \
		cub3d_draw_sprite.c cub3d_draw_wall.c cub3d_draw_wall_multi_thread.c \
		cub3d_draw_2d_map.c cub3d_draw_game_over.c cub3d_draw_gun.c \
		cub3d_draw_health.c cub3d_draw_hud.c cub3d_error_text.c \
		cub3d_event_manager.c save.c cub3d_parsing_map.c cub3d_parsing_utils.c \
		cub3d_check_info.c cub3d_get_info_1.c cub3d_get_info_2.c \
		cub3d_get_map.c cub3d_get_map_utils.c cub3d_draw_constructor.c \
		cub3d_draw_destructor.c cub3d_draw_seter.c cub3d_map_behavior.c \
		cub3d_map_constructors.c cub3d_map_destructors.c \
		cub3d_medikit_constructor.c cub3d_medikit_destructor.c \
		cub3d_monster_constructor.c cub3d_monster_destructor.c \
		cub3d_multithread_behavior.c cub3d_multithread_creators.c \
		cub3d_multithread_destructors.c cub3d_parsing_constructors.c \
		cub3d_parsing_destructors.c cub3d_mvt_behavior.c \
		cub3d_player_behavior.c cub3d_player_constructors.c \
		cub3d_player_destructors.c cub3d_ray_behavior.c \
		cub3d_ray_constructors.c cub3d_ray_destructors.c \
		cub3d_sprites_constructors.c cub3d_sprites_destructors.c \
		cub3d_texture_constructors.c cub3d_texture_destructors.c

NORMAL_SRC = game.c

BONUS_SRC = game_bonus.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
NORMAL_OBJ = $(OBJ) $(addprefix $(OBJ_DIR)/, $(NORMAL_SRC:%.c=%.o))
BONUS_OBJ = $(OBJ) $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:%.c=%.o))

FRAMEWORK = OpenGL AppKit

#Compilation flag
CFLAGS = -Wall -Wextra -Werror #-O3 -fsanitize=address -g3

OS = $(shell uname)
ifeq ($(OS), Linux)
LIB_DIR += libs/graphical_lib/libs/minilibx-linux
else
LIB_DIR += libs/graphical_lib/libs/minilibx-mac
endif

ifeq ($(OS), Linux)
IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir)) -I libs/graphical_lib/libs/minilibx-linux
else
IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir)) -I libs/graphical_lib/libs/minilibx-mac
endif
# IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir)) -I libs/graphical_lib/lib/mlx

ifeq ($(OS), Linux)
MLX_DIR = libs/graphical_lib/libs/minilibx-linux
else
MLX_DIR = libs/graphical_lib/libs/minilibx-mac
endif

ifeq ($(OS), Linux)
LFLAGS =	$(foreach dir, $(LIB_DIR), -L $(dir)) \
			$(foreach lib, $(LIB), -l $(lib)) \
			-lmlx -lXext -lX11 -lm
else
LFLAGS =	$(foreach dir, $(LIB_DIR), -L $(dir)) \
			$(foreach lib, $(LIB), -l $(lib)) \
			$(foreach frame, $(FRAMEWORK), -framework  $(frame))
endif

# Colors

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m

all:			$(NAME)

show:
				@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
				@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LIB_DIR:\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
				@echo "$(_BLUE)LIB_INC :\n$(_YELLOW)$(LIB_INC)$(_WHITE)"
				@echo "$(_BLUE)INC_DIR :\n$(_YELLOW)$(INC_DIR)$(_WHITE)"

install:
				$(foreach dir, $(LIB_DIR), echo "\n$(_BLUE)___$(dir) Setting___\n$(_WHITE)" ; )
				$(foreach dir, $(LIB_DIR), make -C $(dir) ; )

re-install:
				$(foreach dir, $(LIB_DIR), make -C $(dir) re ; )

$(OBJ_DIR)/%.o : %.c
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"


$(NAME): 		$(INC_DIR) $(NORMAL_OBJ) Makefile
				@echo "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... \c"
				@$(CC) $(CFLAGS) $(NORMAL_OBJ) libs/graphical_lib/libLGL.a $(MLX_DIR)/libmlx.a libs/libft/libft.a -o $(NAME) $(LFLAGS) -lpthread
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

bonus:			$(BONUS_NAME)

$(BONUS_NAME):	$(INC_DIR) $(BONUS_OBJ) Makefile
				@echo "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... \c"
				@$(CC) $(CFLAGS) $(BONUS_OBJ) libs/graphical_lib/libLGL.a $(MLX_DIR)/libmlx.a libs/libft/libft.a -o $(BONUS_NAME) $(LFLAGS) -lpthread
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

norme:
				norminette $(SRC_DIR)

exec1: $(NAME)
				@echo "Launch Binary File $(_BLUE)$(NAME)$(_WHITE)\n-----"
				@./$(NAME) maps/start0.cub
				@echo "-----\n$(_BLUE)$(NAME) $(_GREEN)successfully end$(_WHITE)\n-----"

exec2: $(NAME)
				@echo "Launch Binary File $(_BLUE)$(NAME)$(_WHITE)\n-----"
				@./$(NAME) maps/start1.cub
				@echo "-----\n$(_BLUE)$(NAME) $(_GREEN)successfully end$(_WHITE)\n-----"

exec3: $(NAME)
				@echo "Launch Binary File $(_BLUE)$(NAME)$(_WHITE)\n-----"
				@./$(NAME) maps/start2.cub
				@echo "-----\n$(_BLUE)$(NAME) $(_GREEN)successfully end$(_WHITE)\n-----"

re:				fclean all

clean:
				@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
				@rm -rf $(OBJ_DIR)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
				@rm -f $(NAME) $(BONUS_NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all clean flcean re show exec norme bonus
