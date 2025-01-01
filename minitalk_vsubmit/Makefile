# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:19:42 by tat-nguy          #+#    #+#              #
#    Updated: 2025/01/01 12:34:17 by tat-nguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libft
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Source Files
SRCS_DIRS	= srcs
SRCS_SERVER	= $(SRCS_DIRS)/server.c
SRCS_CLIENT = $(SRCS_DIRS)/client.c
SRCS_BONUSS	= $(SRCS_DIRS)/server_bonus.c
SRCS_BONUSC = $(SRCS_DIRS)/client_bonus.c

# Object Files
OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)
OBJS_BONUSS	= $(SRCS_BONUSS:.c=.o)
OBJS_BONUSC	= $(SRCS_BONUSC:.c=.o)

# Include
INCLUDES	= -I includes

# Compiler and Flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

# Targets
all:	$(LIBFT) server client

bonus:	$(LIBFT) server_bonus client_bonus

# Build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Build server
server:	$(OBJS_SERVER)
	@$(CC) $(CFLAGS) $(INCLUDES) -L$(LIBFT_DIR) -lft -o server $(OBJS_SERVER)

# Build client
client: $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(INCLUDES) -L$(LIBFT_DIR) -lft -o client $(OBJS_CLIENT)

# Build bonus:
server_bonus: $(OBJS_BONUSS)
	@$(CC) $(CFLAGS) $(INCLUDES) -L$(LIBFT_DIR) -lft -o server_bonus $(OBJS_BONUSS)

client_bonus: $(OBJS_BONUSC)
	@$(CC) $(CFLAGS) $(INCLUDES) -L$(LIBFT_DIR) -lft -o client_bonus $(OBJS_BONUSC)
	
# Clean
clean:
	@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_BONUSS) $(OBJS_BONUSC)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	@$(RM) server client server_bonus client_bonus
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus server client server_bonus client_bonus
