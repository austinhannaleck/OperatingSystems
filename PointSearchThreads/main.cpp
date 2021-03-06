#include "pointFinder.h"

#include <iostream>
#include <cmath>
#include <limits>
#include <pthread.h>

using namespace std;

vector<Point> closest;

struct Params
{
	pointFinder p;
	int index;
};

double calculateDistance(Point a, Point b)
{
	double result = 0;

	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void * findClosestPoint(void * info)
{
	Params * pParams = (Params *) info;

	pointFinder& pFinder = pParams->p;
	int index = pParams->index;
	
	Point smallest;
	double distance = numeric_limits<double>::max();

	for(int i = (index*5000); i < (index*5000)+4999; i++)
	{
		double test = calculateDistance(pFinder.allPoints[i], pFinder.ref);

		if(test < distance)
		{
			distance = test;
			smallest = pFinder.allPoints[i];	
		}
	}

	//add smallest point to closest
	closest.push_back(smallest);
	
	return NULL;
}

void findClosest(vector<Point>& b, pointFinder p)
{
	Point smallest;
	double distance = numeric_limits<double>::max();

	for(int i = 0; i < 100; i++)
	{
		double test = calculateDistance(b[i], p.ref);
		if(test < distance)
		{
			distance = test;
			smallest = b[i];
		}
	}

	cout << "The closest point is " << smallest.x << " " << smallest.y <<
		" with a distance of " << distance << endl;
}

int main()
{
	pointFinder finder;
	finder.generatePoints();
	finder.getUserInput();

	//create threads
	for(int i = 0; i < 100; i++)
	{
		Params params;
		params.p = finder;
		params.index = i;

		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_t tid;

		pthread_create(&tid, &attr, findClosestPoint, &params);
		pthread_join(tid, NULL);		
	}

	//find closest point from vector of 100 closest points
	findClosest(closest, finder);
}