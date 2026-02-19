# Makefile для сборки проекта лабораторной работы #2, задача 3

student_app: obj/main.o obj/student.o
	gcc -o bin/student_app obj/main.o obj/student.o

obj/main.o: src/main.c include/student.h
	gcc -c src/main.c -o obj/main.o

obj/student.o: src/student.c include/student.h
	gcc -c src/student.c -o obj/student.o

clean:
	rm -f obj/*.o bin/student_app

