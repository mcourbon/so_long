NAME 		= so_long

define HEAD                                                      

                                                                            
 @@@@@@    @@@@@@                  @@@        @@@@@@   @@@  @@@   @@@@@@@@  
@@@@@@@   @@@@@@@@                 @@@       @@@@@@@@  @@@@ @@@  @@@@@@@@@  
!@@       @@!  @@@                 @@!       @@!  @@@  @@!@!@@@  !@@        
!@!       !@!  @!@                 !@!       !@!  @!@  !@!!@!@!  !@!        
!!@@!!    @!@  !@!                 @!!       @!@  !@!  @!@ !!@!  !@! @!@!@  
 !!@!!!   !@!  !!!                 !!!       !@!  !!!  !@!  !!!  !!! !!@!!  
     !:!  !!:  !!!                 !!:       !!:  !!!  !!:  !!!  :!!   !!:  
    !:!   :!:  !:!                  :!:      :!:  !:!  :!:  !:!  :!:   !::  
:::: ::   ::::: ::  :::::::::::::   :: ::::  ::::: ::   ::   ::   ::: ::::  
:: : :     : :  :   :::::::::::::  : :: : :   : :  :   ::    :    :: :: :   

endef
export HEAD

DEF_COLOR 	 = \033[0;39m
YELLOW		 = \033[0;93m
GREEN		 = \033[0;92m
BLUE 		 = \033[0;94m
CYAN		 = \033[0;96m
PURPLE		 = \033[0;35m
BOLD		 = \033[1m

CFLAGS		=	-Wall -Werror -Wextra
MLXFLAGS_OBJ	=	-I/usr/include -I/mlx_linux
MLX_FLAGS	=	-L/mlx_linux -L/usr/lib -I/mlx_linux -lXext -lX11 -lm -lz
CC			=	cc
MINILIBX	=	libmlx.a

FILES 		=	so_long						\
				gnl/get_next_line_utils		\
				gnl/get_next_line			\
				mobs/check_mobs				\
				mobs/draw_mobs				\
				mobs/update_mobs			\
				parsing/check_map			\
				parsing/check_path			\
				parsing/read_map			\
				player/player_update		\
				source/game_draw			\
				source/game_exit			\
				source/game_load			\
				source/game_move_update		\
				source/game_update			\
				utils/ft_itoa				\
				utils/ft_memcpy				\
				utils/ft_putendl_fd			\
				utils/ft_split				\
				utils/ft_strdup				\
				utils/ft_strjoin			\
				utils/ft_strlen				\

all: $(NAME)

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

HEADER_DIR = ./
HEADER = $(wildcard $(HEADER_DIR)*.h)

%.o: %.c $(HEADER) Makefile
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(MLXFLAGS_OBJ) -c $< -o $@

$(NAME): $(OBJS)
	make -C mlx_linux
	@echo "\n$(GREEN)so_long successfuly compiled !$(DEF_COLOR)"
	@echo "$(CYAN)$(BOLD)$$HEAD$(DEF_COLOR)"
	@${CC} $(CFLAGS) $(SRCS) -I $(HEADER) mlx_linux/$(MINILIBX) $(MLX_FLAGS) -o ${NAME}

clean:
	make clean -C mlx_linux
	@$(RM) $(OBJS)
	@echo "$(CYAN)so_long object files cleaned!$(DEF_COLOR)"

fclean: clean
	make clean -C mlx_linux
	@$(RM) $(NAME)
	@$(RM) $(MINILIBX)
	@echo "$(CYAN)3$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(CYAN)2$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(CYAN)1$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(GREEN)so_long executable files cleaned!$(DEF_COLOR)"


re: fclean all

.PHONY: all clean fclean re