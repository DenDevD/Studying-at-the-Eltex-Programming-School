BIN	 := main
LIB := main_dynamic
LIB_SOURCES := division.c multiplication.c subtraction.c addition.c
SOURCES := calc.c division.c multiplication.c subtraction.c addition.c  
HEADERS := prototype.h

.PHONY: all
all: $(LIB) $(BIN) clean

$(LIB):$(LIB_SOURCES)
		gcc -fPIC $(LIB_SOURCES) -c
		gcc -shared -o lib$(LIB).so *.o

$(BIN) : $(SOURCES)
		gcc $(SOURCES) -o $(BIN)

$(BIN):prototype.h

.PHONY: clean

clean:
		rm -f *.o *.so
 