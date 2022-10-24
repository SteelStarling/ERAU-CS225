CollegeCourse.exe: main.o CollegeCourse.o
		g++ main.o CollegeCourse.o -o CollegeCourse.exe

CollegeCourse.o: CollegeCourse.cpp CollegeCourse.h Instructor.o Classroom.o
		g++ Instructor.o Classroom.o CollegeCourse.h CollegeCourse.cpp -o CollegeCourse.o

Classroom.o: Classroom.h Classroom.cpp
		g++ Classroom.h Classroom.cpp -o Classroom.o

Instructor.o: Instructor.h Instructor.cpp
		g++ Instructor.h Instructor.cpp -o Instructor.o