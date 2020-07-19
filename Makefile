all : nbo_test

nbo_test: nbo.cpp
	g++ -o nbo_test nbo.cpp

clean: 
	rm -f nbo_test *.o