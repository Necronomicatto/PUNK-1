main: main.o leitura.o processor.o sort.o saida.o
	cc -Wall main.o leitura.o processor.o sort.o saida.o -o main	

main.0: main.c
	cc -c -Wall main.c

leitura.o: leitura.c leitura.h
	cc -c -Wall leitura.c

processor.o: processor.c processor.h
	cc -c -Wall processor.c

sort.o: sort.c sort.h
	cc -c -Wall sort.c

saida.o: saida.c saida.h
	cc -c -Wall saida.c

clean:
	rm main main.o leitura.o processor.o sort.o saida.o