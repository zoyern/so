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

COLLIDERS_DIR		=	colliders

COLLIDERS_HEADER	=	colliders.h
COLLIDERS_FILE		=	colliders.c 

COLLIDERS			=	$(addprefix $(COLLIDERS_DIR)/, $(COLLIDERS_FILE))
COLLIDERS_HEAD		=	$(addprefix $(COLLIDERS_DIR)/, $(COLLIDERS_HEADER))