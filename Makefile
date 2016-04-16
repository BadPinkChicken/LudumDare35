NAME		= ludum_dare

SRCS		= main.cpp \
		ACharacter.cpp \
		Humain.cpp \
		AnimatedSprite.cpp \
		Animation.cpp \
		back.cpp \
		AObstacle.cpp \
		JumpObstacle.cpp \
		SmallObstacle.cpp \
		DestructibleObstacle.cpp \
		PowerEvent.cpp \
		Hulk.cpp

OBJS		= $(SRCS:.cpp=.o)

RM		= rm -rf

GCC		= g++ -o

CXXFLAGS	+= -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=gnu++11
CXXFLAGS	+= -Iincludes/

all: $(NAME)

$(NAME): $(OBJS)
	 $(GCC) $(NAME) $(OBJS) $(CXXFLAGS)

debug: CXXFLAGS = -Wall -Wextra -g3 -lsfml-graphics -lsfml-window -lsfml-system -std=gnu++11
debug: CXXFLAGS += -Iincludes/
debug: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
