NAME			:= so_long
CC				:= cc
RM				:= rm -rf
CFLAGS			:= -Wall -Wextra -Werror
MLX42_FLAGS		:= -ldl -lglfw -pthread -lm

# Additional library paths
LIBFT_DIR			:= ./library/libft
FT_PRINTF_FD_DIR	:= ./library/ft_printf_fd
MLX42_DIR			:= ./library/MLX42

# Libraries
LIBFT				:= $(LIBFT_DIR)/libft.a
FT_PRINTF_FD		:= $(FT_PRINTF_FD_DIR)/libftprintf.a
MLX42				:= $(MLX42_DIR)/build/libmlx42.a

#INCLUDE
INCLUDE				:= -I $(LIBFT_DIR) -I $(FT_PRINTF_FD_DIR) -I ./includes -I ./library/MLX42/include/MLX42/

MAIN				:= ./srcs/main
MANDATORY			:= ./srcs/mandatory
BONUS				:= ./srcs/bonus


PARSING				:= parsing
EXECUTION			:= execution
ERROR				:= error

MAIN_C				:=	main.c				\
						utilities.c

PARSING_C			:=	map_validation.c	\
						read_map.c			\
						utils.c				\
						bfs.c				\
						bfs_utils.c

EXECUTION_C			:=	game_operation.c	\
						graphic.c			\
						display_image.c

ERROR_C				:= error_handling.c

SRCS				:= 	$(addprefix $(MAIN)/,					$(MAIN_C))			\
						$(addprefix	$(MANDATORY)/$(PARSING)/,	$(PARSING_C))		\
						$(addprefix $(MANDATORY)/$(EXECUTION)/,	$(EXECUTION_C))		\
						$(addprefix $(MANDATORY)/$(ERROR)/,		$(ERROR_C))

#BONUS				:=

OBJS				:= $(SRCS:.c=.o)

#OBJS_BN			:= $(BONUS:.c=.o)

#Default Target
all:	mandatory

#Compiling Rule
%.o:	%.c
	@echo "Compiling..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

#Create MLX42 library
$(MLX42)	: .mlx42
.mlx42		:
			@$(RM) $(MLX42_DIR)
			@git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR)
			@cd $(MLX42_DIR) && mkdir -p build && cd build && cmake .. && cmake --build . -j4
			@cd ..
			@$(RM) $(MLX42_DIR)/.git
			@touch .mlx42

#Create source library
mandatory : .mandatory
.mandatory: $(LIBFT) $(FT_PRINTF_FD) $(MLX42) $(OBJS)
		@cc $(OBJS) $(LIBFT) $(FT_PRINTF_FD) $(MLX42) $(MLX42_FLAGS) -o $(NAME)
		@touch .mandatory

# Build libft.a
$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)

# Build ft_printf.a
$(FT_PRINTF_FD):
		@$(MAKE) -C $(FT_PRINTF_FD_DIR)

# Create bonus lib
bonus : .bonus
.bonus : $(OBJS_BN) $(LIBFT) $(FT_PRINTF_FD)
		@cc $(OBJS_BN) $(LIBFT) $(FT_PRINTF_FD) -o $(NAME)
		@touch .bonus

# Clean target
clean:
		@(RM) $(OBJS) $(OBJS_BN) .mandatory .bonus $(MLX42_DIR)/build
		@$(MAKE) -C $(LIBFT_DIR) clean
		@$(MAKE) -C $(FT_PRINTF_FD_DIR) clean

# Fclean target
fclean:
		@echo "----------------------------Cleaning----------------------------"
		@$(RM) $(OBJS) $(OBJS_BN) .bonus .mandatory .mlx42 $(MLX42_DIR)
		@$(MAKE) -C $(LIBFT_DIR) fclean
		@$(MAKE) -C $(FT_PRINTF_FD_DIR) fclean
		@echo "----------------------------Finished----------------------------"

# Rebuild target
re: fclean all


.PHONY: all clean fclean re