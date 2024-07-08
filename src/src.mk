# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almounib <almounib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 18:55:59 by marvin            #+#    #+#              #
#    Updated: 2024/05/16 14:38:34 by almounib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include src/gears/gears.mk
include src/hooks/hooks.mk
include src/windows/windows.mk
include src/render/render.mk
include src/colliders/colliders.mk
include src/soimgmemory/soimgmemory.mk
include src/sprite/sprite.mk

SRC_DIR		=	$(CURDIR)/src

LIB_HEADER	=	$(addprefix $(SRC_DIR)/, so.h)
SRC_HEADER	=	so_t.h all.h
SRC_FILES	=	so.c

DIR			+= $(GEARS_DIR)
DIR			+= $(HOOKS_DIR)
DIR			+= $(WINDOWS_DIR)
DIR			+= $(RENDER_DIR)
DIR			+= $(SOMEMORY_DIR)
DIR			+= $(SPRITE_DIR)
DIR			+= $(COLLIDERS_DIR)

SRC_HEADER	+= $(GEARS_HEAD)
SRC_HEADER	+= $(HOOKS_HEAD)
SRC_HEADER	+= $(WINDOWS_HEAD)
SRC_HEADER	+= $(RENDER_HEAD)
SRC_HEADER	+= $(SOMEMORY_HEAD)
SRC_HEADER	+= $(SPRITE_HEAD)
SRC_HEADER	+= $(COLLIDERS_HEAD)

SRC_FILES	+= $(GEARS)
SRC_FILES	+= $(HOOKS)
SRC_FILES	+= $(WINDOWS)
SRC_FILES	+= $(RENDER)
SRC_FILES	+= $(SOMEMORY)
SRC_FILES	+= $(SPRITE)
SRC_FILES	+= $(COLLIDERS)

HEADERS		=	$(addprefix $(SRC_DIR)/, $(SRC_HEADER))
SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
FOLDERS		=	$(addprefix $(SRC_DIR)/, $(DIR))
FOLDERS		+=	$(SRC_DIR)