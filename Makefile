# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 14:27:39 by rnovodra          #+#    #+#              #
#    Updated: 2018/03/16 15:36:18 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	wolf3d

SRC			=	main.c \
				ft_error.c \
				ft_exit.c \
				ft_set_default_info.c \
				ft_events.c \
				ft_init_sdl.c \
				ft_create_audio.c \
				ft_check_arguments.c \
				ft_create_matrix.c \
				ft_create_map.c \
				ft_validation.c \
				ft_create_lvls.c \
				ft_raycasting.c \
				ft_event_window.c \
				ft_event_mouse.c \
				ft_event_keyboard.c \
				ft_draw_pixel.c \
				ft_create_tex_surf_from_files.c \
				ft_data.c \
				ft_put_tex_gun.c \
				ft_put_panel_and_face.c \
				ft_create_walls.c \
				ft_create_surf_text.c \
				ft_turn.c \
				ft_go.c \
				ft_shoot_animation.c \
				ft_draw_floor_ceiling.c \
				ft_texturing.c \
				ft_set_position.c \
				ft_validate_matrix.c \
				ft_create_random_map.c \
				ft_free_matrix.c \
				ft_create_minimap.c \
				ft_change_lvl.c \
				ft_menu_keys.c \
				ft_menu.c \
				ft_create_tex_menu.c \
				ft_coloring.c \
				ft_set_null_map.c \
				ft_wall_validation.c \
				ft_menu_new_game.c\
				ft_check_audio_files.c

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/
LIB_DIR		=	./lib/

LIB			=	$(LIBFT_DIR)libft.a
LIBFT_DIR	=	$(LIB_DIR)libft/
LIBFT_INC	=	$(LIBFT_DIR)inc/
LIBFT_FLAGS	=	-lft -L $(LIBFT_DIR)

HEADER		=	$(INC_DIR)wolf3d.h

LINK_FLAGS	=	$(LIBFT_FLAGS)

HEAD_FLAGS	=	-I $(INC_DIR) -I $(LIBFT_INC)

CC_FLAGS	=	-Wall -Werror -Wextra

CC			=	gcc
 
SDL_FLAGS	=	-I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks

BY = "\033[33;1m"
BR = "\033[31;1m"
BG = "\033[32;1m"
BB = "\033[34;1m"
BM = "\033[35;1m"
BW = "\033[37;1m"
KRY = "\033[31;1;41m"
KR = "\033[31;1m"
X = "\033[0m"

all : $(NAME) art

$(NAME) : $(LIB) $(OBJ)
	@$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME) $(SDL_FLAGS) -framework SDL2

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADER)
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS) $(SDL_FLAGS)
	@echo ${BG}"[ ✓ ] $<"

$(LIB):
	@make -C $(LIBFT_DIR)

clean :
	@rm -rf $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)
	@echo ${BR}"[✗] $(NAME)"

re : fclean all

vpath %.c $(SRC_DIR)

art:
	@echo ${BB}
	@echo "                                __"
	@echo "                              .dSSb"
	@echo "                            .\' TOS;\\ "
	@echo "                           /  : TP._;"
	@echo "                          / _.;  :Tb|         "${BR}"W"${BY}"O"${BG}"L"${BM}"F"${BB}" 3D "${KR}"!"${X}${BB}
	@echo "                         /   /   ;"${BW}"j"${BB}"S"${BW}"j"${BB}"        /"
	@echo "                     _.-\"       "${BW}"d"${BB}"SSS"${BW}"S"${BB}
	@echo "                   .' ..       "${BW}"d"${BB}"SSSS"${BW}";"${BB}
	@echo "                  /  /🔥"${X}${BB}"'      "${BW}"d"${BB}"SSSSP. "${BW}"|\\ " ${BB}
	@echo "                 /   \"      ."${BW}"d"${BB}"SSSP' "${BW}"|\\ " ${BB}"^\"l"
	@echo "               .'           \`TSP"${BW}"^"${BB}"\"\"\"\"\"  :"
	@echo "           ._.'      _.'                ;"
	@echo "        \`-.-\".-'-' ._.       _.-\"    .-\""
	@echo "      \`.-\" _____  ._              .-\""
	@echo "     -(.gSSSSSSSb.              .'"
	@echo "       \"\"^^TSSSP^)            .(:"
	@echo "         _/  -\"  /.'         /:/;"
	@echo "      ._.'-'\`-'  \")/         /;/;"
	@echo "   \`-.-\"..--\"\"   \" /         /  ;"
	@echo "  .-\" ..--\"\"        -'          :"
	@echo "  ..--\"\"--.-\"         (\\      .-(\\ "
	@echo "    ..--\"\"              \`-\\(\\/;\`"
	@echo "      _.                      :"
	@echo "                              ;\`-"
	@echo "                             :\\ "
	@echo "                             ;"
	@echo ${X}
	@echo ${BG}"$(NAME) ready for hunting!"

.PHONY: all fclean clean re 
