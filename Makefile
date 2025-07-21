# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 14:25:13 by ncarrera          #+#    #+#              #
#    Updated: 2025/07/21 18:29:34 by ncarrera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile / libft names & settings
NAME = philo
CC = cc
LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a
CFLAGS = -I./libft #-Wall -Wextra -Werror -O0

# Linker flags
LDFLAGS = -L$(LIBFT_DIR) -lft

# Source specification
SRCS = ./srcs/main.c ./srcs/philos.c
OBJS = $(SRCS:.c=.o)

# Colours
NC=\033[0m
Purple=\033[5;35m
Cyan=\033[1;36m
Red=\033[5;31m

# Make rules
all: $(LIBFT_A) $(NAME)
	@printf "\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT_A):
	@make -s -C $(LIBFT_DIR)

%.o: %.c
	@printf "$(Cyan)\rCompiling: $(Purple)$(notdir $<)$(NC)\r"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(Red)\rDeleting: $(Purple)philo objs$(NC)\n"
	@rm -f $(OBJS)
	@make clean -s -C $(LIBFT_DIR)
fclean: clean
	@printf "$(Red)\rDeleting: $(Purple)philo$(NC)\n"
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT_DIR)
re: fclean all
cleanbuild:
	@$(MAKE) fclean -s
	@$(MAKE) all -s
	@$(MAKE) clean -s

.PHONY: all clean fclean re cleanbuild
