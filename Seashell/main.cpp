#include "Seashell.h"
#include <iostream>
#include <string>

int main()
{
	Seashell s;
	std::cout << "Welcome to Seashell!" << std::endl;
	std::cout << "Seashell>";

	std::string input;
	std::getline(std::cin, input);
	while(input != "e" && input != "exit")
	{
		if(input == "w" || input == "wai")
		{
			s.wai();
		}

		else if(input == "l" || input == "list")
		{
			s.list();
		}
		

		else if((input.substr(0,1) == "d" && input.substr(1,1) == " ") || input.substr(0,4) == "down")//checks if first letter is d
		{
			if(input.substr(0,4) == "down")
			{
				s.down(input.substr(5));
			}
			else
			{
				s.down(input.substr(2));//reads desired change of directory after the space
			}
			
		}

		else if(input == "u" || input == "up")
		{
			s.up();
		}
		else if((input.substr(0, 1) == "m" && input.substr(1,1) == " ") || input.substr(0,7) == "makeDir")
		{
			
			if(input.substr(0,7) == "makeDir")
			{
				s.makeDir(input.substr(8));
			}
			else
			{
				s.makeDir(input.substr(2));
			}	
		}

		else
		{
			s.help();
		}

		std::cout << "Seashell>";
		std::getline(std::cin, input);
	}

	std::cout << "Bye" << std::endl;

}