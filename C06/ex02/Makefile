NAME		= ./identify 
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
SRC 		= main.cpp A.cpp B.cpp C.cpp Base.cpp
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re