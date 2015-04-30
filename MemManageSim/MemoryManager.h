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
	bool contains(int test);
	void printQueue();
	int lowest = 0;
	int size = 0;
	int page = 0;
	int pageFault = 0;


};

#endif