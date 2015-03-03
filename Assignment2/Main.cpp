#include "utils.h"
#include "Controller.h"
#include "Child.h"

#include <iostream>

using namespace std;

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
	int x, y;
	
	cout << "Enter the X position of your point: ";
	cout << "\nEnter the Y position of your point: ";
}