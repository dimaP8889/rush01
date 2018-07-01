NAME = ft_gkrellm

SRC =	main.cpp	\
		Graph.class.cpp \
			
OBJ = $(SRC:.cpp=.o)

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NCURS = -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(NCURS)  $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
		$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all 