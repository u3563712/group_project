FLAGS = -pedantic-errors -std=c++11

choose.o:choose.cpp choose.h check_connection.h
	g++ $(FLAGS) -c $<
check_connection.o:check_connection.cpp check_connection.h
	g++ $(FLAGS) -c $<
create_area.o:create_area.cpp create_area.h
	g++ $(FLAGS) -c $<
main.o:main.cpp create_area.h check_connection.h choose.h
	g++ $(FLAGS) -c $<
main:main.o choose.o create_area.o check_connection.o
	g++ $(FLAGS) $^ -o $@
clean:
	rm -f main.o create_area.o check_connection.o choose.o
.PHONY:clean
