all: devise.o
	gcc -o d devise.o
main.o: devise.c
	gcc -c devise.c
run:
	./d
clean:
	rm -rf *.o
	rm -rf *.txt