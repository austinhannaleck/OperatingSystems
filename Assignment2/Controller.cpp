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
#include <limits>

#include "utils.h"
#include "Controller.h"


using namespace std;

double utils::calculateDistance(Point a, Point b)
{
	int result = 0;

	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void Controller::generatePoints()
{
	for(int i = 0; i < 500000; i++)
	{
		allPoints[i].x = (int) rand() % 1000;//returns random number between 0 and 99
		allPoints[i].y = (int) rand() % 1000;

		//cout << allPoints[i].x << " " << allPoints[i].y << endl;
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

	//cout << "Your point is " << refPoint.x << " " << refPoint.y << endl; 
}

void Controller::calculatePoints(int& process, package * pBuff, int& c)
{
	int z = process;
	cout << z << endl;
	for(int i = (z*5000); i < ((pBuff->numPoints) * z) + 4999; i++)
	{
		
		pBuff->points[c] = allPoints[i];
		//cout << pBuff->points[c].x << " " << pBuff->points[c].y << endl;
		//cout << allPoints[i].x << " " << allPoints[i].y << endl;
		c++;
	}
}

int main()
{
	Controller c;
	c.getUserInput();

	//create a shared structure and seg_id for each process
	package shared[10];
	int segment_id[100];
	package * pBuff = NULL;
	int size = sizeof(shared[0]);

	//create spot in shared memory, and write data
	for(int i = 0; i < 100; i++)
	{
		segment_id[i] = shmget(IPC_PRIVATE, size, S_IRUSR | S_IWUSR);
		pBuff = (package *) shmat(segment_id[i], NULL, 0);
		pBuff->numPoints = 5000;
		pBuff->ref.x = c.getRefPoint().x;
		pBuff->ref.y = c.getRefPoint().y;
		int count(0);
		c.calculatePoints(i, pBuff, count);

		char arg[10];
		sprintf(arg, "%d", segment_id[i]);//arg contains segment id
		forkChild(arg);
		wait(NULL);
	}

	//add points to closest, then calculate closest point
	for(int i = 0; i < 100; i++)
	{
		package * pBuff = (package *) shmat(segment_id[i], NULL, 0);

		c.closestPoints[i] = pBuff->closest;

		//cout << c.closestPoints[i].x << " " << c.closestPoints[i].y << endl;
	}

	//calculate closest point
	double distance = numeric_limits<double>::max();
	Point smallest;

	for(int i = 0; i < 100; i++)
	{
		double test = utils::calculateDistance(c.closestPoints[i], c.getRefPoint());
		if(test < distance)
		{
			distance = test;
			smallest = c.closestPoints[i];
		}
	}

	cout << "The closest point is " << smallest.x << " " << smallest.y <<
		" with a distance of " << distance << endl;

}