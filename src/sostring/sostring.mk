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

SOSTRING_DIR		=	sostring

SOSTRING_HEADER		=	sostring.h
SOSTRING_FILE		=	sostring.c ft_bzero.c ft_memchr.c\
						ft_memcmp.c ft_memcpy.c ft_memmove.c\
						ft_memset.c ft_split.c ft_strchr.c\
						ft_strdup.c ft_striteri.c ft_strjoin.c\
						ft_strlcat.c ft_strlcpy.c ft_strlen.c\
						ft_strmapi.c ft_strmcat.c ft_strncmp.c\
						ft_strnstr.c ft_strrchr.c ft_strtrim.c\
						ft_substr.c

SOSTRING			=	$(addprefix $(SOSTRING_DIR)/, $(SOSTRING_FILE))
SOSTRING_HEAD		=	$(addprefix $(SOSTRING_DIR)/, $(SOSTRING_HEADER))