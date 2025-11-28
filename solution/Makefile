all: ./main.out 
	echo "Compilation done"

./main.o: ./main.c 
	gcc -c ./main.c -o ./main.o

main.out: ./main.o 
	gcc ./main.o -o main.out

clean:
	rm -f *.o main.out

