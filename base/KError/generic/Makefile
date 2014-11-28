# Variables
# =========

# Test binary name
NAME			=	test.bin

# Local sources (test functions, main, ...) 
SRC				=	./main.c

# External libraries and sources.
KNM			=	-lKNM -Wl,-rpath /usr/local/lib

# Search path (includes)
INCLUDE			=	/usr/local/include/KNM

# Compilator flags to use
CFLAGS			=	-W -Wall -ansi -pedantic -Wl,--no-as-needed

# Libraries to link
CLIBS 			=	-lpthread -ldl

# Compilator
CC			=	g++

# Rules
# =====
all:		$(NAME)

$(NAME):
			$(CC) -I $(INCLUDE) $(CFLAGS) $(CLIBS) $(SRC) $(KNM) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
