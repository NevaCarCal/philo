# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 14:25:13 by ncarrera          #+#    #+#              #
#    Updated: 2025/07/21 20:15:24 by ncarrera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile / libft names & settings
NAME = philo
CC = cc
CFLAGS = -I./headers#-Wall -Wextra -Werror -O0

# Source specification
SRCS = ./srcs/main.c ./srcs/philos.c
OBJS = $(SRCS:.c=.o)

# Colours
NC=\033[0m
Purple=\033[5;35m
Cyan=\033[1;36m
Red=\033[5;31m

# Make rules
all: $(NAME)
	@printf "\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	@printf "$(Cyan)\rCompiling: $(Purple)$(notdir $<)$(NC)\r"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(Red)\rDeleting: $(Purple)philo objs$(NC)\n"
	@rm -f $(OBJS)
fclean: clean
	@printf "$(Red)\rDeleting: $(Purple)philo$(NC)\n"
	@rm -f $(NAME)
re: fclean all
cleanbuild:
	@$(MAKE) fclean -s
	@$(MAKE) all -s
	@$(MAKE) clean -s

.PHONY: all clean fclean re cleanbuild
