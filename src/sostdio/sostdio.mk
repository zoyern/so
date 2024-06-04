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

SOSTDIO_DIR			= 	sostdio

SOSTDIO_HEADER		= 	sostdio.h
SOSTDIO_FILE		=	sostdio.c ft_putchar_fd.c ft_putendl_fd.c\
						ft_putnbr_fd.c ft_putstr_fd.c

SOSTDIO				= 	$(addprefix $(SOSTDIO_DIR)/, $(SOSTDIO_FILE))
SOSTDIO_HEAD		=	$(addprefix $(SOSTDIO_DIR)/, $(SOSTDIO_HEADER))