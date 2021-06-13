NAME 		= ml

CLANG 		= g++ -std=c++2a

MAIN 		= main.cpp

SRC_NAME 	= linear_algebra.cpp \
			  matrix_functions.cpp \
			  statistic.cpp \
			  main.cpp

SRC_DIR 	= ./source/
SRC			= $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR 	= ./obj/
OBJ 		= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

INC = -I ./includes/

all: 
	$(CLANG) $(OBJ) $(INC) -o $(NAME)
