CXX := g++
CXXFLAGS := -g -Wall -std=c++11 -O3

all:		Inspire2BibTeX

Inspire2BibTeX:	main.cpp inspire.h
			$(CXX) $(CXXFLAGS) -o Inspire2BibTeX main.cpp

clean:
		rm -rf Inspire2BibTeX
