#include <fstream>
#include <iostream>
#include <string>

#include <stdlib.h>

using namespace std;

int main(int argc, char * argv[])
{
    string filename = string("output") + argv[1] + string(".txt");
    int num = atoi(argv[1]);

    ofstream output;
    output.open(filename.c_str());
    if (output.is_open())
    {
        cout << "num is " << num << endl;
        for (int i = (num * 10000); i < ((num+1) * 10000); i++)
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
    