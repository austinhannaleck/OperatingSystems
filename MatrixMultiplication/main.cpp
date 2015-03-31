#include "Matrix.h"
#include "FileReader.h"

#include <iostream>
#include <pthread.h>

using namespace std;


Matrix matrix1();
Matrix matrix2();

struct Matrices
{
	Matrix m1;
	Matrix m2;
	Matrix result;
	int id;
};

void * doSomething(void * info)//void can take any parameter, return any type
{
	Matrices * pMatrices = (Matrices *) info;
	Matrix a = pMatrices->m1;
	Matrix b = pMatrices->m2;
	Matrix c = pMatrices->result;

	cout << (a.getRows() * b.getColumns()) << endl;

	int index = pMatrices->id;//doesnt return actual thread id

	cout << index << endl;
	int sum = 0;

	for(int i = 0; i < a.getRows(); i++)
	{
		int num = a.get(index, i) * b.get(i, index);

		sum = sum + num;

		if(i == (a.getRows()-1))
		{
			//cout << sum << endl;
			c.set(index, (i%a.getRows()), sum);
		}
	}
	
	
	return NULL;
}

Matrix addMatrices(Matrix ma1, Matrix ma2)
{
	Matrices matrices;
	// Matrices matrices;
	// matrices.m1 = ma1;
	// matrices.m2 = ma2;
	if(ma1.getRows() == ma2.getColumns())
	{
		// will have m1 rows and m2 columns
		// Matrix result();

		cout << (ma1.getRows() * ma2.getColumns()) << endl;

		for(int i = 0; i < (ma1.getRows() * ma2.getColumns()); i++)
		{

			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_t tid = i;

			//Matrices matrices;
			matrices.m1 = ma1;
			matrices.m2 = ma2;
			matrices.id = i;

			pthread_create(&tid, &attr, doSomething, &matrices);
		}
	}
	else
	{
		cout << "Matrices cannot be added together" << endl;
	}

	return matrices.result;
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

	Matrix m("matrix1.txt");//input1
	Matrix n("matrix2.txt");

	Matrix r = addMatrices(m, n);
	r.printToFile();

	//int test = m.get(1, 0);

	//cout << test << endl;



}