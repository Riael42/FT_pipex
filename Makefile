NAME    =   pipex
INC     =   pipex.h
FLAGS   =   -Wall -Wextra -Werror

SRC     =   ft_check_command.c ft_check_errors.c ft_cook_path.c \
ft_empty_mat.c ft_fill_args.c ft_get_path.c ft_pipex.c \
ft_process_path.c ft_putstr.c ft_split.c ft_split_utils.c \
ft_start_pipe.c ft_strdup.c ft_strdupi.c ft_strlen.c main.c

OBJ = $(SRC:.c=.o)

SRC_PATH = .

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
