BIN := main
SOURCES := calc.c
C := PWD


$(BIN): $(SOURCES)
		gcc -fPIC $(SOURCES) -c
		gcc -fPIC *.c -c 
		gcc -shared *.o -o libcalc.so 
		gcc calc.o -o $(BIN) -ldl -Wl,-rpath,.
		
				
clean:
		rm -rf *.o
		rm -rf $(BIN)
		rm -rf libcalc.so