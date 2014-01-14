CC=gcc
CFLAGS=

EXE=sudoku

OBJS=main.o sudoku.o

.PHONY: all clean $(EXE)

all: $(EXE)

$(EXE): $(OBJS)
	${CC} -o $(EXE) $(OBJS)

sudoku.o: sudoku.h
main.o: sudoku.h

clean:
	-rm -f ${EXE} $(OBJS) *~