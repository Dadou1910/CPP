NAME = megaphone

SRC = megaphone.cpp
OBJ = megaphone.o

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ): megaphone.cpp
	$(CXX) $(CXXFLAGS) -c megaphone.cpp -o megaphone.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
