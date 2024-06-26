#! ******************************************************************************#
#                                   NAME                                         #
#! ******************************************************************************#

NAME = 
.DEFAULT_GOAL := all
.PHONY: all clean fclean re help
.SILENT:

#! ******************************************************************************#
#                                   COLORS                                       #
#! ******************************************************************************#

DEFAULT=\033[39m
BLACK=\033[30m
DARK_RED=\033[31m
DARK_GREEN=\033[32m
DARK_YELLOW=\033[33m
DARK_BLUE=\033[34m
DARK_MAGENTA=\033[35m
DARK_CYAN=\033[36m
LIGHT_GRAY=\033[37m
DARK_GRAY=\033[90m
RED=\033[91m
GREEN=\033[92m
ORANGE=\033[93m
BLUE=\033[94m
MAGENTA=\033[95m
CYAN=\033[96m
WHITE=\033[97m
RESET = \033[0m

#! ******************************************************************************#
#                                   PATH                                         #
#! ******************************************************************************#

SRCS_PATH = 
INCS_PATH = 
BUILD_DIR := 
LIBFT_DIR := 

#! ******************************************************************************#
#                                   FILES                                        #
#! ******************************************************************************#

SRCS =	$(addprefix $(SRCS_PATH),\
		file01 \
		file02 \
		file03)
# LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
LIBS := $(LIBFT_DIR)libft.a
OBJS = $(SRCS:%.c=$(BUILD_DIR)%.o)
DEPS = $(OBJS:.o=.d)

#! ******************************************************************************#
#                                    COMMANDS                                    #
#! ******************************************************************************#

MKDIR := mkdir -p
RM := rm -rf
SLEEP = sleep 0.1
CC = cc
SHELL := /bin/bash

#! ******************************************************************************#
#                                 FLAGS E COMP                                   #
#! ******************************************************************************#

CFLAGS = -Wall -Wextra -Werror
DFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LDLIBS = -lft -ldl -lglfw -pthread
LDFLAGS = $(addprefix -L,$(dir $(LIBS)))
CPPFLAGS = $(addprefix -I,$(INCS_PATH)) -MMD -MP
COMP_OBJ = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE = $(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

#! ******************************************************************************#
#                                  FUNCTIONS                                     #
#! ******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMP_OBJ)
	$(SLEEP)
	printf "GENERIC MESSAGE$(YELLOW) %d%%\r$(FCOLOR)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))
endef

define comp_libft
	printf "$(YELLOW)Building libft files\n$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)
endef

define comp_exe
	$(COMP_EXE)
	printf "\n"
	printf "$(GREEN)PROGRAM ->$(RESET)$(PURPLE) READY\n$(RESET)"
endef

define help
	echo "${DARK_RED}Available targets:${RESET}"
	printf "\n"
	echo "${DARK_BLUE}all:${RESET} ${LIGHT_GRAY}Build push swap${RESET}"
	echo "${DARK_BLUE}both:${RESET} ${LIGHT_GRAY}Build push swap and checker${RESET}"
	echo "${DARK_BLUE}bonus:${RESET} ${LIGHT_GRAY}Build checker${RESET}"
	echo "${DARK_BLUE}re:${RESET} ${LIGHT_GRAY}Rebuild the program${RESET}"
	echo "${DARK_BLUE}clean:${RESET} ${LIGHT_GRAY}Remove the object files${RESET}"
	echo "${DARK_BLUE}fclean:${RESET} ${LIGHT_GRAY}Remove the program and the object files${RESET}"
	echo "${DARK_BLUE}debug:${RESET} ${LIGHT_GRAY}Build the program with debugging information${RESET}"
	echo "${DARK_BLUE}case:${RESET} ${LIGHT_GRAY}Show numbers with best and worst case${RESET}"
	echo "${DARK_BLUE}test_nb:${RESET} ${LIGHT_GRAY}Test the program with provided list length${RESET}"
endef

#! ******************************************************************************#
#                                   TARGETS                                      #
#! ******************************************************************************#

all: $(LIBFT) $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJS)
	$(call comp_exe)

$(LIBFT):
	$(call comp_libft)

clean:
	$(RM) $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

help:
	$(call help)

-include $(DEPS)
