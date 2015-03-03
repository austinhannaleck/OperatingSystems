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

#include "utils.h"
#include "Controller.h"
#include "Child.h"


using namespace std;

Controller::Controller()  
{

}

Point Controller::getRefPoint()
{
	return Controller::refPoint;
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
		execl("./Child.out", "Child.out", num.c_str(), NULL);
		cout << "Error calling execl" << endl;
	}
}

int main()
{
	int x, y;
	
	cout << "Enter the X position of your point: ";
	cout << "\nEnter the Y position of your point: ";
}

