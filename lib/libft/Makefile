# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:48:38 by phkevin           #+#    #+#              #
#    Updated: 2024/11/11 09:35:21 by phkevin          ###   Luxembour.lu       #
#                                                                              #
# **************************************************************************** #

################################################################################
#	Makefile variables
################################################################################

NAMECC	=	libft
CC		=	clang
FLAGWS	=	-g -Wall -Wextra -Werror
AR		=	ar rcs
RM		=	/bin/rm -f

################################################################################
#	Mandatory part
################################################################################

NAME	=	libft.a
OBJS_DIR	=	./
OBJS		=	$(addprefix $(OBJS_DIR), $(FILES:.c=.o))

FILES	=	ft_atoi.c \
			ft_atoill.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_cpy_strarray.c \
			ft_free_array.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_ispaire.c \
			ft_isprint.c \
			ft_isrc.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_strequal.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \

################################################################################
#	Colors
################################################################################

NO_COLOR = 	\033[0;39m
GREEN = 	\033[0;92m
YELLOW = 	\033[0;93m
BLUE = 		\033[0;94m
CYAN = 		\033[0;96m
RED = 		\033[0;31m
PURPLE = 	\033[0;35m

################################################################################
#	Rules
################################################################################

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGWS) -c -o $@ $<
	@echo "$(YELLOW)Compiling: $< $(NO_COLOR)"

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAMECC) compiled!$(NO_COLOR)"
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAMECC) optimised!$(NO_COLOR)"
	@make --silent good
	@make --silent separate

clean:
	@$(RM) $(OBJS)
	@echo "$(BLUE)$(NAMECC) object files cleaned!$(NO_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAMECC) executable files cleaned!$(NO_COLOR)"
	@echo ""

re: fclean all
	@echo "$(GREEN)$(NAMECC) RE compiled!$(NO_COLOR)"

.PHONY: all clean fclean re

################################################################################
#	Extra
################################################################################

separate:
	@echo ""
	@echo "$(BLUE)#####################################################################$(NO_COLOR)"
	@echo ""

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

