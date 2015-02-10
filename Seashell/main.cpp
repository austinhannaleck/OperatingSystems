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
	while(input != "e")
	{
		if(input == "w")
		{
			s.wai();
		}

		if(input == "l")
		{
			s.list();
		}
		
		if(input == "h")
		{
			s.help();
		}

		if(input.substr(0,1) == "d")//checks if first letter is d
		{
			s.down(input.substr(2));//reads desired change of directory after the space
		}

		if(input == "u")
		{
			s.up();
		}

		std::cout << "Seashell>";
		std::getline(std::cin, input);
	}

	std::cout << "Bye" << std::endl;

}