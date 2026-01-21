# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 15:26:21 by pol               #+#    #+#              #
#    Updated: 2026/01/21 10:33:00 by pledieu          ###   ########.fr        #
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
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \
	AForm.cpp \
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
	rm -f "home boss_shrubbery" "home_shrubbery"

re: fclean all

.PHONY: all clean fclean re
