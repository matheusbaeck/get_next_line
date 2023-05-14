# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 01:21:47 by mamagalh@st       #+#    #+#              #
#    Updated: 2023/03/14 21:04:43 by mamagalh@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = main.out

HEADER_NAME = get_next_line.h

HEADER_PATH = /Users/mamagalh/42Projects/\#header/

SRC_PATH = /Users/mamagalh/42Projects/get_next_line/proj/

CC = cc

HEADER_FLAG = -I$(HEADER_PATH)

BUFFER_SIZE = -D BUFFER_SIZE=10

FLAGS = $(HEADER_FLAG) -Wall -Wextra -Werror -g

SRC = main.c \
	$(SRC_PATH)get_next_line.c \
	$(SRC_PATH)get_next_line_utils.c

all: $(NAME)

$(NAME): $(SRC) $(HEADER_PATH)$(HEADER_NAME)
	$(CC) $(FLAGS) $(BUFFER_SIZE) $(SRC) -o $(NAME)

$(HEADER_PATH)$(HEADER_NAME): $(SRC_PATH)$(HEADER_NAME)
	ln -f $(SRC_PATH)$(HEADER_NAME) $(HEADER_PATH)$(HEADER_NAME)

clean:
	rm -rf *.o *.dSYM *.out

fclean: clean
	rm -f $(NAME) $(HEADER_PATH)$(HEADER_NAME)

re: fclean all

run: $(NAME) file
	./$(NAME)
	make diff
	cat files/*_diff.txt

srun: re run

paco:
	bash paco.sh

file:
	cd /Users/mamagalh/42Projects/get_next_line/extra/files/; \
	make

diff:
	cd /Users/mamagalh/42Projects/get_next_line/extra/files/; \
	make diff

