# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:48:38 by phkevin           #+#    #+#              #
#    Updated: 2024/12/06 13:38:23 by nfordoxc         ###   Luxembourg.lu      #
#                                                                              #
# **************************************************************************** #

################################################################################
#	Makefile variables
################################################################################

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
CC_OPT			=	-g -o2 -D DEBUG=1
CC_DEF			=	

DEB				=	valgrind
DEB_OPT			=	--tool=memcheck \
					--leak-check=full \
					--show-leak-kinds=definite,indirect,possible \
					--track-fds=yes \
					2> error


ARG0			=	

RM				=	rm -f

################################################################################
#	Librairies																   #
################################################################################

LIBFT_DIR		=	./lib/libft
FT_PRINTF_DIR	=	./lib/ft_printf
GNL_DIR			=	./lib/gnl
MLX_DIR			=	./lib/mlx_linux

LIBFT_NAME		=	-lft
FT_PRINTF_NAME	=	-lftprintf
GNL_NAME		=	-lgnl

LIB_PROG		=
LIB_OPTI		=
LIB_OPTI		=
LIB_NAME		=

MYLIBS			=	-L$(LIBFT_DIR) $(LIBFT_NAME)\
					-L$(GNL_DIR) $(GNL_NAME)\
					-L$(FT_PRINTF_DIR) $(FT_PRINTF_NAME)\
					-L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz \

MYLIBS_BONUS	=

################################################################################
#	Mandatory part															   #
################################################################################

#					./src/controller/key_wasd.c \
#					./src/controller/key_zqsd.c \
#					./src/controller/keyboard.c \
#					./src/controller/mouse.c \
#					./src/debug/aff_map_ctr.c \
#					./src/draw/ft_colors.c \
#					./src/draw/ft_pixel_put.c \
#					./src/draw/ft_put_circle.c \
#					./src/file/file.c \
#					./src/map_generator/map_generator.c \
#					./src/minimap/fr_print_player.c \
#					./src/minimap/ft_print_fond.c \
#					./src/minimap/ft_print_ray.c \
#					./src/minimap/ft_print_spawn.c \
#					./src/minimap/ft_print_wall.c \
#					./src/minimap/map_render.c \
#					./src/texture/ft_load_textures.c \
#					./src/utils/ft_close.c \
#					./src/utils/ft_init.c \
#					./src/utils/ft_parse_col.c \
#					./src/utils/ft_time.c \
#					./src/utils/init.c \
#					./src/utils/render.c \
#					./src/validate/ft_validate.c \
#					./src/validate/ft_validate_map.c \

SRC				=	./src/main.c \
					./src/debug/ft_print_info.c \
					./src/exit/ft_exit.c \
					./src/exit/ft_error.c \
					./src/structure/ft_free_structure.c \
					./src/structure/ft_init_structure.c \
					./src/validate/ft_check_arg.c \
					./src/validate/ft_validate_para.c \
					./src/parser/ft_parse_utils.c \
					./src/parser/ft_parse.c \

OBJ				=	$(SRC:.c=.o)

NAME			=	cube3D

################################################################################
#	Colors																	   #
################################################################################

RESET			=	'\033[0m'

# Regular

BLACK			=	'\033[0;30m'
RED				=	'\033[0;31m'
GREEN			=	'\033[0;92m'
YELLOW			=	'\033[0;93m'
BLUE			=	'\033[0;94m'
PURPLE			=	'\033[0;95m'
CYAN			=	'\033[0;96m'
WHITE			=	'\033[0;97m'

# Bold

BBLACK			=	'\033[1;30m'
BRED			=	'\033[1;31m'
BGREEN			=	'\033[1;92m'
BYELLOW			=	'\033[1;93m'
BBLUE			=	'\033[1;94m'
BPURPLE			=	'\033[1;95m'
BCYAN			=	'\033[1;96m'
BWHITE			=	'\033[1;97m'

################################################################################
#	Progress bar															   #
################################################################################

CURRENT_FILE	= 	0
NB_SRC			=	$(words $(SRC))
NB_BONUS		=	$(words $(SRC_BONUS))
NB_TESTER		=	$(words $(SRC_TESTER))
NB_TESTER_BONUS	=	$(words $(BONUS_TESTER))
SLEEP_TIME		=	0.001

################################################################################
#	Functions
################################################################################

define compile_c_to_o
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@$(CC) $(CFLAGS) $(CC_OPT) -c -o $@ $<
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
	@for i in $$(seq 100 -1 0); do \
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
		for j in $$(seq 0 $$i); do \
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

all:		$(LIBFT_DIR)/$(LIBFT_NAME) \
			$(FT_PRINTF_DIR)/$(FT_PRINTF_NAME) \
			$(GNL_DIR)/$(GNL_NAME) \
			$(MLX_DIR)/libmlx_Linux.a \
			$(NAME)

$(NAME):	NUM_FILES=$(NB_SRC)
$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) $(CC_OPT) $(CC_DEF) $(OBJ) $(MYLIBS) -o $(NAME)

%.o :		%.c
	$(call compile_c_to_o)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@$(MAKE) -sC $(LIBFT_DIR) bonus

$(GNL_DIR)/$(GNL_NAME):
	@$(MAKE) -sC $(GNL_DIR)

$(FT_PRINTF_DIR)/$(FT_PRINTF_NAME):
	@$(MAKE) -sC $(FT_PRINTF_DIR)

$(MLX_DIR)/libmlx_Linux.a:
	@$(MAKE) -sC $(MLX_DIR)

clean:
	$(call delete_progress, ./src/*.o)
	$(call delete_progress, ./src/controller/*.o)
	$(call delete_progress, ./src/debug/*.o)
	$(call delete_progress, ./src/draw/*.o)
	$(call delete_progress, ./src/exit/*.o)
	$(call delete_progress, ./src/file/*.o)
	$(call delete_progress, ./src/map_generator/*.o)
	$(call delete_progress, ./src/minimap/*.o)
	$(call delete_progress, ./src/parser/*.o)
	$(call delete_progress, ./src/structure/*.o)
	$(call delete_progress, ./src/texture/*.o)
	$(call delete_progress, ./src/utils/*.o)
	$(call delete_progress, ./src/validate/*.o)
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(GNL_DIR) clean
	@$(MAKE) -sC $(FT_PRINTF_DIR) clean
	@$(MAKE) -sC $(MLX_DIR) clean

fclean: clean
	$(call delete_file, $(NAME))
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(MAKE) -sC $(GNL_DIR) fclean
	@$(MAKE) -sC $(FT_PRINTF_DIR) fclean

re: fclean all
	@echo "$(GREEN)all RE compiled!$(NO_COLOR)"

.PHONY: all clean fclean re debug

################################################################################
#	Extra
################################################################################

separate_blue:
	@echo "$(BLUE)\n#####################################################################\n$(NO_COLOR)"

separate_red:
	@echo "$(RED)\n#####################################################################\n$(NO_COLOR)"

separate_green:
	@echo "$(GREEN)\n#####################################################################\n$(NO_COLOR)"
	
good:
	@echo ""
	@echo "     /)                     (\\"
	@echo "    '/                       \'"
	@echo "___' (____               ____) '___"
	@echo ".... ((___)             (___)) ...."
	@echo ".....((____)           (____))....."
	@echo ".....((___)             (___))....."
	@echo "--.__((__)               (__))__.--"
	@echo ""

goodanime:
	@clear
	@echo ""
	@echo ""
	@echo ""
	@echo "__________               __________"
	@echo ".... ((___)             (___)) ...."
	@echo ".....((____)           (____))....."
	@echo ".....((___)             (___))....."
	@echo "--.__((__)               (__))__.--"
	@sleep 0.5
	@clear
	@echo ""
	@echo ""
	@echo ""
	@echo "____/)____               ____(\____"
	@echo ".... ((___)             (___)) ...."
	@echo ".....((____)           (____))....."
	@echo ".....((___)             (___))....."
	@echo "--.__((__)               (__))__.--"
	@sleep 0.5
	@clear
	@echo ""
	@echo ""
	@echo "    /)                       (\\"
	@echo "___' (____               ____) '___"
	@echo ".... ((___)             (___)) ...."
	@echo ".....((____)           (____))....."
	@echo ".....((___)             (___))....."
	@echo "--.__((__)               (__))__.--"
	@sleep 0.5
	@clear
	@echo ""
	@echo "     /)                     (\\"
	@echo "    '/                       \'"
	@echo "___' (____               ____) '___"
	@echo ".... ((___)             (___)) ...."
	@echo ".....((____)           (____))....."
	@echo ".....((___)             (___))....."
	@echo "--.__((__)               (__))__.--"
	@echo ""

cafe:
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo ' 
	@echo ""

cafeanime:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |        COFFEE BREAK         |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |        COFFEE BREAK         |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@echo ""
	@sleep 0.5
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |        COFFEE BREAK         |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |        COFFEE BREAK         |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@echo ""

mfrcomplainte:
	@clear
	@echo ""
	@echo "$(GREEN)HOOOO grand makfile divint, je t'implore de compiler mon program.$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(CYAN)Non.$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(GREEN)Mais tu m'avais promis de compiler.$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(CYAN)Non j'ai pas enive.$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(GREEN)Mais pourquoi ?$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(CYAN)Tu me relira jusqu'a temps aue tu trouve ton erreur ou aue sombre dans la folie.$(NO_COLOR)"
	@sleep 0.3
	@echo "$(CYAN)HAAAA HAHAHAHAHA$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(GREEN)Cruel que tu es.$(NO_COLOR)"
	@echo ""

mengcomplainte:
	@clear
	@echo ""
	@echo "$(GREEN)HOOOO great makfile divint, I implore you to compile my program.$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(CYAN)No.$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(GREEN)But you promised me to compile.$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(CYAN)No I do not want to.$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(GREEN)But why ?$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(CYAN)You reread me until you find your error or sink into madness.$(NO_COLOR)"
	@sleep 0.3
	@echo "$(CYAN)HAAAA HAHAHAHAHA$(NO_COLOR)"
	@sleep 0.5
	@echo ""
	@echo "$(GREEN)Cruel that you are.$(NO_COLOR)"
	@echo ""
