# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orakib <orakib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 18:43:02 by orakib            #+#    #+#              #
#    Updated: 2023/09/23 20:51:52 by orakib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

TEST = test

SRC = main.cpp ScalarConverter.cpp

HEADER = ScalarConverter.hpp

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

OBJ = $(SRC:.cpp=.o)

all: $(NAME) $(TEST)

$(test): test.cpp $(NAME)
	$(CC) $(CFLAGS) -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME) $(TEST)
	
re: fclean all test

.PHONY: all clean fclean re