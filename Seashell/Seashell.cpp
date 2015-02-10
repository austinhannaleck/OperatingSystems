#include "Seashell.h"
#include <iostream>

#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

Seashell::Seashell()
{
	findDirectory();
}
void Seashell::list()
{
	DIR *dp;
	struct dirent *dirp;
	dp = opendir(".");
	if(dp == NULL)
	{
		std::cout << "error opening current working directory" << std::endl;
	}
	else
	{
		dirp = readdir(dp);
		while(dirp != NULL)
		{
			if(std::string(dirp->d_name) != "." && std::string(dirp->d_name) != "..")
			{
				//stat(dirp, &fileStat);
				//bool isDir = S_ISDIR(fileStat.st_mode);
				//if(isDir == true)
				//{
					std::cout << "\t(d) " << dirp->d_name << std::endl;
				//}
				//else
				//{
					std::cout << "\t(f) " << dirp->d_name << std::endl;
				//}
				
				
			}
			dirp = readdir(dp);
		}
	}
	closedir(dp);
}

void Seashell::down(std::string s)
{
	std::cout << s << std::endl;
	std::string temp = cwd;
	temp += "/";
	temp += s;

	char myArray[temp.size()+1];
	strcpy(myArray, temp.c_str());

	std::cout << temp << std::endl;
	chdir(myArray);
}

void Seashell::up()
{
	//chdir();
}

void Seashell::wai()
{
	std::cout << cwd << std::endl;
}

void Seashell::help()
{
	std::cout << "(l)ist: lists the contents of current directory" << std::endl;
	std::cout << "(d)down [dir]: moves into the specified child directory" << std::endl;
	std::cout << "(u)p: moves to the parent directory" << std::endl;
	std::cout << "(w)ai: prints the current directory" << std::endl;
	std::cout << "(e)xit: exits the shell" << std::endl;
	std::cout << "(h)elp: prints a list of the supported commands" << std::endl;
}

void Seashell::exit()
{

}

void Seashell::findDirectory()
{
	char buff[PATH_MAX];
	cwd = getcwd(buff, PATH_MAX);

}