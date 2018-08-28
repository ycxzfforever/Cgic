CC=/opt/am335x_gcc-4.7.3/bin/arm-linux-gnueabihf-gcc
#CC=/opt/arm-2011.09/bin/arm-none-linux-gnueabi-gcc
#CC=arm-none-linux-gnueabi-gcc
#CC=

TARGET1=readinifile
TARGET2=writeinifile

DIR_INC = ./inc
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin

CFLAGS=-Wall -lpthread -lrt -lm -I$(DIR_INC)
CFLAGS += -D Debug

SRC = $(wildcard *.c $(DIR_SRC)/*.c)  
OBJ = $(patsubst %.c,$(DIR_OBJ)/%.o,$(notdir $(SRC))) 
BIN_TARGET1 = $(DIR_BIN)/$(TARGET1).cgi
BIN_TARGET2 = $(DIR_BIN)/$(TARGET2).cgi

all:$(BIN_TARGET1) $(BIN_TARGET2)


$(BIN_TARGET1):$(OBJ)
	$(CC) $(CFLAGS) $(DIR_OBJ)/$(TARGET1).o $(DIR_OBJ)/cgic.o $(DIR_OBJ)/inirw.o -o $@
	
$(BIN_TARGET2):$(OBJ)
	$(CC) $(CFLAGS) $(DIR_OBJ)/$(TARGET2).o $(DIR_OBJ)/cgic.o $(DIR_OBJ)/inirw.o -o $@
    
$(DIR_OBJ)/%.o:$(DIR_SRC)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@

.PHONY:clean
clean:
	rm -f $(DIR_OBJ)/*.o
	rm -f $(DIR_BIN)/$(TARGET1).cgi
	rm -f $(DIR_BIN)/$(TARGET2).cgi

	