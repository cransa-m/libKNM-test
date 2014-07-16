# Variables
# =========

# Test binary name
NAME			=	test.bin

# Local sources (test functions, main, ...) 
SRC				=	./main.c

# External libraries and sources.
KNM			=	-lKNM -Wl,-rpath /usr/local/lib

# Search path (includes)
INCLUDE			=	/usr/local/include/libKNM

# Compilator flags to use
CFLAGS			=	-W -Wall -ansi -pedantic

# Libraries to link
CLIBS 			=	-lpthread

# Compilator
CC			=	g++

# Rules
# =====
all:		$(NAME)

$(NAME):
			$(CC) -I $(INCLUDE) $(CFLAGS) $(CLIBS) $(SRC) $(KNM) -o $(NAME)
			@rm -f testLog1.log

fclean:
	rm -f $(NAME)
	@rm -f testLog1.log

re: fclean all
