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
void * doSomething(void * num)//void can take any parameter, return any type
{
	Params * pI = (Params *)num;//type cast whats being passed in
	for (int i = pI->i2; i < pI->i1; i++)
        {

            bool prime = true;

            for(int j = i-1; j > 1; j--)
            {
                int test = i%j;
                if(test == 0)
                {
                    prime = false;
                    break;
                }
            }

            if(prime)
            {
                cout << i << endl;
            }
            
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
	Params number;
	number.i1 = 100;
	number.i2 = number.i1/2;
	//pass id, attr, code to run, and paramters of code
	pthread_create(&tid1, &attr, doSomething, number);
	pthread_create(&tid2, &attr, doSomething, number);
	cout << "new thread created..." << endl;
	cout << "waiting for thread to end" << endl;
	pthread_join(tid1, NULL);//waits for thread to run before continuing main
	pthread_join(tid2, NULL);
	cout << "ok, thread is doing running" << endl;
}