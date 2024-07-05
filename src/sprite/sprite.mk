# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    fork.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 20:23:13 by marvin            #+#    #+#              #
#    Updated: 2024/04/07 20:23:13 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include src/sprite/sprite_list/sprite_list.mk

SPRITE_DIR		=	sprite

SPRITE_HEADER	=	sprite.h
SPRITE_FILE		=	sprite.c sprite_colorized.c sprite_grid.c sprite_color.c sprite_modier.c
SPRITE_FILE		+=	$(SPRITE_LIST)

SPRITE			=	$(addprefix $(SPRITE_DIR)/, $(SPRITE_FILE))
SPRITE_HEAD		=	$(addprefix $(SPRITE_DIR)/, $(SPRITE_HEADER))