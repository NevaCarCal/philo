# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 14:25:13 by ncarrera          #+#    #+#              #
#    Updated: 2025/10/16 22:46:12 by ncarrera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile / libft names & settings
NAME = philo
CC = cc
CFLAGS = -I./headers -g#-Wall -Wextra -Werror -O0

# Source specification
SRCS = ./srcs/main.c ./srcs/philos.c ./srcs/init_exit.c ./srcs/parsing.c \
	   ./srcs/lock_handlers.c ./srcs/death_meal_watcher.c \
	   ./srcs/time_management.c
OBJS = $(SRCS:.c=.o)

# Colours
NC=\033[0m
Purple=\033[0;35m
Cyan=\033[1;36m
Red=\033[0;31m
LC=\033[2K

# Make rules
all: $(NAME)
	@printf "\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	@printf "$(LC)\r"
	@printf "$(Cyan)\rCompiling: $(Purple)$(notdir $<)$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@printf "$(Red)\rDeleting: $(Purple)philo objs$(NC)\n"
	@rm -f $(OBJS)
fclean: clean
	@printf "$(Red)\rDeleting: $(Purple)philo$(NC)\n"
	@rm -f $(NAME)
re: fclean all
reclean:
	@$(MAKE) fclean -s
	@$(MAKE) all -s
	@$(MAKE) clean -s

.PHONY: all clean fclean re cleanbuild
