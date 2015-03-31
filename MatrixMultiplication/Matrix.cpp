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

Matrix::Matrix(){};

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

			cout << "\nthere are " << rows << " rows" << endl;
			cout << "there are " << columns << " columns" << endl;
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
			cout << endl;
		}

		count++;
	}
}

void Matrix::printToFile()
{
	ofstream outputFile("MatrixTotal.txt");

	// for(int i = 0; i < imageData.size(); i++)
	// {
	// 	//print contents of matrix (values[][]) to a text file
	// 	//outputFile << imageData.at(i) << endl;
	// }

	outputFile.close();

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

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
	// for (vector<string>::const_iterator it = m.values.cbegin(); 
	// 		it!=m.values.cend(); it++)
	// {
	// 	os << *it << " ";
	// }
	// os << endl;
	return os;
}