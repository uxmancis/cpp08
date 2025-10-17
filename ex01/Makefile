# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uxmancis <uxmancis>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 14:49:07 by uxmancis          #+#    #+#              #
#    Updated: 2025/10/17 13:18:38 by uxmancis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiler flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

# Source files and object files
SRC =	main.cpp\
		Span.cpp

OBJ = $(SRC:.cpp=.o)

# Executable name
NAME = cpp08_ex01

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