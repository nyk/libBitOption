CC = gcc
CFLAGS = -Wall -g
LFLAGS = 
BIN = test


all : ${BIN}

$(BIN) : test/test.o
	$(CC) $(LFLAGS) test.o -o ${BIN}

test/%.o: test/%.c
	$(CC) $(CFLAGS) -c $<

clean:
	del /Q /S *.o *.exe

test:
	.\$(BIN)
