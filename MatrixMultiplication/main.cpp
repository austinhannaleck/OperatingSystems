#include "Matrix.h"
#include "FileReader.h"

#include <iostream>
#include <pthread.h>

using namespace std;

Matrix total;

struct Matrices
{
	Matrix m1;
	Matrix m2;
	int id;
};

void * addMatrices(void * info)//void can take any parameter, return any type
{
	Matrices * pMatrices = (Matrices *) info;
	Matrix a = pMatrices->m1;
	Matrix b = pMatrices->m2;
	//Matrix c = pMatrices->result;

	//cout << a.getRows() << endl;

	int index = pMatrices->id;

	//should print 0-3, but sometimes it doesnt print anything or prints
	//"random" numbers (usually '2' or '3')
	cout << index << endl; 


	//code below for calculating resulting matrix
	

	// for(int i = 0; i < a.getRows(); i++)
	// {
	// 	int num = a.get(index, i) * b.get(i, index);

	// 	sum = sum + num;

	// 	if(i == (a.getRows()-1))
	// 	{
	// 		//cout << sum << endl;
	// 		c.set(index, (i%a.getRows()), sum);
	// 	}
	// }
	
	
	return NULL;
}

int main()
{
	string input1;
	string input2;

	cout << "Welcome to the matrix multipler!" << endl 
		<< "\nPlease enter the name of your first matrix: ";

	// cin >> input1;

	// cout << "Please enter the name of your second matrix: ";

	// cin >> input2;

	// cout << "\nYour first file is " << input1 << " and your second file is " 
	// 	<< input2 << endl;

	Matrix ma1("matrix1.txt");//input1
	Matrix ma2("matrix2.txt");//input2

	//set dimensions of total
	total.setDimensions(ma1.getRows(), ma2.getColumns());

	if(ma1.getRows() == ma2.getColumns())
	{
		// will have m1 rows and m2 columns

		for(int i = 0; i < (ma1.getRows() * ma2.getColumns()); i++)
		{
			Matrices matrices;
			matrices.m1 = ma1;
			matrices.m2 = ma2;
			matrices.id = i;

			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_t tid = i;

			

			pthread_create(&tid, &attr, addMatrices, &matrices);

			cout << "i is " << matrices.id << endl;//this works
		}
	}
	else
	{
		cout << "Matrices cannot be added together" << endl;
	}

	//total.printToFile();



}