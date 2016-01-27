#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/08/16 09:21:46 by sdurr             #+#    #+#              #
#    Updated: 2015/01/26 16:03:35 by bciss            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#################
##  VARIABLES  ##
#################

#	Sources
SRCDIR		=	./
SRC			=	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strlcpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_atof.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_itoa.c \
				ft_lstnew.c \
				ft_lstadd.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstdel.c \
				ft_lstmap.c \
				ft_putstr_c.c \
				ft_putendl_c.c \
				ft_print_c.c \
				ft_print_d.c \
				ft_print_u.c \
				ft_print_s.c \
				ft_putnbr_u.c \
				ft_print_o.c \
				ft_print_x.c \
				ft_print_p.c \
				ft_print_f.c \
				ft_printf.c \
				ft_sqrt.c

#	Objects
OBJDIR		=	obj

#	Includes
INCDIR		=	./

#	Libraries
LIBDIR		=	libft
LIB			=	-lft

#	Output
NAME		=	libft.a

#	Compiler
CFLAGS		=	-Werror -Wall -Wextra -g -Ofast #-Weverything
CC			=	gcc


################
##   COLORS   ##
################

CLEAN_COLOR		=	3
CLEAN_COLOR_T	=	1
LINK_COLOR		=	5
LINK_COLOR_T	=	4
OBJ_COLOR		=	6
OBJ_COLOR_T		=	2
NORM_COLOR		=	153
NORM_COLOR_T	=	141
NORM_COLOR_ERR	=	160
NORM_COLOR_WAR	=	214


#################
##    AUTO     ##
#################

SHELL		=	/bin/zsh
OBJ			=	$(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
LIBFLAG		=	$(addprefix -L,$(LIBDIR))
INCFLAG		=	$(addprefix -I,$(INCDIR))
NORME		=	$(addsuffix /*.h,$(INCDIR)) $(addprefix $(SRCDIR)/,$(SRC))

$(foreach S,$(SRC), \
	$(eval VPATH_TMP += $(SRCDIR)/$(dir $(S)) \
	))
VPATH		=	$(VPATH_TMP:./=)

disp_indent	=	for I in `seq 1 $(MAKELEVEL)`; do \
				test "$(MAKELEVEL)" '!=' '0' && printf "\t"; \
				done

exec_color	=	$(call disp_indent); \
				echo $(1)$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)"\033[31m"; \
				$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)

disp_title	=	$(call disp_indent); \
				echo "\033[38;5;$(2);1m[  $(1) \#$(MAKELEVEL)  ]\033[0m"


#################
##  TARGETS    ##
#################

#	First target
all: $(NAME)

#	Linking
$(NAME): $(OBJ)
	@$(call disp_title,Linking,$(LINK_COLOR_T));
	@$(call exec_color, "\033[38;5;$(LINK_COLOR_T);1m➤ \033[38;5;$(LINK_COLOR);1m",\
		ar rc, $(NAME), $(OBJ))
	@ranlib $(NAME)

#	Objects compilation
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(call disp_title,Building,$(OBJ_COLOR_T))
	@$(call exec_color,"\033[38;5;$(OBJ_COLOR_T);1m➤ \033[0m\033[38;5;$(OBJ_COLOR);1m",\
		$(CC), $(CFLAGS), $(INCFLAG), -o, $@, -c, $<)
	@$(eval ALREADY_OBJ=x)

#	Removing objects
clean:
	@if [ $(ALREADY_RM)x != xx ]; then \
		$(call disp_title,Cleaning,$(CLEAN_COLOR_T)); \
		fi
	@$(call exec_color,"\033[38;5;$(CLEAN_COLOR_T);1m➤ \033[38;5;$(CLEAN_COLOR);1m",\
		rm -f, $(OBJ)) # <- Cleaning objs
	@rmdir $(OBJDIR) 2> /dev/null || echo "" > /dev/null
	@$(eval ALREADY_RM=x)

#	Removing objects and exe
fclean: clean
	@if [ $(ALREADY_RM)x != xx ]; then \
		$(call disp_title,Cleaning,$(CLEAN_COLOR_T)); \
		fi
	@$(call exec_color,"\033[38;5;$(CLEAN_COLOR_T);1m➤ \033[38;5;$(CLEAN_COLOR);1m",\
		rm -f, $(NAME))
	@$(eval ALREADY_RM=x)

#	All removing then compiling
re: fclean all

#	Checking norme
norme:
	@$(call disp_title,Norme,$(NORM_COLOR_T))
	@norminette $(NORME) | sed "s/Norme/[0;1;$(NORM_COLOR_T);1m➤  [0;38;5;$(NORM_COLOR);1mNorme/g;s/Warning/[38;5;$(NORM_COLOR_WAR);1mWarning/g;s/Error/[38;5;$(NORM_COLOR_ERR);1mError/g"

run: $(NAME)
	@gcc libftprintf.a main.c
	@echo "\033[1;35;7m[  Running #$(MAKELEVEL)  ]\033[0m"
	@echo "\033[0;1;35m➤ \033[0;38;5;147m./a.out ${ARGS}\033[0m"
	@./a.out ${ARGS}

codesize:
	@cat $(NORME) |grep -v '/\*' |wc -l

coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'

.PHONY: all clean fclean re norme codesize coffee

SRC_PATH =	

SRC_NAME =	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_atof.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_lstnew.c \
			ft_lstadd.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstdel.c \
			ft_lstmap.c \
			ft_putstr_c.c \
			ft_print_c.c \
			ft_print_d.c \
			ft_print_u.c \
			ft_print_s.c \
			ft_putnbr_u.c \
			ft_print_o.c \
			ft_print_x.c \
			ft_print_p.c \
			ft_print_f.c \
			ft_printf.c \
			ft_sqrt.c

# OBJ_PATH =	obj/

# INC_PATH =	

# LIB_PATH =	libft.h

# NAME =		libft.a

# MAIN =

# CC =		clang

# CFLAGS =	-Wall -Wextra -Werror

# OBJ_NAME =	$(SRC_NAME:.c=.o)

# all: $(NAME)

# $(NAME): mkdir $(OBJ_NAME)
# 		@ar rc $(NAME) $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# mkdir:
# 	@mkdir -p $(OBJ_PATH)

# %.o: %.c
# 	@echo "\033[31;1m"
# 	@echo -n 'o_OΨ┉ ┉ ┉┉ℵ┉┉ ┉ ┉ΨO_o'
# 	@echo "\033[0m"
# 	@gcc $(FLAGS) -o $(OBJ_PATH)$@ -c $^ -I.
# 	@printf '\033[1;33m%s \t\033[0m\n⇒ \033[1;32m%s\033[0m' $^ "OK."

# clean:
# 		@rm -rf $(addprefix $(OBJ_PATH), $(OBJ_NAME))
# 		@rm -rf $(OBJ_PATH)

# fclean: clean
# 		@rm -rf $(NAME)

# re: fclean all
