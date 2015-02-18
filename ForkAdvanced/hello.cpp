#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	cout << "Child is wrting to output.txt" << endl;
    ofstream output;
    output.open("output.txt");
    if (output.is_open())
    {
        for (int i = 0; i < 10; i++)
        {
            output << i << endl;
        }
    }
    else 
    {
        cout << "file not found" << endl;
    }
    output.close();
}
    
