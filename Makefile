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
SRCDIR		=	srcs
SRC			=	main.c			\
				ft_ls.c			\
				ft_print.c		\
				ft_print_l.c	\
				ft_lt.c			\
				ft_rec.c		\
				ft_init.c		\
				ft_ft.c
				

#	Objects
OBJDIR		=	obj

#	Includes
INCDIR		=	includes libft

#	Libraries
LIBDIR		=	libft
LIBS		=	ft

#	Output
NAME		=	ft_ls

#	Compiler
CFLAGS		=	-Werror -Wall -Wextra -g -Ofast #-Weverything
CC			=	clang


################
##   COLORS   ##
################

CLEAN_COLOR		=	9
CLEAN_COLOR_T	=	196
LINK_COLOR		=	47
LINK_COLOR_T	=	46
OBJ_COLOR		=	122
OBJ_COLOR_T		=	123
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
LIB			=	$(addprefix -l,$(LIBS))
INCFLAG		=	$(addprefix -I,$(INCDIR))
NORME		=	$(addsuffix /*.h,$(INCDIR)) $(addprefix $(SRCDIR)/,$(SRC))

$(foreach S,$(SRC), \
	$(eval VPATH_TMP += $(SRCDIR)/$(dir $(S)) \
	))
VPATH		=	$(VPATH_TMP:./=)

disp_indent	=	for I in `seq 1 $(MAKELEVEL)`; do \
				test "$(MAKELEVEL)" "!=" "0" && printf "\t"; \
				done

exec_color	=	$(call disp_indent); \
				echo $(1)$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)"\033[31m"; \
				$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)

disp_title	=	$(call disp_indent); \
				echo "\033[38;5;$(2);m[  $(1) \#$(MAKELEVEL)  ]\033[0m"


#################
##  TARGETS    ##
#################

#	First target
all: $(NAME)

#	Linking
$(NAME): $(OBJ)
	@make -C libft
	@$(call disp_title,Linking,$(LINK_COLOR_T));
	@$(call exec_color, "\033[38;5;$(LINK_COLOR_T)m➤ \033[38;5;$(LINK_COLOR)m",\
		$(CC), $(CFLAGS), $(LIBFLAG), $(LIB), -o, $(NAME), $(OBJ))

#	Objects compilation
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(call disp_title,Building,$(OBJ_COLOR_T))
	@$(call exec_color,"\033[38;5;$(OBJ_COLOR_T)m➤ \033[0m\033[38;5;$(OBJ_COLOR)m",\
		$(CC), $(CFLAGS), $(INCFLAG), -o, $@, -c, $<)
	@$(eval ALREADY_OBJ=x)

#	Removing objects
clean:
	@if [ $(ALREADY_RM)x != xx ]; then \
		$(call disp_title,Cleaning,$(CLEAN_COLOR_T)); \
		fi
	@$(call exec_color,"\033[38;5;$(CLEAN_COLOR_T)m➤ \033[38;5;$(CLEAN_COLOR)m",\
		rm -f, $(OBJ)) # <- Cleaning objs
	@rmdir $(OBJDIR) 2> /dev/null || echo "" > /dev/null
	@$(eval ALREADY_RM=x)

#	Removing objects and exe
fclean: clean
	@if [ $(ALREADY_RM)x != xx ]; then \
		$(call disp_title,Cleaning,$(CLEAN_COLOR_T)); \
		fi
	@$(call exec_color,"\033[38;5;$(CLEAN_COLOR_T)m➤ \033[38;5;$(CLEAN_COLOR)m",\
		rm -f, $(NAME))
	@$(eval ALREADY_RM=x)

#	All removing then compiling
re: fclean all

#	Checking norme
norme:
	@$(call disp_title,Norme,$(NORM_COLOR_T))
	@norminette $(NORME) | sed "s/Norme/[0;1;$(NORM_COLOR_T)m➤  [0;38;5;$(NORM_COLOR)mNorme/g;s/Warning/[38;5;$(NORM_COLOR_WAR)mWarning/g;s/Error/[38;5;$(NORM_COLOR_ERR)mError/g"

run: $(NAME)
	@echo "\033[1;35;7m[  Running #$(MAKELEVEL)  ]\033[0m"
	@echo "\033[0;1;35m➤ \033[0;38;5;147m./a.out ${ARGS}\033[0m"
	@./$(NAME) ${ARGS}

codesize:
	@cat $(NORME) |grep -v "/\*" |wc -l

.PHONY: all clean fclean re norme codesize

