#include "Matrix.h"
#include "FileReader.h"

#include <iostream>
#include <fstream>
#include <cstring>

vector<string> split(const string& str, const string& sep)
{
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL)
    {
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

Matrix::Matrix()
{
	rows = 0;
	columns = 0;
};

Matrix::Matrix(const string& file)
{
	FileReader in(file);
	int count(0);
	rows = 0;
	columns = 0;;
	
	while (!in.endOfFile())
	{
		string line = in.readLine();

		if(count==0)
		{
			vector<string> dimensions = split(line, ", ");
			rows = atoi(dimensions.at(0).c_str());
			columns = atoi(dimensions.at(1).c_str());

			//cout << "\nthere are " << rows << " rows" << endl;
			//cout << "there are " << columns << " columns" << endl;
		}
		else
		{
			vector<string> numbers = split(line, ", ");
			vector<int> newRow;
			

			for(int j = 0; j < numbers.size(); j++)
			{
				//cout << numbers.at(j);
				newRow.push_back(atoi(numbers.at(j).c_str()));
			}

			values.push_back(newRow);
		}

		count++;
	}
}

int Matrix::get(int row, int column)
{
	int temp = 0;

	temp = values.at(row).at(column);

	return temp;
}

void Matrix::set(int row, int column, int value)
{
	values.at(row).at(column) = value;
}

int Matrix::getRows()
{
	return rows;
}

int Matrix::getColumns()
{
	return columns;
}

void Matrix::setDimensions(int r, int c)//only to be used with first constructor
{
	rows = r;
	columns = c;

	for(int i = 0; i < r; i++)
	{
		vector<int> row;
		
		for(int j = 0; j < c; j++)
		{
			//cout << j << endl;
			row.push_back(0);
		}

		values.push_back(row);
	}

}

void Matrix::printToFile()
{
	ofstream outputFile("MatrixTotal.txt");

	outputFile << getRows() << ", " << getColumns() << endl;
	for(int i = 0; i < getRows(); i++)
	{
		//cout << i << endl;
		for(int j = 0; j < getColumns(); j++)
		{
			//cout << values.at(i).at(j) << endl;
			outputFile << values[i][j];
			if(j < getColumns()-1)
			{
				outputFile << ", ";
			}
		}

		outputFile << endl;
	}

	outputFile.close();

}