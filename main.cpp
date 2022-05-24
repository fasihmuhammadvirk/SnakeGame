#include <iostream>
#include <conio.h>//FOR INPUT OUTPUT PURPOSE
#include <windows.h>//FOR FUNCTIONS IN WINDOWS API 
using namespace std;
//GLOBALLY DECLARE VARIBALE 
bool gameover;
const int width = 20, height = 20;
int goback, choice, mood, x, y, fruitx, fruity, score;
int tailx[100], taily[100];
int ntail;
enum  eDirection { STOP = 0, RIGHT, LEFT, DOWN, UP };
eDirection  dir;
//FUNCTION TO CHOOSE A MODE 
int mode(int mood)
{


	switch (mood) {
	case 1:

		//WHEN HEAD COLLIDES WITH THE WALL PASS TO THE OTHER SIDE AND COME OUT FROM THE PARALLEL WALL 

		if (x >= width)x = 0; else if (x < 0)x = width - 1;
		if (y >= height)y = 0; else if (y < 0)y = height - 1;

		break;
	case 2:

		//WHEN THE HEAD COLLIDES WITH THE WALL ITS GAME OVER 

		if (x > width || x<0 || y>height || y < 0)
			gameover = true;
	}
	return mood;
}
//FUNCTION TO GENERATE THE FRUIT 
void setup()
{
	gameover = false;
	//DEFINING VALUE OF X AND Y 
	x = width / 2;
	y = height / 2;
	srand(time(10));
	//GENERATION RANDOM FRUIT POSITION 
	fruitx = rand() % width;
	fruity = rand() % height;
	score = 0;

}
//FUCTION TO DRAW THE WALLS IN THE GAME AND HEAD OF THE SNAKE AND THE OTHER BODY OF SNAKE  
void draw()
{
	system("cls");//FOR CLEARING THE SCREEN 
	//using loops for displaying everthing on screen from walls to the head and tail if the snake 
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruity && j == fruitx)
				cout << "*";
			else
			{
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{
					if (tailx[k] == j && taily[k] == i)
					{
						cout << "o";
						print = true;
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

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score = " << score << endl;
}
//FUNCTION TO TAKE INPUT CONTROL FROM THE USER 
void input()
{
	//for controls 
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameover = true;

		}
	}

}
//FUNCTION TO APPLY LOGIC 
void logic()
{

	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	//LOOP FOR TAIL TO FOLLOW THE HEAD 
	for (int i = 1; i < ntail; i++)
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	//FOR CHANGING THE DIREXTION OF THE SNAKE HEAD 
	switch (dir)
	{
	case RIGHT:
		x++;
		break;
	case LEFT:
		x--;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	//FOR MODE 
	mode(mood);
	for (int i = 0; i < ntail; i++)
		if (tailx[i] == x && taily[i] == y)
			gameover = true;
	//FOR INCRMENTING THE SCORE AND GENERATING NEW FRUIT POSITION 
	if (x == fruitx && y == fruity)
	{
		score += 10;
		srand(time(0));
		fruitx = rand() % width;
		fruity = rand() % height;
		ntail++;
	}
}
// MAIN FUNCTION 
int main()
{
back:
	//MAIN MENU 
	cout << "\t\t\t\t~WELCOME~ :)\n";
	cout << "\t\t  ____________________________________ \n"
		"\t\t |              MAIN MENU             | \n"
		"\t\t |             -----------            | \n"
		"\t\t |             ~ SNAKE GAME ~         | \n"
		"\t\t |                                    | \n"
		"\t\t |            1.  PLAY (default mode) | \n"
		"\t\t |                                    | \n"
		"\t\t |            2.  MODE                | \n"
		"\t\t |                                    | \n"
		"\t\t |            3.  EXIT                | \n"
		"\t\t |                                    | \n"
		"\t\t |            4.  CONTROLS            | \n"
		"\t\t |____________________________________| \n\n\n"
		"\n";

	cout << "\t\t\tENTER ->>";	cin >> choice;
	// FOR SELECTING A MODE 
	if (choice == 2)
	{


		cout << "\t\tCHOOSE A MODE FOR THE GAME\n"
			<< "\t\tAVAILABLE MODE ARE TWO\n"
			<< "\t\tPRESS 1 FOR NO WALLS\n"
			<< "\t\tPRESS 2 FOR  WALLS\n";
		cin >> mood;
		mode(mood);
		setup();
		while (!gameover)
		{
			draw();
			input();
			logic();
			Sleep(10);
		}
		cout << "\t\tGame End" << endl;
		cout << "\t\tYour Total Score is = " << score << endl;
	}

//FOR DEFAULT MODE AND START GAME  GAME 
	else if (choice == 1)
	{
		mood = 1;
		mode(mood);
		setup();
		while (!gameover)
		{
			draw();
			input();
			logic();
			Sleep(10);
		}
		cout << "Game End" << endl;
		cout << "Your Total Score is = " << score << endl;


	}
	else if (choice == 3)
	{
		score = 0;
		cout << "\tGame End" << endl;
		cout << "\tYour Total Score is = " << score << endl;
		exit;

	}
	else if (choice == 4)
	{
		//SHOWING CONTROLS ON KEYBOARD 
		cout << endl;
		cout << "\t\t\t |           KEYBOARD          |\n"
			"\t\t\t |-----------------------------|\n"
			"\t\t\t |  |   |   |    |   |   |   | |\n"
			"\t\t\t |-----------------------------|\n"
			"\t\t\t |  |   | w |    |   |   |   | |\n"
			"\t\t\t |-----------------------------|\n"
			"\t\t\t |  | a | s | d  |   |   |   | |\n"
			"\t\t\t |-----------------------------|\n"
			"\t\t\t |  |   | x |    |   |   |   | |\n"
			"\t\t\t |-----------------------------|\n"
			"\t\t\t |          |        |         |\n"
			"\t\t\t |-----------------------------|\n"
			"\t\t\t |_____________________________|\n";
		cout << "\t\t\t\t~Controls~";
		cout << "\t\t\t\t |w = \"up\"   |\n"
			"\t\t\t\t |s = \"down\" |\n"
			"\t\t\t\t |a = \"left\" |\n"
			"\t\t\t\t |d = \"right\"|\n"
			"\t\t\t\t |x = \"EXIT\" |\n";
		cout << endl;
		cout << "\t\t\tPRESS 1 to GoBack ->>"; cin >> goback;
		cout << endl;
		if (goback == 1)
		{
			goto back;
		}
	}
	

}
