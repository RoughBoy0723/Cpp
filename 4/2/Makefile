all: namecard

main.o: namecard.h  main.cpp

namecard.o: namecard.h namecard.cpp

namecard: namecard.o main.o
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f namecard *.o