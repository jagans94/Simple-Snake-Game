#include <iostream>
#include <Windows.h>s
// For Async Functions
#include <conio.h>
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
	y = height / 2;
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
			
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "X";
			else
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

	// Display Score
	cout << "Score: " << score << '\n';
	cout << endl;
}

void Input(){
	// Checks if keyboard is hit
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': 
			dir = LEFT; 
			break;  
		case 'd': 
			dir = RIGHT; 
			break;
		case 'w': 
			dir = UP; 
			break;
		case 's': 
			dir = DOWN; 
			break;
		case 'x': 
			gameOver = true; 	
			break;

		}
	}
}

void Logic(){
	// Switch directions
	switch (dir){
	case LEFT:	
		--x; 
		break;
	case RIGHT: 
		++x; 
		break;
	case UP:	
		--y; 
		break;
	case DOWN:	
		++y; 
		break;
	default: break;
	}
	// Hit the sides and Game Over!!
	if (x > width || x < 0 || y > height || y < 0)
		gameOver = true;
	// Eat the fruit to increase score
	if (x == fruitX && y == fruitY) {
		score += 1;
		// Fruit will be generated randomly on the map
		fruitX = rand() % width;
		fruitY = rand() % height;		
	}
}

int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(30);
	}
}