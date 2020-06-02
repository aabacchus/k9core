# This makefile is BSD compatiable: You can run it without gmake on most systems

CC = cc

compile:
	$(CC) -c *.c
	$(CC) -o cat 	cat.o
	$(CC) -o dirname 	dirname.o
	$(CC) -o echo 	echo.o
	$(CC) -o ln	ln.o
	$(CC) -o mkdir	mkdir.o
	$(CC) -o pwd	pwd.o
	$(CC) -o rmdir	rmdir.o
	$(CC) -o touch	touch.o
	$(CC) -o yes	yes.o

clean:
	rm *.o cat dirname echo ln mkdir pwd rmdir touch yes

.PHONY: clean objclean compile
