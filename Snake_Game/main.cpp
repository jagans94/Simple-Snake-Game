#include <iostream>
#include <Windows.h>s
// For Async Functions
#include <conio.h>
#include <algorithm>
using namespace std;

bool gameOver;
int speed = 30;
// Screen Dimensions
const int width = 40, height = 20;
// Coordinates for Snake and Fruits
int x, y, fruitX, fruitY, score;
// Tail Coordinates
int tailX[100], tailY[100];
// Tail Length
int nTail;
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
			else {
				bool print = false;
				for (int k = 0; k < nTail; ++k) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "0"; print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	// Border for bottom wall
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;

	// Display Scored
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
		// Added speed control
		case '+':
			speed -= 10;
			break;
		case '-':
			speed += 10;
			break;
		case 'x': 
			gameOver = true; 	
			break;

		}
	}
}

void Logic(){

	// Tail Logic
	int prevX = tailX[0], prevY = tailY[0];
	tailX[0] = x; tailY[0] = y;
	for (int i = 1; i < nTail; ++i) {
		swap(tailX[i], prevX);
		swap(tailY[i], prevY);
	}
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
		// Increase the tail length and score by 1
		nTail += 1;
		score += 1;
		// Fruit will be generated randomly on the map
		fruitX = rand() % width;
		fruitY = rand() % height;		
	}

	// Speed logic
	if (speed > 300)
		speed = 300;
	else if (speed < 0)
		speed = 0;
}

int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(speed);
	}
}