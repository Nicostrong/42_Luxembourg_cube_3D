# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:48:38 by phkevin           #+#    #+#              #
#    Updated: 2025/03/18 12:12:33 by nfordoxc         ###   Luxembourg.lu      #
#                                                                              #
# **************************************************************************** #

################################################################################
#	Makefile variables
################################################################################

CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra
CC_OPT				=	-g -o3
CC_DEF				=	

DEB					=	valgrind
DEB_OPT				=	--tool=memcheck \
						--leak-check=full \
						--show-leak-kinds=all \
						--track-fds=yes

DEB_OUT				=	2> error

ARG0				=	"./maps/error_test/C_novalid.cub"

ARG1				=	./maps/error_test/EA_novalid.cub

ARG2				=	./maps/error_test/SO_noexist.cub

ARG3				=	./maps/error_test/F_noexist.cub

ARG4				=	./maps/bmap_zarb5_f.cub

RM					=	rm -f

UNAME				:=	$(shell uname)

################################################################################
#	Librairies																   #
################################################################################

LIBFT_DIR			=	./lib/libft
FT_PRINTF_DIR		=	./lib/ft_printf
GNL_DIR				=	./lib/gnl
MLX_L_DIR			=	./lib/mlx_linux
MLX_M_DIR			=	./lib/mlx_mac

LIBFT_NAME			=	-lft
FT_PRINTF_NAME		=	-lftprintf
GNL_NAME			=	-lgnl
MLX_L_NAME			=	-lmlx
MLX_M_NAME			=	-lmlx
MLX_L_FLAGS			=	-lXext -lX11 -lm -lz
MLX_M_FLAGS			=	-framework OpenGL -framework AppKit

ifeq ($(UNAME), Linux)
	MLX_DIR			=	$(MLX_L_DIR)
	MLX_NAME		=	$(MLX_L_NAME)
	MLX_FLAGS		=	$(MLX_L_FLAGS)
else
	MLX_DIR			=	$(MLX_M_DIR)
	MLX_NAME		=	$(MLX_M_NAME)
	MLX_FLAGS		=	$(MLX_M_FLAGS)
endif

LIB_PROG			=
LIB_OPTI			=
LIB_NAME			=

MYLIBS				=	-L$(LIBFT_DIR) $(LIBFT_NAME)\
						-L$(GNL_DIR) $(GNL_NAME)\
						-L$(MLX_DIR)  $(MLX_NAME)\
						$(MLX_FLAGS)

MYLIBS_BONUS		=	$(MYLIBS)

################################################################################
#	Specifics files															   #
################################################################################

ifeq ($(UNAME), Linux)
	SRC_OS			=	./src/controller/ft_press_key.c
	SRC_OS_BONUS	=	./bonus/controller/ft_press_key_bonus.c
else
	SRC_OS			=	./src/controller/ft_press_key_mac.c
	SRC_OS_BONUS	=	./bonus/controller/ft_press_key_mac_bonus.c
endif

################################################################################
#	Mandatory part															   #
################################################################################

SRC_COMMON			=	./src/main.c \
						./src/controller/ft_check_wall.c \
						./src/controller/ft_move.c \
						./src/controller/ft_rotate.c \
						./src/debug/ft_print_color.c \
						./src/debug/ft_print_img.c \
						./src/debug/ft_print_info.c \
						./src/debug/ft_print_map.c \
						./src/debug/ft_print_user.c \
						./src/draw/ft_get_color.c \
						./src/draw/ft_working_pixel.c \
						./src/exit/ft_error.c \
						./src/exit/ft_exit.c \
						./src/parser/ft_check_arg.c \
						./src/parser/ft_parse.c \
						./src/parser/ft_parse_utils_1.c \
						./src/parser/ft_parse_utils_2.c \
						./src/parser/ft_parse_utils_3.c \
						./src/raycast/ft_raycasting.c \
						./src/raycast/ft_raycasting_utils_1.c \
						./src/raycast/ft_raycasting_utils_2.c \
						./src/raycast/ft_raycasting_utils_3.c \
						./src/structure/ft_free_structure.c \
						./src/structure/ft_init_structure.c

SRC					=	$(SRC_COMMON) $(SRC_OS)

OBJ					=	$(SRC:.c=.o)

NAME				=	cub3D

################################################################################
#	Bonus part																   #
################################################################################

SRC_BONUS_COM		=	./bonus/main_bonus.c \
						./bonus/controller/ft_check_wall_bonus.c \
						./bonus/controller/ft_check_door_bonus.c \
						./bonus/controller/ft_door_bonus.c \
						./bonus/controller/ft_mouse_move_bonus.c \
						./bonus/controller/ft_move_bonus.c \
						./bonus/controller/ft_rotate_bonus.c \
						./bonus/debug/ft_print_anim_bonus.c \
						./bonus/debug/ft_print_color_bonus.c \
						./bonus/debug/ft_print_img_bonus.c \
						./bonus/debug/ft_print_info_bonus.c \
						./bonus/debug/ft_print_map_bonus.c \
						./bonus/debug/ft_print_minimap_bonus.c \
						./bonus/debug/ft_print_ray_bonus.c \
						./bonus/debug/ft_print_sky_floor_bonus.c \
						./bonus/debug/ft_print_user_bonus.c \
						./bonus/draw/ft_get_color_bonus.c \
						./bonus/draw/ft_put_door_bonus.c \
						./bonus/draw/ft_put_circle_bonus.c \
						./bonus/draw/ft_put_item_bonus.c \
						./bonus/draw/ft_put_player_bonus.c \
						./bonus/draw/ft_working_pixel_bonus.c \
						./bonus/exit/ft_error_bonus.c \
						./bonus/exit/ft_exit_bonus.c \
						./bonus/minimap/ft_draw_circle.c \
						./bonus/minimap/ft_minimap_utils_bonus.c \
						./bonus/minimap/ft_minimap_bonus.c \
						./bonus/parser/ft_check_arg_bonus.c \
						./bonus/parser/ft_parse_utils_1_bonus.c \
						./bonus/parser/ft_parse_utils_2_bonus.c \
						./bonus/parser/ft_parse_utils_3_bonus.c \
						./bonus/parser/ft_parse_bonus.c \
						./bonus/raycast/ft_raycasting_bonus.c \
						./bonus/raycast/ft_raycasting_utils_1_bonus.c \
						./bonus/raycast/ft_raycasting_utils_2_bonus.c \
						./bonus/raycast/ft_raycasting_utils_3_bonus.c \
						./bonus/raycast/ft_raycasting_utils_4_bonus.c \
						./bonus/structure/ft_free_structure_bonus.c \
						./bonus/structure/ft_init_anim_bonus.c \
						./bonus/structure/ft_init_img_bonus.c \
						./bonus/structure/ft_init_mlx_bonus.c \
						./bonus/structure/ft_init_structure_bonus.c \

SRC_BONUS			=	$(SRC_BONUS_COM) $(SRC_OS_BONUS)

OBJ_BONUS			=	$(SRC_BONUS:.c=.o)

NAME_BONUS			=	cub3D++

################################################################################
#	Colors																	   #
################################################################################

RESET				=	'\033[0m'

# Regular

BLACK				=	'\033[0;30m'
RED					=	'\033[0;31m'
GREEN				=	'\033[0;32m'
YELLOW				=	'\033[0;93m'
BLUE				=	'\033[0;34m'
PURPLE				=	'\033[0;35m'
CYAN				=	'\033[0;36m'
WHITE				=	'\033[0;97m'

# Bold

BBLACK				=	'\033[1;30m'
BRED				=	'\033[1;31m'
BGREEN				=	'\033[1;92m'
BYELLOW				=	'\033[1;93m'
BBLUE				=	'\033[1;94m'
BPURPLE				=	'\033[1;95m'
BCYAN				=	'\033[1;96m'
BWHITE				=	'\033[1;97m'

# Blink

CBLACK				=	'\033[5;30m'
CRED				=	'\033[5;31m'
CGREEN				=	'\033[5;32m'
CYELLOW				=	'\033[5;93m'
CBLUE				=	'\033[5;34m'
CPURPLE				=	'\033[5;35m'
CCYAN				=	'\033[5;36m'
CWHITE				=	'\033[5;97m'

################################################################################
#	Progress bar															   #
################################################################################

CURRENT_FILE		= 	0
NB_SRC				=	$(words $(SRC))
NB_BONUS			=	$(words $(SRC_BONUS))
NB_TESTER			=	$(words $(SRC_TESTER))
NB_TESTER_BONUS		=	$(words $(BONUS_TESTER))
SLEEP_TIME			=	0.001

################################################################################
#	Functions
################################################################################

define compile_c_to_o
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@$(CC) $(CFLAGS) $(CC_OPT) $(CC_DEF) -c -o $@ $<
	@printf $(BLUE)"\r\033[K\033[0KCompiling files => $< ["
	@for i in $$(seq 0 $$(($(CURRENT_FILE)*100/$(NUM_FILES)))); do \
		printf $(YELLOW)"="; \
	done
	@printf $(BBLUE)"] $(CURRENT_FILE)/$(NUM_FILES)$(RESET)"
	@if [ $(CURRENT_FILE) -eq $(NUM_FILES) ]; then \
		echo ; \
	fi
	@$(eval CURRENT_FILE=$(if \
		$(filter $(CURRENT_FILE), $(NUM_FILES)), 0, $(CURRENT_FILE)))
endef

define optimise_lib
	@printf "$(BYELLOW)Optimisation of $(LIB_NAME)$(YELLOW)\n"
	@$(LIB_OPTI) $(LIB_NAME) > /dev/null 2>&1
	@for i in $$(seq 1 50); do \
		printf "\r\033[K\033[0K["; \
		for j in $$(seq 1 $$i); do \
			printf "=="; \
		done; \
		printf " %d%% ]" $$((i * 2)); \
		sleep $(SLEEP_TIME); \
	done; \
	echo $(RESET)
endef

define delete_progress
	@$(RM) $(1) > /dev/null 2>&1
	@for i in $$(seq 100 -1 1); do \
		printf "\r\033[K\033[0K"; \
		if [ $$((i % 4)) -eq 0 ]; then \
			printf "$(BRED)DELETE - ["; \
		elif [ $$((i % 4)) -eq 1 ]; then \
			printf "$(BRED)DELETE / ["; \
		elif [ $$((i % 4)) -eq 2 ]; then \
			printf "$(BRED)DELETE | ["; \
		else \
			printf "$(BRED)DELETE \\ ["; \
		fi; \
		for j in $$(seq 0 $$(($$i - 1))); do \
			printf '='; \
		done; \
		printf " %d/100 ]$(RESET)" $$i; \
		sleep $(SLEEP_TIME); \
	done
	@printf "\r\033[K\033[0K$(GREEN)All files $(1) of $(NAME) deleted$(RESET)\n"
endef

define delete_file
	@$(RM) $(1) > /dev/null 2>&1
	@printf "\r\033[K\033[0K$(GREEN)$(1) deleted$(RESET)\n"
endef

################################################################################
#	Rules
################################################################################

all:			$(MLX_DIR)/$(MLX_NAME)\
				$(LIBFT_DIR)/$(LIBFT_NAME) \
				$(GNL_DIR)/$(GNL_NAME) \
				$(NAME)

bonus:			$(MLX_DIR)/$(MLX_NAME)\
				$(LIBFT_DIR)/$(LIBFT_NAME) \
				$(GNL_DIR)/$(GNL_NAME) \
				$(NAME_BONUS)

$(NAME):		NUM_FILES=$(NB_SRC)
$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) $(CC_OPT) $(CC_DEF) $(OBJ) $(MYLIBS) -o $(NAME)
	@echo "$(CGREEN)all files of the programm $(NAME) compiled with success!$(RESET)"

$(NAME_BONUS):	NUM_FILES=$(NB_BONUS)
$(NAME_BONUS):	$(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(CC_OPT) $(CC_DEF) $(OBJ_BONUS) $(MYLIBS_BONUS) -o $(NAME_BONUS)
	@echo "$(CGREEN)all files of the programm $(NAME_BONUS) compiled with success!$(RESET)"

%.o :			%.c
	$(call compile_c_to_o)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@$(MAKE) -sC $(LIBFT_DIR) bonus

$(GNL_DIR)/$(GNL_NAME):
	@$(MAKE) -sC $(GNL_DIR)

$(MLX_DIR)/$(MLX_NAME):
	@$(MAKE) -sC $(MLX_DIR)

deb:			all
	@echo "$(BBLUE)==========	RUN DEBUG MODE	==========$(RESET)"
ifeq ($(arg),ARG0)
	$(DEB) $(DEB_OPT) ./$(NAME) $(ARG0) $(DEB_OUT)
else ifeq ($(arg),ARG1)
	$(DEB) $(DEB_OPT) ./$(NAME) $(ARG1) $(DEB_OUT)
else ifeq ($(arg),ARG2)
	$(DEB) $(DEB_OPT) ./$(NAME) $(ARG2) $(DEB_OUT)
else ifeq ($(arg),ARG3)
	$(DEB) $(DEB_OPT) ./$(NAME) $(ARG3) $(DEB_OUT)
else ifeq ($(arg),ARG4)
	$(DEB) $(DEB_OPT) ./$(NAME) $(ARG4) $(DEB_OUT)
else ifneq ($(arg),)
	$(DEB) $(DEB_OPT) ./$(NAME) $(arg) $(DEB_OUT)
else
	@echo "$(RESET)Usage: make deb arg=ARG0|ARG1|ARG2|ARG3|ARG4|personal_arg"
endif

clean:
	$(call delete_progress, ./src/*.o)
	$(call delete_progress, ./src/controller/*.o)
	$(call delete_progress, ./src/debug/*.o)
	$(call delete_progress, ./src/draw/*.o)
	$(call delete_progress, ./src/exit/*.o)
	$(call delete_progress, ./src/minimap/*.o)
	$(call delete_progress, ./src/parser/*.o)
	$(call delete_progress, ./src/raycast/*.o)
	$(call delete_progress, ./src/structure/*.o)
	$(call delete_progress, ./bonus/*.o)
	$(call delete_progress, ./bonus/controller/*.o)
	$(call delete_progress, ./bonus/debug/*.o)
	$(call delete_progress, ./bonus/draw/*.o)
	$(call delete_progress, ./bonus/exit/*.o)
	$(call delete_progress, ./bonus/minimap/*.o)
	$(call delete_progress, ./bonus/parser/*.o)
	$(call delete_progress, ./bonus/raycast/*.o)
	$(call delete_progress, ./bonus/structure/*.o)
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(GNL_DIR) clean
	@$(MAKE) -sC $(MLX_DIR) clean

fclean: 		clean
	$(call delete_file, $(NAME))
	$(call delete_file, $(NAME_BONUS))
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(MAKE) -sC $(GNL_DIR) fclean

re: 			fclean all

.PHONY: all clean fclean re bonus deb