#! ******************************************************************************#
#                                   NAME                                         #
#! ******************************************************************************#

NAME = philo_bonus
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

SRCS_PATH = ./src/
INCS_PATH = ./includes/ ./garbage-collector/include/
BUILD_DIR := ./build/
GARB_DIR := garbage-collector/

#! ******************************************************************************#
#                                   FILES                                        #
#! ******************************************************************************#

SRCS =	$(addprefix $(SRCS_PATH),\
		init.c \
		monitoring.c \
		philo_bonus.c \
		philos_life.c \
		routines.c \
		semaphores.c \
		u_atol.c \
		u_error.c \
		u_time.c \
		utils.c)
GARB = $(addprefix $(GARB_DIR), garbage_collector.a)
LIBS = $(GARB_DIR)garbage_collector.a
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

CFLAGS = -Wall -Wextra -Werror -g3
DFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LDFLAGS = $(GARB_DIR)garbage_collector.a
LDLIBS = -ldl -lglfw -pthread
CPPFLAGS = $(addprefix -I,$(INCS_PATH)) -MMD -MP
COMP_OBJ = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE = $(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

#! ******************************************************************************#
#                                  FUNCTIONS                                     #
#! ******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_garb
	printf "$(YELLOW)Building garb files\n$(RESET)"
	$(MAKE) -C $(GARB_DIR)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMP_OBJ)
	$(SLEEP)
	printf "Compiling philo files:$(DARK_YELLOW) %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))
endef

define comp_exe
	$(COMP_EXE)
	printf "\n"
	printf "$(GREEN)PHILO ->$(RESET)$(DARK_CYAN) IS READY\n$(RESET)"
endef

define help
	printf "$(DARK_RED)Available targets:${RESET}\n"
	printf "${DARK_BLUE}all:${RESET}	${LIGHT_GRAY}Build philo program${RESET}\n"
	printf "${DARK_BLUE}re:${RESET}	${LIGHT_GRAY}Rebuild the program${RESET}\n"
	printf "${DARK_BLUE}clean:${RESET}	${LIGHT_GRAY}Remove the object files${RESET}\n"
	printf "${DARK_BLUE}fclean:${RESET}	${LIGHT_GRAY}Remove the program and the object files${RESET}\n"
endef

#! ******************************************************************************#
#                                   TARGETS                                      #
#! ******************************************************************************#

all: $(GARB) $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJS)
	$(call comp_exe)

$(GARB):
	$(call comp_garb)

clean:
	$(RM) $(BUILD_DIR)
	$(MAKE) -C $(GARB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(GARB_DIR) fclean

re: fclean all

help:
	$(call help)

-include $(DEPS)
