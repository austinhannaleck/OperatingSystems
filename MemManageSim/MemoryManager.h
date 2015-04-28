#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "FileReader.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

class MemoryManager
{
public:
	MemoryManager(const string& file);
	//void add(Page& page);//make private or dont need at all


private:
	map<int, int> m_pages;
	void add(int number);
	void remove();


};

#endif