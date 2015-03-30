#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
	Matrix(const string& file);
	void printToFile();
	int get(int row, int column);
	void set(int row, int column, int value);
	//getSize?
		//get rows
		//get columns
	//operator overload -> cout to print matrix

private:
	vector<vector<int>> values;
	//could use a 2d vector instead
	//int values[][];


};

#endif
