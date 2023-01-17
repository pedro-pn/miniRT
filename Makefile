SOURCES =	main.c args.c
NAME = miniRT
LIBFT = libs/libft/libft.a
MLX = libs/minilibx/libmlx_Linux.a
SRCS_PATH = ./sources
OBJS_PATH = ./objects
MY_SRCS = ${addprefix ${SRCS_PATH}/, ${notdir ${MY_SOURCES}}}
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${notdir ${SOURCES:.c=.o}}}
CC_LIBS = ${LIBFT} ${MLX}
CC_INCLUDES = -I libs/libft/include -I includes -I libs/minilibx
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
	@ ${CC} ${CC_INCLUDES} ${FLAGS} -c $< -o $@

${NAME}: ${MLX} ${LIBFT} ${OBJS}
	@ ${CC} ${FLAGS} ${OBJS} ${CC_LIBS} -o ${NAME} 
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
MAIN_W = main.c
MAIN_OBJ = ${OBJS_PATH}/main.o
SOURCES_W = $(wildcard $(SRCS_PATH)/**/*.c) $(wildcard $(SRCS_PATH)/*.c) \
			$(wildcard $(SRCS_PATH)/**/**/*.c)
OBJECTS_W = $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SOURCES_W))
OBJECTS_W_PATH = ${dir ${OBJECTS_W}}

m: ${NAME_WILD}


${NAME_WILD}: ${LIBFT} ${NAME_ARCHIVE} ${MAIN_OBJ}
				${CC} ${MAIN_OBJ} ${NAME_ARCHIVE} ${CC_LIBS} ${CC_INCLUDES} -lXext -lX11 -lm ${FLAGS} -o ${NAME_WILD}

${MAIN_OBJ}: ${MAIN_W}
		 @ printf "Compiling: $< %10s\r"
		 @ ${CC} ${CC_INCLUDES} ${FLAGS} -c $< -o $@
			
${NAME_ARCHIVE}: ${OBJECTS_W}
				ar -rcs ${NAME_ARCHIVE} ${OBJECTS_W}

run: m
	./${NAME_WILD}


# ============================================================ #

# ***********************TESTS******************* # 

TEST_PATH = ./tests
SOURCES_T = $(wildcard $(TEST_PATH)/*.c) $(wildcard ${TEST_PATH}/**/*.c)
TESTS = $(patsubst $(TEST_PATH)/%.c, $(TEST_PATH)/%.out, $(SOURCES_T))
test:	test_clean ${TEST_PATH}/$t.out
		./${TEST_PATH}/$t.out

${TEST_PATH}/%.out: ${TEST_PATH}/%.c
			${CC} $<  ${NAME_ARCHIVE} ${CC_LIBS} ${CC_INCLUDES} -lm -o $@

test_clean: clean dirs m
			rm -rf ${wildcard ${TEST_PATH}/*.out} ${wildcard $(TEST_PATH)/**/*.out}

vgtest: test_clean ${TEST_PATH}/$t.out
		valgrind --leak-check=full --show-leak-kinds=all ./${TEST_PATH}/$t.out
# ============================================================ #

clean:
	@ rm -rf ${OBJS_PATH}
	@ echo "${L_CYAN}Objects deleted!${NC}"

fclean: clean
	@ make fclean -C libs/libft/ --no-print-directory
	@ rm -rf ${NAME} ${NAME_ARCHIVE} ${NAME_WILD}
	@ echo "${L_BLUE}miniRT deleted!${NC}"

re: fclean dirs m

dirs:
		mkdir -p ${OBJECTS_W_PATH} ${OBJECTS_T_PATH}

norma:
		norminette sources/
.PHONY: clean re all fclean