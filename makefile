CXX = g++ -std=c++14
CXXFLAGS=-Wall

frac:		mainFrac.o frac.o
	$(CXX) mainFrac.o frac.o -o mainFrac.exe
mainFrac.o:	mainFrac.cc frac.h
	$(CXX) -c mainFrac.cc $(CXXFLAGS)
frac.o:	frac.cc frac.h
	$(CXX) -c frac.cc $(CSSFLAGS)
matrix:	matrix.o
	$(CXX) matrix.o -o matrix.exe $(CXXFLAG)
clean:
	rm -rf *o *exe
