#include <iostream>

using namespace std;

bool gameOver;
// Screen Dimensions
const int width = 40, height = 20;
// Coordinates for Snake and Fruits
int x, y, fruitX, fruitY, score;
// Direction of the Snake
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void Setup(){
	dir = STOP;
	// Snakes head will be centered on the map
	x = width / 2;
	y = width / 2;
	// Fruit will be generated randomly on the map
	fruitX = rand() % width;
	fruitY = rand() % height;

	gameOver = false;
}

void Draw(){
	// Clears the screen
	system("cls");
	// Border for the top wall
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;

	// Create the map
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (j == 0)
				cout << "#";
			
			cout << " ";

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	// Border for bottom wall
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;

}

void Input(){

}

void Logic(){

}

int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		//Sleep(10);
	}
}