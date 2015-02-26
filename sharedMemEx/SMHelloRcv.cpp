#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
	int segment_id  = atoi(argv[1]);//gets segment id
	char * pBuff = (char *) shmat(segment_id, NULL, 0);//casts segment id as char*, so process finds shared memory
	cout << "Child: " << pBuff << endl;//prints message left by parent

	sprintf(pBuff, "Hello from child pid %d!", getpid());//overwrite pbuff
	cout << "Child " << getpid() << " exiting" << endl;

	return 0;
}
