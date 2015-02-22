#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/time.h>
#include <time.h>

#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>

using namespace std;

double timedif(struct timeval start, struct timeval end)
{
	float time1 = start.tv_sec * 1000000 + start.tv_usec;
	float time2 = end.tv_sec * 1000000 + end.tv_usec;
	return (time2 - time1) / 1000000;
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
		execl("./findPrimes.out", "findPrimes.out", num.c_str(), NULL);
		cout << "Error calling execl" << endl;
	}
}

	int main()
	{
		struct timeval start;
		struct timeval end;

		gettimeofday(&start, NULL);

		//parallel - often inneficient (overhead)
		forkChild("0");
		forkChild("1");
		wait(NULL);
		wait(NULL);

		gettimeofday(&end, NULL);
		cout << "running time = " << timedif(start, end) <<endl;

		gettimeofday(&start, NULL);

		forkChild("0");
		wait(NULL);
		forkChild("1");
		wait(NULL);

		gettimeofday(&end, NULL);
		cout << "running time = " << timedif(start, end) << endl;
	}
