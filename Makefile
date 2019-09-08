a.out: main.o
	g++ -o a.out main.o

main.o: main.cpp
	g++ -c -o main.o main.cpp
excel:
	python openxl.py
clean :
	rm *.o
	rm *.txt
	rm *.out
#b.out: foo.o
#	g++ -o b.out foo.o
#
#foo.o: foo.cpp
#	g++ -c -o foo.o foo.cpp
