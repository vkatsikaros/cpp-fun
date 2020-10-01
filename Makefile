fun:
	g++ -std=c++11 -Wall -pthread fun.cpp -o fun

clean:
	$(RM) *.o

check:
	scan-build-10 make