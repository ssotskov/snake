#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>

const int MAXLENGTH = 1000;			//Maximum length of snake

struct point
{
	int x;
	int y;
};

class Member
{
protected:
	int x, y;	//position of current element
public:
	Member() { this->x = -1; this->y = -1; }					//default constructor
	Member(int x, int y) { this->x = x; this->y = y; }		//constructor
	void set_pos ( int x, int y ) { this->x = x; this->y = y; }		//it's obvious, isn't it?
	int get_x( ) { return x; }
	int get_y( ) { return y; }
	friend int isSnake( point );			//friend function
};

class Snake: public Member		//inheritance as it is
{
public:
	Snake( int, int );		//constructor
	int length;		//Length of snake = number of members
	int directon;	//current direction of snake 1 - up, 2 - down, 3 - left, 4 - right
	Member head;	//snake's head
	Member body[ MAXLENGTH - 1 ];	//snake's body ( length - 1 members)
};

class Field
{
public:
	point size;		//Unecpectable, Height and Width of field
	point food;		//Coordinates of food
	int isSnake( point );	//When randomly places food check is this field is empty(No member of snake there) 0 - no snake, 1 - snake
	int level;		//level of the game = speed of moving = time to sleep
	//int isEnd();		//check if the game ended in this turn(Snake eat itself, crashed into border and e.t.c.)
	void key_pressed( int );	//move the snake according to key pressed
	void show( );	//draw everything
	int score;		//result
	friend void start();
	friend point gen_food();
};

Snake::Snake(int a, int b) : Member(a, b)
{
}

int delay( int millisec )
{
	clock_t timesec;

	timesec = clock( );

	while( ( clock ( ) - timesec ) < millisec )
	{
	}

	return millisec;
}


int _tmain( int argc, _TCHAR* argv[] )
{
	/*
	start();
	while(1)
	{
		key_pressed();
		if(timer)
		{
			new_step();
			if(end)
				end();
		}
	}
	*/

	std::cout << "Hello!\n";
	delay(500);
	system("cls");
	std::cout << "Good bye!\n";
	delay(500);
	return 0;
}

