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

HOOKS_DIR		=	hooks

HOOKS_HEADER	=	hooks.h
HOOKS_FILE		=	hooks.c sokeys.c 

HOOKS			=	$(addprefix $(HOOKS_DIR)/, $(HOOKS_FILE))
HOOKS_HEAD		=	$(addprefix $(HOOKS_DIR)/, $(HOOKS_HEADER))