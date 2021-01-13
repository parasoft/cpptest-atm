CC=g++
INCLUDE_FLAGS=-Iinclude
DEBUG_FLAGS=
CFLAGS=-g
OBJ_DIR=build/obj
APP_DIR=build
APP_NAME=atm

OBJ = $(OBJ_DIR)/ATM.o \
	  $(OBJ_DIR)/Bank.o \
	  $(OBJ_DIR)/BaseDisplay.o \
	  $(OBJ_DIR)/Account.o \
	  $(OBJ_DIR)/Main.o

.PHONY = clean all
	
all : $(OBJ_DIR) $(APP_NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cxx
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -o $@ -c $^ 

$(APP_DIR) :
	mkdir -p $(APP_DIR)

$(APP_NAME) : $(OBJ) $(APP_DIR)
	$(CC) $(OBJ_DIR)/*.o -o $(APP_DIR)/$(APP_NAME)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(APP_DIR)
