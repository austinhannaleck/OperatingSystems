#include "MemoryManager.h"

MemoryManager::MemoryManager(const string& file)
{
	try
	{
		FileReader in(file);

		while(!in.endOfFile())
		{
			string line = in.readLine();
			int size = line.length();

			//add each number to map
			for(int i = 0; i < size; i++)
			{
				int number = stoi(line.substr(0,1));
				line = line.substr(1);
				add(number);
				cout << number << endl;
			}
		}
	}
	catch(string err)
	{
		cout << "Error: " << err << endl;
	}

}

void MemoryManager::add(int number)
{

}

void MemoryManager::remove()
{

}