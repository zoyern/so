# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    soimgmemory.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 02:15:59 by marvin            #+#    #+#              #
#    Updated: 2024/07/02 19:13:13 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOMEMORY_DIR		=	soimgmemory

SOMEMORY_HEADER		=	soimgmemory.h
SOMEMORY_FILE		=	soimgmemory.c soimgfree.c soimgmemory_add.c \
						soimgmemory_show.c soimgmemory_clear.c soimgmemory_find.c \

SOMEMORY			=	$(addprefix $(SOMEMORY_DIR)/, $(SOMEMORY_FILE))
SOMEMORY_HEAD		=	$(addprefix $(SOMEMORY_DIR)/, $(SOMEMORY_HEADER))