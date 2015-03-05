#include "utils.h"
#include "Child.h"

    #include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>

using namespace std;

Child::Child(int n, Point r, Point p[], Point c)
{
	xyz * data;
	data->numPoints = n;
 	data->ref = r;
	//data->points = p;
	data->closest = c;

}

int main(int argc, char * argv[])
{
	int num = atoi(argv[1]);

	int segment_id  = atoi(argv[1]);//gets segment id
	xyz pBuff = (xyz) shmat(segment_id, NULL, 0);//casts segment id as char*, so process finds shared memory
	//cout << "Child: " << pBuff << endl;//prints message left by parent

	//sprintf(pBuff, "Hello from child pid %d!", getpid());//overwrite pbuff
	//cout << "Child " << getpid() << " exiting" << endl;

	return 0;
}

