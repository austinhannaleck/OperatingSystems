#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <iostream>

#include <stdlib.h>
#include <math.h>

#include "utils.h"
#include "Controller.h"


using namespace std;

Point* generatePoints(const int& arraySize)
{
	Point * temp[arraySize];
	for(int i = 0; i < arraySize; i++)
	{
		temp[i]->x = (int) rand % 100;//returns random number between 0 and 99
		temp[i]->y = (int) rand % 100;

		cout << temp[i]->x << endl;
		cout << temp[i]->y << endl;
	}

	return * temp;
}

Controller::Controller()  
{
	allPoints = generatePoints(10);
}

Point Controller::getRefPoint()
{
	return refPoint;
}

void forkChild(const string& num)
{
	pid_t pid = 0;
	pid = fork();

	if(pid < 0)
	{
		cout << "Fork failed" << endl;
		exit(-1);
	}

	if(pid == 0)
	{
		execl("./Child.o", "Child.o", num.c_str(), NULL);
		cout << "Error calling execl" << endl;
	}
}

void getUserInput()
{
	int x, y;
	
	cout << "Enter the X position of your point: ";
	cin >> x;
	cout << "\nEnter the Y position of your point: ";
	cin >> y;

	cout << "Your point is " << x << " " << y << endl; 

	refPoint.x = x;
	refPoint.y = y;
}

int main()
{

	//Controller c;

	// int x, y;
	
	// cout << "Enter the X position of your point: ";
	// cin >> x;
	// cout << "\nEnter the Y position of your point: ";
	// cin >> y;

	// cout << "Your point is " << x << " " << y << endl; 

	// refPoint->x = x;
	// refPoint->y = y;

	
}

