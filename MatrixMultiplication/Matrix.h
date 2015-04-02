#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(const string& file);
	void printToFile();
	int get(int row, int column);
	void set(int row, int column, int value);
	int getRows();
	int getColumns();
	void setDimensions(int r, int c);

private:
	vector<vector<int>> values;
	int rows;
	int columns;
};

#endif
