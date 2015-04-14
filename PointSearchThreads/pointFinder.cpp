#include "pointFinder.h"

#include <stdio.h>
#include <stdlib.h>

void pointFinder::getUserInput()
{
	int x, y;
	
	cout << "\nThis program finds the point closest to a user made point" <<
		"on a 1000x1000 grid." << endl;

	cout << "\nEnter the X coordinate of your point: ";
	cin >> x;
	cout << "Enter the Y coordinate of your point: ";
	cin >> y;

	ref.x = x;
	ref.y = y;
}

void pointFinder::generatePoints()
{
	cout << "Generating random points..." << endl;
	srand(time(0));
	for(int i = 0; i < 500000; i++)
	{
		//returns random number between 0 and 999
		allPoints[i].x = (int) rand() % 1000;
		allPoints[i].y = (int) rand() % 1000;
	}
}