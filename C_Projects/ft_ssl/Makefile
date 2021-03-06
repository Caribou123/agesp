CC = gcc
# CFLAGS = -Wall -Werror -Wextra

NAME = ./ft_ssl

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INCLS = $(LIBFT_DIR)/includes

SRC_DIR = ./src
UTILS_DIR = $(SRC_DIR)/utils
CRYPTO_DIR = $(SRC_DIR)/crypto
CYPHER_DIR = $(SRC_DIR)/cypher
vpath %.c $(SRC_DIR) $(UTILS_DIR) $(CRYPTO_DIR) $(CYPHER_DIR)

MAIN_PATH = $(addprefix $(SRC_DIR)/, $(MAIN))
UTILS_PATHS = $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))
CRYPTO_PATHS = $(addprefix $(CRYPTO_DIR)/, $(CRYPTO_SRCS))
CYPHER_PATHS = $(addprefix $(CYPHER_DIR)/, $(CYPHER_SRCS))
SRC_PATHS = $(MAIN_PATH) $(UTILS_PATHS) $(CRYPTO_PATHS)

UTILS_SRCS = parser.c \
			 exit.c \
			 files.c \
			 console.c \
			 strings.c

CRYPTO_SRCS = ft_md5.c \
			  ft_sha256.c \
			  utils.c

CYPHER_SRCS = ft_base64.c

MAIN = ft_ssl.c
SRCS = $(MAIN) $(UTILS_SRCS) $(CRYPTO_SRCS) $(CYPHER_SRCS)

OBJ_DIR = ./obj
OBJS = $(SRCS:.c=.o)
OBJ_PATHS = $(addprefix $(OBJ_DIR)/, $(OBJS))

INCL_DIR = ./includes
INCLS = $(INCL_DIR)/ft_ssl.h

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ_DIR) $(OBJ_PATHS) $(INCLS) $(SRC_PATHS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_PATHS) -I$(INCL_DIR) -I$(LIBFT_INCLS) $(LIBFT_LIB) -lm -ggdb

$(OBJ_DIR)/%.o: %.c $(INCLS) $(LIBFT_LIB)
	@printf "building : %s\n" $<
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCL_DIR) -I$(LIBFT_INCLS) -lm -ggdb

$(OBJ_DIR):
	@mkdir -p $@

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
