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
	void makeDir(std::string s);//creates a new directory
	void help();//prints a list of supported commands

private:
	std::string cwd;//stores current working directory
	void findDirectory();//finds current directory upon start of program
	void findUpperDirectory(std::string s);//finds directory above current dir

};
#endif