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
				//cout << number << endl;
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
	cout << "loading " << number << endl;

	if(!contains(number))
	{
		if(size < 5)//put this only if map doesnt have number
		{
			m_pages.insert(pair<int, int> (number, page));
			size++;
			page++;
			pageFault++;
			cout << "page fault" << endl;
		}
		else
		{
			//eject lowest
			cout << "fifo ejecting " << lowest << endl;
			remove();
			m_pages.insert(pair<int, int> (number, page));
		}
	}
	else
	{
		cout << "page already loaded" << endl;
	}
	

	//cout << m_pages[size] << endl;;


	
}

void MemoryManager::remove()
{
	m_pages.erase(lowest);
	lowest++;
}

bool MemoryManager::contains(int test)
{

}

void MemoryManager::printQueue()
{
	for(auto it = m_pages.begin(); it != m_pages.end(); it++)
	{
		cout << (*it) << endl;
	}
}