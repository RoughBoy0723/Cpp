all: point

main.o: point.h  main.cpp

point.o: point.h point.cpp

point: point.o main.o
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f point *.o