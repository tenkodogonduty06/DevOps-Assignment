all: program

program: readXML.o tinyxml2.o
	g++ -o program readXML.o tinyxml2.o

readXML.o: readXML.cpp
	g++ -c readXML.cpp

tinyxml2.o: tinyxml2.cpp
	g++ -c tinyxml2.cpp

clean:
	rm readXML.o tinyxml2.o program