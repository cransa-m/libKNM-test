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
CFLAGS			=	-Wl,--no-as-needed -std=c++11

# Libraries to link
CLIBS 			=	-lpthread -ldl

# Compilator
CC			=	g++

# Dynamic Library
DYLIB			=	Dylib/Dylib.cpp
OBJDYLIB		= 	$(DYLIB:.cpp=.o)
NAMELIB			=	testDyLib.so.1

# Rules
# =====
all:		 $(NAME)

$(NAME):	
			$(CC) $(DYLIB) -fPIC -c
			mv Dylib.o Dylib
			$(CC) -shared -Wl,-soname,$(NAMELIB)  -o $(NAMELIB).0 $(OBJDYLIB)
			$(CC) -I $(INCLUDE) $(CFLAGS) $(CLIBS) $(SRC) $(KNM) -o $(NAME)

fclean:
	rm -f $(NAME)
	rm -f $(OBJDYLIB)
	rm -f $(NAMELIB).0


re: fclean all
