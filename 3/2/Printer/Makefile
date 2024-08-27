all: printer

main.o: printer.h  main.cpp

printer.o: printer.h printer.cpp

printer: main.o printer.o
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f printer *.o