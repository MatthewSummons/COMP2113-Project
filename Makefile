FLAGS = -pedantic-errors -std=c++11 -g

Title_Screen.o: Title_Screen.cpp Title_Screen.hpp
			g++ $(FLAGS) -c $< -o $@

Save_Load.o: Save_Load.cpp Save_Load.hpp
			g++ $(FLAGS) -c $< -o $@

Story.o: Story.cpp Story.hpp
			g++ $(FLAGS) -c $< -o $@

Minigames.o: Minigames.cpp Minigames.hpp
			g++ $(FLAGS) -c $< -o $@

End_Screen.o: End_Screen.cpp End_Screen.hpp
			g++ $(FLAGS) -c $< -o $@

main.o: main.cpp Title_Screen.hpp Save_Load.hpp Story.hpp Minigames.hpp End_Screen.hpp
			g++ $(FLAGS) -c $<

GAME: main.o Title_Screen.o Save_Load.o Story.o Minigames.o End_Screen.o
			g++ $(FLAGS)  $^ -o $@

clean:
			rm -f *.o

.PHONY: clean