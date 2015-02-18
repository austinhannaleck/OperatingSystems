#include <sys/types.h>//includes a lot of types for system calls
#include <unistd.h>//more system calls
#include <iostream>

int main()
{
	//creating a new child process
	//pid_t is a type
	//fork is the Linux command for the program running
	//to create an exact copy child process of itself
	pid_t pid = fork();

	//by using an if statement and identifying by pid, we can make the parent
	//and child run different code
	if(pid == 0)//for the process that calls fork, it's pid is 0
	{
		//getpid() returns it's own pid, can be used by any program
		std::cout << std::endl << "Bugger boo to you too from " 
		<< getpid() << std::endl;
	}
	else//the child gets it's real pid back 
	{
		std::cout << std::endl << "Peanut butter ice cream from " 
		<< getpid() << std::endl;
	}

	//getpid() returns it's own pid, can be used by any program
	// std::cout << std::endl << "Hello from " 
	// 	<< getpid() << std::endl;

}