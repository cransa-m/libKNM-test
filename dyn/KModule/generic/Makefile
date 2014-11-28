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
CFLAGS			=	-W -Wall -g -ansi

# Libraries to link
CLIBS 			=	-lpthread -ldl

# Compilator
CC			=	g++ -std=c++11

# Dynamic Library
DYLIB			=	Module/ModuleTest.cpp
OBJDYLIB		= 	$(DYLIB:.cpp=.o)
NAMELIB			=	testModule.so.1

# Rules
# =====
all:		 $(NAME)

$(NAME):	
			$(CC) $(DYLIB) -fPIC -c
			mv ModuleTest.o Module
			$(CC) -shared -Wl,-soname,$(NAMELIB)  -o $(NAMELIB).0 $(OBJDYLIB) -ldl
			$(CC) -I $(INCLUDE) $(CFLAGS) $(SRC) $(KNM) -o $(NAME) $(CLIBS)

fclean:
	rm -f $(NAME)
	rm -f $(OBJDYLIB)
	rm -f $(NAMELIB).0


re: fclean all
