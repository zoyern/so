# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 16:01:12 by marvin            #+#    #+#              #
#    Updated: 2024/05/01 21:13:34 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include build.mk

#❖═════Arguments══════❖
ARGS		= 

#❖═════Commandes══════❖
all : $(NAME)

start :
	@make re
	@make clear
	@./$(NAME) $(ARGS)

clear :
	@clear
	@echo "42Paris : $(NAME)"
	@echo ""

clean : clear
	@rm -rf build/
	@echo "Clean   : *.o in build !"

fclean : clean
	@rm -f $(NAME)
	@echo "Clean   : ./$(NAME)"


val :
	@make re
	@clear
	valgrind --leak-check=full --track-fds=yes --show-leak-kinds=all --trace-children=yes --track-origins=yes ./$(NAME) $(ARGS)
	@echo ""

check : 
	@make re
	@clear
	funcheck -o ./$(NAME) $(ARGS)
	@echo ""

re: fclean all clear 

.PHONY: all clean fclean re val dependencies