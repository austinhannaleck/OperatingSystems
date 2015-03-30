#include <pthread.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int iglobal = 100;

struct Params
{
	int i1;
	int i2;
};
void * doSomething(void * info)//void can take any parameter, return any type
{
	Params * pI = (Params *)info;//type cast whats being passed in
	for (int i = 0; i < 10; i++)
	{
		iglobal = iglobal + 1;
		int sum = pI->i1 + pI->i2;
		cout << "thread calculated " << sum << endl;
		cout << "iglobal = " << iglobal << endl;
		sleep(1);//puts thread into waiting period
	}
	return NULL;
}

int main()
{
	pthread_attr_t attr;//asks OS for attribute (attr)
	pthread_attr_init(&attr);//gets address of attr structure.. initialized attr

	cout << "in main thread, creating new thread" << endl;
	//creates unique id for thread
	pthread_t tid1;
	pthread_t tid2;
	Params info1;
	info1.i1 = 10;
	info1.i2 = 20;
	Params info2;
	info2.i1 = 2;
	info2.i2 = 2;
	//pass id, attr, code to run, and paramters of code
	pthread_create(&tid1, &attr, doSomething, &info1);
	pthread_create(&tid2, &attr, doSomething, &info2);
	cout << "new thread created..." << endl;
	cout << "waiting for thread to end" << endl;
	pthread_join(tid1, NULL);//waits for thread to run before continuing main
	pthread_join(tid2, NULL);
	cout << "ok, thread is doing running" << endl;
}