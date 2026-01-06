# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pol <pol@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 15:26:21 by pol               #+#    #+#              #
#    Updated: 2026/01/06 11:20:46 by pol              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := a.out

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
INCDIR := inc
SRCDIR := src
OBJDIR := obj

INC := -I$(INCDIR)

SRC := \
	Bureaucrat.cpp \
	Form.cpp \
	main.cpp

SRCS := $(addprefix $(SRCDIR)/,$(SRC))
OBJS := $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
