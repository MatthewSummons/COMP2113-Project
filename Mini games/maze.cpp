// maze game to collect crystals

#include <iostream>
using namespace std;

const char width = 20, height = 10;
char player = 'P';                  // player character
int posx = 1, posy = 1;
char action;

void playerMove ();

struct enemies
{
	char symbol;
	bool active;
	int x;
	int y;
};

char maze[height][width] = {

	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, //0
	{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#'}, //1
	{'#', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'}, //2
	{'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', '#', ' ', '#', '#', '#'}, //3
	{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#'}, //4
	{'#', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', '#', ' ', '#'}, //5
	{'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#'}, //6
	{'#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'}, //7
	{'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#'}, //8
	//0     1     2    3    4    5    6    7    8    9    0    1    2    3    4    5    6    7    8    9
};

int main() 
{

	while (action != 'Q' || 'q')
	{	cout << endl;
		cout << "Press WASD to move... " << endl;
		cout << endl;

	maze[posx][posy] = player;

	for (int y0 = 0; y0 < height; y0++){             // runs 2d array
	 	cout << endl;
		for (int x0 = 0; x0 < height; x0++)
		{
			cout << maze[y0][x0];
		}

		//1st enemy 
	enemies enemy1;
	enemy1.symbol = 'L';
	enemy1.active = true;
	enemy1.x = 3;
	enemy1.y = 6;
	maze[enemy1.y][enemy1.x] = enemy1.symbol;
		//2nd enemy
	enemies enemy2;
	enemy2.symbol = 'I';
	enemy2.active = true;
	enemy2.x = 8;
	enemy2.y = 1;
	maze[enemy2.y][enemy2.x] = enemy2.symbol;

		//3rd enemy
	enemies enemy3;
	enemy3.symbol = 'E';
	enemy3.active = true;
	enemy3.x = 6;
	enemy3.y = 6;
	maze[enemy3.y][enemy3.x] = enemy3.symbol;
	
	}

	playerMove();
	}

	return 0;
}

	void playerMove()
	{
		cout << "\nYour move: ";
		cin >> action;

		int prevposx = posx;
		int prevposy = posy;
		char space = ' ';                  // ASCII for space

		switch (action)	
	{
		case 'a':
			if (maze [posx][posy - 1] != '#') {      // future position is not hash
				posy--;
	//		cout << posx << ',' << posy << endl;
			maze[prevposx][prevposy] = space;}
		system("cls");
		break;

		case 'd':
			if (maze [posx][posy + 1] != '#'){
				posy++;
	//		cout << posx << ',' << posy << endl;
			maze[prevposx][prevposy] = space;}
		system("cls");
		break;

		case 's':
			if (maze [posx + 1][posy] != '#'){
				posx++;
	//		cout << posx << ',' << posy << endl;
			maze[prevposx][prevposy] = space;}
		system("cls");                               // system clear screen to redraw maze
		break;

		case 'w':
			if (maze [posx - 1][posy] != '#'){
				posx--;
	//		cout << posx << ',' << posy << endl;
			maze[prevposx][prevposy] = space;}
		system("cls");
		break;

		default :
		cout << "Incorrect action... try a valid key" << endl;
		break;


		}


}