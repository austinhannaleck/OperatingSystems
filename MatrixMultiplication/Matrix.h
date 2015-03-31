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
	friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
	int getRows();
	int getColumns();
	//operator overload -> cout to print matrix

private:
	vector<vector<int>> values;
	int rows;
	int columns;
};

#endif
