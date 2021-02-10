# COMPILATION #
CC		=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror
NASM		=	nasm

OS		:=	$(shell uname)
ifeq ($(OS), Linux)
	NASM_FLAGS 	=	-f elf64
	DIR		=	Linux/
endif
ifeq ($(OS), Darwin)
	NASM_FLAGS	=	-f macho64
	DIR		=	MacOX/
endif


AR		=	ar rcs
RANLIB		=	ranlib
NAME		=	libasm.a
RM		=	rm -f

# FILES #
SRCS			=	$(DIR)ft_strlen.s \
				$(DIR)ft_strcmp.s \
				$(DIR)ft_strcpy.s \
				$(DIR)ft_strdup.s \
				$(DIR)ft_read.s \
				$(DIR)ft_write.s \

# COMPILED_SOURCES #

OBJS		= ${SRCS:.s=.o}

%.o: %.s
		@echo " Updating library..."
		$(NASM) $(NASM_FLAGS) $< -o $@
		@echo "..."
	
## RULES ##

${NAME}:	${OBJS}
			@echo " System is '$(OS)'."
			@echo " All files compiled. ✅"
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo " Library '$(NAME)' compiled. ✅"

# OBLIGATORY PART #
all: 		${NAME}

clean:
		${RM} ${OBJS} 

fclean:		clean
		${RM} ${NAME}
		${RM} ./a.out

re:		fclean all

.PHONY: 	all clean fclean re 
