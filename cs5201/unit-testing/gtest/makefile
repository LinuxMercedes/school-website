.PHONY:test clean

test: testsuite
	@./testsuite

testsuite: test_main.o test_apathy.o gtest/libgtest.a
	g++ -pthread $^ -o testsuite

test_main.o: test_main.cpp
	g++ -c test_main.cpp

test_apathy.o: test_apathy.cpp
	g++ -c test_apathy.cpp

gtest/libgtest.a:
	mkdir gtest
	cd gtest && cmake -DCMAKE_BUILD_TYPE=Release /usr/src/gtest && make

clean:
	-@rm -f *.o testsuite
	-@rm -rf gtest
