# Makefile для сборки проекта лабораторной работы #2, задача 3
student_app: src/main.o src/student.o
	gcc -o student_app src/main.o src/student.o

src/main.o: src/main.c include/student.h
	gcc -c src/main.c -o src/main.o

src/student.o: src/student.c include/student.h
	gcc -c src/student.c -o src/student.o

clean:
	rm -f src/*.o student_app
