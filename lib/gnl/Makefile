# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 10:06:31 by nfordoxc          #+#    #+#              #
#    Updated: 2025/03/07 17:58:12 by nfordoxc         ###   Luxembourg.lu      #
#                                                                              #
# **************************************************************************** #

################################################################################
#	Makefile variables                                                         #
################################################################################

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g
CC_OPT			=	-D BUFFER_SIZE=666

DEB				=	valgrind
DEB_OPT			=	--tool=memcheck --leak-check=full --show-leak-kinds=all

ARG				=	./files/big_line

RM				=	rm -f

################################################################################
#	Librairies                                                                 #
################################################################################

LIB_DIR			=	
LIB_PROG		=	ar -rcs
LIB_OPTI		=	ranlib
LIB_NAME		=	libgnl.a

################################################################################
#	Mandatory part                                                             #
################################################################################

SRC				=	get_next_line.c \
					get_next_line_utils.c

OBJ				=	$(SRC:.c=.o)

NAME			=	gnl

################################################################################
#	Bonus part                                                                 #
################################################################################

BONUS			=	

OBJ_BONUS		=	$(BONUS:.c=.o)

NAME_BONUS		=	

################################################################################
#	Tester part
################################################################################

SRC_TESTER		=	
BONUS_TESTER	=	

OBJ_TESTER		=	$(SRC_TESTER:.c=.o)
OBJ_BONUS_TESTER=	$(BONUS_TESTER:.c=.o)

TESTER			=	
TESTER_BONUS	=	

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
NB_BONUS		=	$(words $(BONUS))
NB_TESTER		=	$(words $(SRC_TESTER))
NB_TESTER_BONUS	=	$(words $(BONUS_TESTER))
SLEEP_TIME		=	0.001

################################################################################
#	Functions
################################################################################

define compile_c_to_o
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@$(CC) $(CFLAGS) -c -o $@ $<
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
#	Rules                                                                      #
################################################################################

.PHONY : all $(NAME) clean fclean re

all: 			$(NAME)

$(NAME):		NUM_FILES=$(NB_SRC)
$(NAME):		$(OBJ)
	@$(LIB_PROG) $(LIB_NAME) $(OBJ) > /dev/null 2>&1

%.o : %.c
	$(call compile_c_to_o)

optimize:		$(NAME)
	$(call optimise_lib)

clean:
	$(call delete_progress, *.o)

fclean: 		clean
	$(call delete_file, $(LIB_NAME))

re : 			fclean all
