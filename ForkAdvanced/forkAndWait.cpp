#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	pid_t pid = 0;
	pid = fork();

	if (pid < 0)
	{
		cout << "Fork failed" << endl;
		return -1;
	}

	if (pid < 0)//if I'm the child, swap out my code
	{
		execl("./hello.o", "hello.o", NULL);
		cout << "Error calling execl" << endl;
	}
	else//the parent waits until the child is done
	{
		int status = 0;
		wait(&status);
		cout << "Child done, here is what it wrote to file" << endl;
		
	    ifstream input;
		input.open("output.txt");
		if (input.is_open())
		{
		    double num;
		    (input >> num).get();
		    while (input.good())
		    {   
		        cout << num << endl;
		        (input >> num).get();
		    }
		}
		else 
		{
		    cout << "file not found" << endl;
		}
		input.close();

	}
	return 0;
}
