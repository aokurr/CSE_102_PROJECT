program: lib test calıstır sonuc
lib:
	gcc -c ./header/lib.c -o ./implementation/lib.o
test:
	gcc -I "./header" -c ./implementation/test.c -o ./implementation/test.o
calıstır:
	gcc ./implementation/lib.o ./implementation/test.o -o ./implementation/program -lm
sonuc:
	./implementation/program
