#ifndef SEASHELL_H
#define SEASHELL_H

#include <iostream>
#include <string>

class Seashell
{
public:
	Seashell();
	void list();//lists contents of current directory
	void down(std::string s);//moves into specified child directory
	void up();//moves to the parent directory
	void wai();//shows current directory
	void help();//prints a list of supported commands
	void exit();//exits the shell

private:
	std::string cwd;
	void findDirectory();

};
#endif