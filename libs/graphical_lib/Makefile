# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 09:02:30 by ldutriez          #+#    #+#              #
#    Updated: 2022/03/26 00:51:31 by ldutriez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libLGL.a

CC =		gcc

MLX_DIR = 	$(shell find lib/mlx -type d)
SRC_DIR = 	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d)
LIB_DIR =
OBJ_DIR = 	obj

OS = $(shell uname)
ifeq ($(OS), Linux)
LIB_DIR += libs/minilibx-linux
else
LIB_DIR += libs/minilibx-mac
endif

# List de toute les library a linker au projet (le nom - le lib et - le .a)
LIB =

FRAMEWORK = OpenGL AppKit

ifeq ($(OS), Linux)
LFLAGS =  $(foreach dir, $(LIB_DIR), -L $(dir) ) -lmlx -lXext -lX11 -lm
else
LFLAGS = $(foreach dir, $(LIB_DIR), -L $(dir) ) $(foreach lib, $(LIB), -l $(lib) ) $(foreach framework, $(FRAMEWORK), -framework $(framework) )
endif

IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir)) $(foreach dir, $(LIB_DIR), -I$(dir))

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

#SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file)))) mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_mouse.m

SRC = error_text.c application_behavior.c application_creators.c \
	application_destructors.c application_event_catcher.c basic_convert.c \
	basic_put.c basic_str1.c basic_str2.c ftoa.c color_behavior.c \
	color_creators.c color_destructors.c draw_button.c draw_line.c \
	draw_panel.c draw_primitive.c lgl_images_constructors.c \
	lgl_images_destructors.c vector2_list_behavior.c vector2_list_creators.c \
	vector2_list_destructors.c angle_functions.c calc_line.c f_power.c \
	vector2_behavior.c vector2_constructors.c vector2_destructors.c \
	vector2_normalize.c vector3_behavior.c vector3_constructors.c \
	vector3_destructors.c vector4_behavior.c vector4_constructors.c \
	vector4_destructors.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

#Compilation flag
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

# IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir))

# LFLAGS = $(foreach dir, $(LIB_DIR), -L $(dir) ) $(foreach lib, $(LIB), -l $(lib) ) $(foreach framework, $(FRAMEWORK), -framework $(framework) )

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

$(OBJ_DIR)/%.o : %.c
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

%.a:
				@echo "\n$(_BLUE)___$(notdir $@) Setting___\n$(_WHITE)"
				@make --no-print-directory -C $(dir $@)

$(NAME): 		$(OBJ) $(LIB_DIR)/libmlx.a Makefile
				@echo "-----\nCreating library $(_YELLOW)$@$(_WHITE) ... \c"
				ar -rc $(NAME) $(OBJ) $(LIB_DIR)/libmlx.a
				ranlib $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

debug:			$(OBJ) $(NAME) main.c
				@echo "Creating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
				$(CC) $(CFLAGS) $(IFLAGS) main.c libs/minilibx-linux/libmlx.a -o debug -L . -lLGL $(LFLAGS)
				@echo "$(_GREEN)DONE$(_WHITE)\n"
				@echo "Execution !\n-----"
				@./debug

norme:
				norminette $(SRC_DIR)

re:				fclean all

clean:
				@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
				@$(foreach file, $(OBJ), rm -rf $(file))
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
				@rm -f $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all clean flcean re show norme
