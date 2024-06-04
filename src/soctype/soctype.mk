# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sostdlib.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 21:26:57 by marvin            #+#    #+#              #
#    Updated: 2024/04/11 21:26:57 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOCTYPE_DIR			=	soctype

SOCTYPE_HEADER		=	soctype.h
SOCTYPE_FILE		=	soctype.c ft_isalnum.c ft_isalpha.c\
						ft_isascii.c ft_isdigit.c ft_isprint.c\
						ft_tolower.c ft_toupper.c 

SOCTYPE				= $(addprefix $(SOCTYPE_DIR)/, $(SOCTYPE_FILE))
SOCTYPE_HEAD		= $(addprefix $(SOCTYPE_DIR)/, $(SOCTYPE_HEADER))