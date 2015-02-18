#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <wait.h>

using namespace std;

int loop()
{
	for (int sec = 0; sec < 10; sec++)
	{
		cout << "greetings from pid " << getpid() << endl;
		//tells the OS you want to wait for a certain amount of time in the wait
		//area, then resume. in this case, sleep for 1 second
		sleep(1); 
	}
}

int main()
{
	pid_t pid = fork();
	if(pid == 0)//parent process
	{
		loop();
	}
	else
	{
		pid = fork();
		if(pid == 0)//if process is parent
		{
			loop();
		}
		else
		{
			pid = fork();
			if(pid == 0)
			{
				loop();
			}
			else
			{
				cout << "all forks are done" << endl;
			}
		}
	}
}