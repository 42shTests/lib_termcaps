# ---------------------------------------------------------------------------- #
# PROJECT DATA
# ---------------------------------------------------------------------------- #

NAME		=	libcaps.a

# ---------------------------------------------------------------------------- #

SRCS		=	caps__context.c					\
				caps__initialize.c				\
				caps__finalize.c				\
				caps__init_func.c				\
				caps__init_func_by_keycode.c	\
				caps__exec_func.c				\
				caps__keycode_dump.c			\
				caps__keycode_cmp.c				\
				caps__keycode_find.c			\
				caps__win.c						\
				caps__print.c					\
				caps__print_cap.c				\
				caps__delete_line.c				\
				caps__cursor_to_offset.c		\
				caps__cursor_getxy.c			\
				caps__cursor_setxy.c			\
				node__key.c						\

# ---------------------------------------------------------------------------- #
# PROJECT CONFIGURATION
# ---------------------------------------------------------------------------- #

CFLAGS		=	\
				-g 								\
				-Wall -Wextra -Werror			\

# >>> REQUIRED FOR LIBRARIES >>> THINK ABOUT CHANGING THE *LIBS rules

CPPFLAGS	=	\
				-I $(DIRINC)					\
				-I $(DIRLIB)/libft/				\
				-I $(DIRLIB)/ft_printf/			\

LDFLAGS		=	\
				-L $(DIRLIB)libft				\
				-L $(DIRLIB)ft_printf			\

LDLIBS		=	\
				-ltermcap						\
				-lft							\
				-lprintf						\

# GLOBAL SETUP
AR			=	ar
CC			=	clang
RM			=	rm
MKDIR		=	mkdir
MAKE		=	make

DIRSRC		=	./srcs/
DIROBJ		=	./.objs/
DIRINC		=	./incs/
DIRLIB		=	./libs/

# EXTRA COLOR
C_DFL		=	\033[0m
C_GRA		=	\033[30m
C_RED		=	\033[31m
C_GRE		=	\033[32m
C_YEL		=	\033[33m
C_BLUE		=	\033[34m
C_MAG		=	\033[35m
C_CYA		=	\033[36m
C_WHI		=	\033[37m

# ============================================================================ #

# ---------------------------------------------------------------------------- #
# SOURCES NORMALIZATION
# ---------------------------------------------------------------------------- #

SRC			=	$(addprefix $(DIRSRC), $(SRCS))
OBJ			=	$(addprefix $(DIROBJ), $(notdir $(SRC:.c=.o)))

# ---------------------------------------------------------------------------- #
# RULES
# ---------------------------------------------------------------------------- #

all			:	libs $(NAME)
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) build completed\n" "$(MAKE)"

$(NAME)		:	$(DIROBJ) $(OBJ)
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) linking objects\n" "$(CC)"
	@$(AR) rc $(NAME) $(OBJ)
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) index project\n" "ranlib"
	@ranlib $(NAME)

# ---------------------------------------------------------------------------- #
# CUSTOMISABLE RULES

libs		:
	@make -C ./libs/libft
	@make -C ./libs/ft_printf

fcleanlibs	:
	@make -C ./libs/libft fclean
	@make -C ./libs/ft_printf fclean

# ---------------------------------------------------------------------------- #

clean		:
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) remove objects\n" "$(RM)"
	@$(RM) -rf $(DIROBJ)

fclean		:	fcleanlibs clean
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) remove binaries\n" "$(RM)"
	@$(RM) -f $(NAME)

re			:	fclean all

$(DIROBJ)	:
	@$(MKDIR) -p $(DIROBJ)

depend		:
	@sed -e '/^#start/,/^end/d' Makefile > .mftmp && mv .mftmp Makefile
	@printf "#start\n\n" >> Makefile
	@$(foreach s, $(SRC),													\
		printf '$$(DIROBJ)'										>> Makefile	&& \
		$(CC) -MM $(s) $(CPPFLAGS)								>> Makefile	&& \
																			\
		printf '\t\t@printf "$$(C_GRE)[ $(NAME) ] '				>> Makefile && \
		printf '[ %%-6s ]$$(C_DFL) " "$(CC)"\n'					>> Makefile && \
		printf '\t\t@printf "compiling $(s)\\n"\n'				>> Makefile	&& \
																			\
		printf '\t\t@$$(CC) -c $(s) -o '						>> Makefile	&& \
		printf '$(addprefix $(DIROBJ), $(notdir $(s:.c=.o))) '	>> Makefile	&& \
		printf '$$(CPPFLAGS) $$(CFLAGS) \n\n'					>> Makefile	&& \
																			\
		printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) " "dep"				&& \
		printf "$(s) rule generated\n"										|| \
																			\
		(sed -e '/^#start/,$$d' Makefile > .mftmp && mv .mftmp Makefile		&& \
		printf "#start\n\n"										>> Makefile	&& \
		printf "$(C_RED)[ $(NAME) ] [ %-6s ]$(C_DFL) " "dep"				&& \
		printf "$(s) rule generation failed\n"								) \
	;)
	@printf "\n#end\n" >> Makefile

.PHONY	:	 libs

# ---------------------------------------------------------------------------- #
# AUTO-GENERATED SECTION - do not modify
# ---------------------------------------------------------------------------- #

#start

$(DIROBJ)caps__context.o: srcs/caps__context.c srcs/internal_caps.h incs/caps.h \
  incs/types.h incs/list.h incs/context.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__context.c\n"
		@$(CC) -c ./srcs/caps__context.c -o ./.objs/caps__context.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__initialize.o: srcs/caps__initialize.c srcs/internal_caps.h \
  incs/caps.h incs/types.h incs/list.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__initialize.c\n"
		@$(CC) -c ./srcs/caps__initialize.c -o ./.objs/caps__initialize.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__finalize.o: srcs/caps__finalize.c srcs/internal_caps.h incs/caps.h \
  incs/types.h incs/list.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__finalize.c\n"
		@$(CC) -c ./srcs/caps__finalize.c -o ./.objs/caps__finalize.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__init_func.o: srcs/caps__init_func.c srcs/internal_caps.h \
  incs/caps.h incs/types.h incs/list.h incs/libft.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__init_func.c\n"
		@$(CC) -c ./srcs/caps__init_func.c -o ./.objs/caps__init_func.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__init_func_by_keycode.o: srcs/caps__init_func_by_keycode.c \
  srcs/internal_caps.h incs/caps.h incs/types.h incs/list.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__init_func_by_keycode.c\n"
		@$(CC) -c ./srcs/caps__init_func_by_keycode.c -o ./.objs/caps__init_func_by_keycode.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__exec_func.o: srcs/caps__exec_func.c incs/types.h \
  srcs/internal_caps.h incs/caps.h incs/list.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__exec_func.c\n"
		@$(CC) -c ./srcs/caps__exec_func.c -o ./.objs/caps__exec_func.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__keycode_dump.o: srcs/caps__keycode_dump.c incs/caps.h incs/types.h \
  incs/libft.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__keycode_dump.c\n"
		@$(CC) -c ./srcs/caps__keycode_dump.c -o ./.objs/caps__keycode_dump.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__keycode_cmp.o: srcs/caps__keycode_cmp.c incs/libft.h incs/types.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__keycode_cmp.c\n"
		@$(CC) -c ./srcs/caps__keycode_cmp.c -o ./.objs/caps__keycode_cmp.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__keycode_find.o: srcs/caps__keycode_find.c incs/types.h \
  srcs/internal_caps.h incs/caps.h incs/list.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__keycode_find.c\n"
		@$(CC) -c ./srcs/caps__keycode_find.c -o ./.objs/caps__keycode_find.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__win.o: srcs/caps__win.c srcs/internal_caps.h incs/caps.h \
  incs/types.h incs/list.h incs/libft.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__win.c\n"
		@$(CC) -c ./srcs/caps__win.c -o ./.objs/caps__win.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__print.o: srcs/caps__print.c srcs/internal_caps.h incs/caps.h \
  incs/types.h incs/list.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__print.c\n"
		@$(CC) -c ./srcs/caps__print.c -o ./.objs/caps__print.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__print_cap.o: srcs/caps__print_cap.c srcs/internal_caps.h \
  incs/caps.h incs/types.h incs/list.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__print_cap.c\n"
		@$(CC) -c ./srcs/caps__print_cap.c -o ./.objs/caps__print_cap.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__delete_line.o: srcs/caps__delete_line.c srcs/internal_caps.h \
  incs/caps.h incs/types.h incs/list.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__delete_line.c\n"
		@$(CC) -c ./srcs/caps__delete_line.c -o ./.objs/caps__delete_line.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__cursor_to_offset.o: srcs/caps__cursor_to_offset.c \
  srcs/internal_caps.h incs/caps.h incs/types.h incs/list.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__cursor_to_offset.c\n"
		@$(CC) -c ./srcs/caps__cursor_to_offset.c -o ./.objs/caps__cursor_to_offset.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__cursor_getxy.o: srcs/caps__cursor_getxy.c srcs/internal_caps.h \
  incs/caps.h incs/types.h incs/list.h incs/libft.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__cursor_getxy.c\n"
		@$(CC) -c ./srcs/caps__cursor_getxy.c -o ./.objs/caps__cursor_getxy.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)caps__cursor_setxy.o: srcs/caps__cursor_setxy.c srcs/internal_caps.h \
  incs/caps.h incs/types.h incs/list.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/caps__cursor_setxy.c\n"
		@$(CC) -c ./srcs/caps__cursor_setxy.c -o ./.objs/caps__cursor_setxy.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)node__key.o: srcs/node__key.c srcs/internal_caps.h incs/caps.h \
  incs/types.h incs/list.h incs/libft.h
		@printf "$(C_GRE)[ libcaps.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/node__key.c\n"
		@$(CC) -c ./srcs/node__key.c -o ./.objs/node__key.o $(CPPFLAGS) $(CFLAGS) 


#end
