all: calculator

main.o: calculator.h  main.cpp

calculator.o: calculator.h calculator.cpp

calculator: main.o calculator.o
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f calculator *.o