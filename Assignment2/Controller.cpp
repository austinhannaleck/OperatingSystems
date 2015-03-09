#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <iostream>

#include <stdlib.h>
#include <math.h>

#include <cstring>
#include <string>

#include "utils.h"
#include "Controller.h"


using namespace std;

void Controller::generatePoints()
{
	for(int i = 0; i < 100; i++)
	{
		allPoints[i].x = (int) rand() % 100;//returns random number between 0 and 99
		allPoints[i].y = (int) rand() % 100;

		cout << allPoints[i].x << " " << allPoints[i].y << endl;
	}
}

Controller::Controller()
{
	generatePoints();
}

Point Controller::getRefPoint()
{
	return refPoint;
}

Point* Controller::getAllPoints()
{
	return allPoints;
}

void forkChild(const char h[])
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
		execl("./Child.o", "Child.o", h, NULL);
		cout << "Error calling execl" << endl;
	}
}

void Controller::getUserInput()
{
	int x, y;
	
	cout << "Enter the X position of your point: ";
	cin >> x;
	cout << "Enter the Y position of your point: ";
	cin >> y;

	

	refPoint.x = x;
	refPoint.y = y;

	cout << "Your point is " << refPoint.x << " " << refPoint.y << endl; 
}

Point temp[0];

Point* Controller::calculatePoints(int& process)
{

	for(int i = 0; i < 100; i++)
	{
		temp[i] = allPoints[process];
	}

	cout << "COPIED VALUES" << endl;
	cout << temp[0].x << " " << temp[0].y << endl;;

	return temp;
}

int main()
{
	Controller c;
	c.getUserInput();

	//create a shared structure and seg_id for each process
	package shared[100];
	int segment_id[100];
	package * pBuff = NULL;
	int size = sizeof(shared[0]);
		//cout << "SIZE OF " << sizeof(size) << "." << endl;

	//create spot in shared memory, and write data
	for(int i = 0; i < 100; i++)
	{
		segment_id[i] = shmget(IPC_PRIVATE, size, S_IRUSR | S_IWUSR);
		pBuff = (package *) shmat(segment_id[i], NULL, 0);
		pBuff->numPoints = 100;
		pBuff->ref.x = c.getRefPoint().x;
		pBuff->ref.y = c.getRefPoint().y;
		pBuff->points = c.calculatePoints(i);

		char arg[10];
		sprintf(arg, "%d", segment_id[i]);//arg contains segment id
		forkChild(arg);
	}
	// char * pBuff = NULL;
	// const int size = 20;

	
}