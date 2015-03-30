#include "Matrix.h"
#include "FileReader.h"

#include <iostream>
#include <fstream>

Matrix::Matrix(const string& file)
{
	FileReader in(file);
	
	while (!in.endOfFile())
	{
		string line = in.readLine();
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