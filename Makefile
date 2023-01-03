SOURCES =	main.c args.c
NAME = miniRT
LIBFT = libs/libft/libft.a
MLX = libs/minilibs/libmlx_Linux.a
SRCS_PATH = ./sources
OBJS_PATH = ./objects
MY_SRCS = ${addprefix ${SRCS_PATH}/, ${notdir ${MY_SOURCES}}}
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${notdir ${SOURCES:.c=.o}}}
#VPATH :=	${SRCS_PATH} ${SRCS_PATH}/main ${SRCS_PATH}/file
CC = cc
FLAGS = -g

# Colors
GREEN = \33[1;32m
L_CYAN = \33[1;36m
L_BLUE = \33[1;34m
L_GREEN = \33[1;92m
L_PURPLE = \33[1;35m
NC = \033[0m

all: ${NAME}

bonus: ${BONUS}

${OBJS_PATH}/%.o: ${SRCS_PATH}/%.c
	@ mkdir -p ${OBJS_PATH}
	@ printf "Compiling: $< %10s\r"
	@ ${CC} ${FLAGS} -I libs/libft/include/ -I includes/ -Ilibs/minilibx -c $< -o $@

${NAME}: ${MLX} ${LIBFT} ${OBJS}
	@ ${CC} ${FLAGS} ${OBJS} -Llibs/minilibx -lmlx_Linux -lXext -lX11 -lm ${LIBFT} -o ${NAME} 
	@ echo "\12${GREEN}${NAME} successfully compiled!${NC}"

${LIBFT}:
	@ make -C libs/libft/ --no-print-directory

${MLX}:
		@ echo "Compiling Minilibx..."
		@ make -C libs/minilibx --no-print-directory
		@ clear
		@ echo "$(L_GREEN)Minilibx successufully compiled!$(NC)"


# ***********************WILDCARD COMPILATION******************* # 
NAME_WILD = minirt
NAME_ARCHIVE = minirt.a
SOURCES_W = $(wildcard $(SRCS_PATH)/**/*.c) $(wildcard $(SRCS_PATH)/*.c)
OBJECTS_W = $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SOURCES_W))
OBJECTS_W_PATH = ${dir ${OBJECTS_W}}

m: ${NAME_WILD}


${NAME_WILD}: ${LIBFT} ${NAME_ARCHIVE}
				${CC} ${FLAGS} ${NAME_ARCHIVE} -Llibs/minilibx -lmlx_Linux -lXext -lX11 -lm ${LIBFT} -o ${NAME_WILD}

${NAME_ARCHIVE}: ${OBJECTS_W}
				ar -rcs ${NAME_ARCHIVE} ${OBJECTS_W}

dirs:
		mkdir -p ${OBJECTS_W_PATH}

# ============================================================ #

clean:
	@ rm -rf ${OBJS_PATH}
	@ echo "${L_CYAN}Objects deleted!${NC}"

fclean: clean
	@ make fclean -C libs/libft/ --no-print-directory
	@ rm -rf ${NAME} ${NAME_ARCHIVE} ${NAME_WILD}
	@ echo "${L_BLUE}miniRT deleted!${NC}"

re: fclean all

.PHONY: clean re all fclean