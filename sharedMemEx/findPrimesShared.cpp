#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <iostream>

using namespace std;

	int main()
	{
		int segment_id = 0;
		int * pBuff = NULL;
		const int size = 20000;
	
	//system call(make it private, size, read only)
	segment_id = shmget(IPC_PRIVATE, size, S_IRUSR | S_IWUSR);
	
	//need strings, so this makes a point in memory where we can read/write characters btween processes
	pBuff = (int *) shmat(segment_id, NULL, 0);//pointer to array of characters. (char *) type casting
	
	pid_t pid = 0;
	pid = fork();

	if (pid < 0)
	{
		cout << "Fork failed" << endl;
		return -1;
	}

	if (pid == 0)
	{
		char arg[10];
		sprintf(arg, "%d", segment_id);//arg contains segment id
		execl("./findPrimes.out", "findPrimes.out", arg, NULL);
		cout << "Error calling execl" << endl;
		return -1;
	}
	
	cout << "Parent waiting..." << endl;
	wait(NULL);

	cout << "Parent: " << pBuff << endl;//parent prints what child wrote
	cout << "Parent Exiting" << endl;
	
	//these two sections clean up shared memory
	shmdt(&segment_id);

	shmctl(segment_id, IPC_RMID, NULL);
	
	return 0;
}
