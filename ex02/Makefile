# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uxuemancisidorlaskurain <uxuemancisidor    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 14:49:07 by uxmancis          #+#    #+#              #
#    Updated: 2025/10/21 12:13:41 by uxuemancisi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiler flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

# Source files and object files
SRC =	main.cpp

OBJ = $(SRC:.cpp=.o)

# Executable name
NAME = cpp08_ex02

# Make all rule
all: $(NAME)

# Build the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ)

# Clean everything, including the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re