#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	cout << "Child is writing to output.txt" << endl;
    ofstream output;
    output.open("output.txt");
    if (output.is_open())
    {
        for (int i = 1; i < 10000; i++)
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
                output << i << endl;
            }
            
        }
    }
    else 
    {
        cout << "file not found" << endl;
    }
    output.close();
}
    