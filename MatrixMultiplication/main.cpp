#include "Matrix.h"
#include "FileReader.h"

#include <iostream>
#include <pthread.h>
#include <cmath>

using namespace std;

Matrix total;

struct Matrices
{
	Matrix m1;
	Matrix m2;
	int i;
	int j;
};

void * addMatrices(void * info)//void can take any parameter, return any type
{
	Matrices * pMatrices = (Matrices *) info;
	Matrix a = pMatrices->m1;
	Matrix b = pMatrices->m2;

	int indexI = pMatrices->i;
	int indexJ = pMatrices->j;


	//cout << "index is " << indexI << endl; 

	//code below for calculating resulting matrix
	
	int sum = 0;


	for(int i = 0; i < a.getColumns(); i++)
	{


		
		int num = a.get(indexI, i) * b.get(i, indexJ);
		sum = sum + num;
		
		//cout << sum << endl;
		total.set(indexI, indexJ, sum);
		
	}
	
	return NULL;
}

int main()
{
	string input1;
	string input2;

	cout << "Welcome to the matrix multipler!" << endl 
		<< "\nPlease enter the name of your first matrix: ";

	cin >> input1;

	cout << "Please enter the name of your second matrix: ";

	cin >> input2;

	Matrix ma1(input1);//input1
	Matrix ma2(input2);//input2

	//set dimensions of total
	total.setDimensions(ma1.getRows(), ma2.getColumns());

	if(ma1.getColumns() == ma2.getRows())
	{
		cout << "\nCalculating total..." << endl;
		for(int i = 0; i < total.getRows(); i++)
		{

			for(int j = 0; j < total.getColumns(); j++)
			{
				Matrices matrices;;
				matrices.m1 = ma1;
				matrices.m2 = ma2;
				matrices.i = i;
				matrices.j = j;

				pthread_attr_t attr;
				pthread_attr_init(&attr);
				pthread_t tid;

				pthread_create(&tid, &attr, addMatrices, &matrices);
				pthread_join(tid, NULL);
			}
			
		}

		total.printToFile();

		cout << "Total printed to 'MatrixTotal.txt'" << endl; 
	}
	else
	{
		cout << "Matrices cannot be added together" << endl;
	}

}