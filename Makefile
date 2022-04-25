FLAGS = -pedantic-errors -std=c++11

Title_Screen.o: Title_Screen.cpp Title_Screen.h
			g++ $(FLAGS) -c $< -o $@

main.o: main.cpp Title_Screen.h
			g++ $(FLAGS) -c $<

GAME: main.o Title_Screen.o
			g++ $(FLAGS)  $^ -o $@

clean:
			rm -f *.o

.PHONY: clean