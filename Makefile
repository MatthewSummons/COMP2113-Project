FLAGS = -pedantic-errors -std=c++11

Title_Screen.o: Title_Screen.cpp Title_Screen.hpp
			g++ $(FLAGS) -c $< -o $@

Save_Load.o: Save_Load.cpp Save_Load.hpp
			g++ $(FLAGS) -c $< -o $@

main.o: main.cpp Title_Screen.hpp Save_Load.hpp
			g++ $(FLAGS) -c $<

GAME: main.o Title_Screen.o Save_Load.o
			g++ $(FLAGS)  $^ -o $@

clean:
			rm -f *.o

.PHONY: clean