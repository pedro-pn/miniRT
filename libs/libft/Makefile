SOURCES	=	ft_isalpha.c ft_tolower.c ft_toupper.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c get_next_line.c ft_printf.c \
			ft_printf_utils_1.c ft_printf_hexa.c \
			ft_utoa.c ft_printf_utils_2.c \
			ft_printf_utils_3.c ft_printf_utils_4.c ft_atoi_base.c ft_strrpl.c \
			ft_memrpl.c ft_strcmp.c ft_atof.c ft_putdouble_fd.c ft_strcpy_end.c
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${SOURCES:.c=.o}}
CC = cc
FLAGS = -Werror -Wall -Wextra ${GNL_BUFFER}
GNL_BUFFER = -D BUFFER_SIZE=42
NAME = libft.a

# Colors
L_CYAN = \33[1;36m
L_BLUE = \33[1;34m
L_GREEN = \33[1;92m
NC = \033[0m

all: ${NAME}

${OBJS_PATH}/%.o:	${SRCS_PATH}/%.c
					@ mkdir -p objs
					@ echo "Compiling: $<"
					@ ${CC} ${FLAGS} -I include/ -c -o $@ $<

${NAME}: ${OBJS}
		@ ar -rcs ${NAME} ${OBJS}
		@ echo "${L_GREEN}Libft successfully compiled!${NC}"

clean: 
		@ rm -rf ${OBJS_PATH}
		@ echo "${L_CYAN}Objects deleted!${NC}"

fclean: clean
		@ rm -f ${NAME}
		@ echo "${L_BLUE}Libft deleted!${NC}"

norma:
		@ norminette ${SRCS} include/*

re: fclean all

.PHONY: re clean fclean all norma
