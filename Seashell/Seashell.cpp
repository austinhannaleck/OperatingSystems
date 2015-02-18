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
				struct stat fileStat;
				stat(dirp->d_name, &fileStat);
				bool isDir = S_ISDIR(fileStat.st_mode);
				if(isDir == true)
				{
					std::cout << "\t(d) " << dirp->d_name << std::endl;
				}
				else
				{
					std::cout << "\t(f) " << dirp->d_name << std::endl;
				}
<<<<<<< HEAD
				
=======
>>>>>>> 41a1a0957aa5c35acdbf80a6f45ca211869eeb65
			}
			dirp = readdir(dp);
		}
	}
	closedir(dp);
}

void Seashell::down(std::string s)
{
	//makes a temporary string in case directory is not valid
	std::string temp = cwd;
	temp += "/";
	temp += s;


	//std::cout << temp << std::endl;
	if(chdir(temp.c_str()) == 0)
	{
		cwd = temp;
		std::cout << cwd << std::endl;
	}
	else
	{
		std::cout << "Error! " << s << " is not directory!" << std::endl;
	}
}

void Seashell::up()
{
	findUpperDirectory(cwd);
	std::cout << cwd << std::endl;
}

void Seashell::makeDir(std::string s)
{
	std::string newDir = cwd;
	newDir += "/";
	newDir += s;

	if(mkdir(newDir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0)
	{
		std::cout << "Directory succesfully created!" << std::endl;
		chdir(newDir.c_str());
		cwd = newDir;
	}
	else
	{
		std::cout << "Error, directory could not be created or it already exists" << std::endl;
	}

	std::cout << newDir << std::endl;
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
	std::cout << "(m)akeDir [dir]: creates a new directory" << std::endl;
	std::cout << "(e)xit: exits the shell" << std::endl;
	std::cout << "(h)elp: prints a list of the supported commands" << std::endl;
}

void Seashell::findDirectory()
{
	char buff[PATH_MAX];
	cwd = getcwd(buff, PATH_MAX);

}

void Seashell::findUpperDirectory(std::string s)
{
	
	if(s == "/home")
	{
		std::cout << "error! can't do that!" << std::endl;
	}
	else
	{
		for(int i = s.length(); i > 0; i--)
	{
		int pos = i-1;
		std::string temp = s.substr(i-1, i);
		if(temp.substr(0, 1) == "/")
		{
			s = s.substr(0, pos);
			cwd = s;
			chdir(cwd.c_str());
			break;
		}

	}
	}
}