MYMATRIX: mymain.o  mymatrix.o
	gcc -ansi -Wall -g mymain.o  mymatrix.o
mymain.o: mymain.c mymatrix.h
	gcc -c -ansi -Wall mymain.c -o mymain.o
mymatrix.o: mymatrix.c mymatrix.h
	gcc -c -ansi -Wall mymatrix.c -o mymatrix.o 

