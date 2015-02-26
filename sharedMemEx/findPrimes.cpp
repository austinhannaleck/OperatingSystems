#include <fstream>
#include <iostream>
#include <string>

#include <stdlib.h>

using namespace std;

int main(int argc, char * argv[])
{
    #include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
    int segment_id  = atoi(argv[1]);//gets segment id
    int * pBuff = (int *) shmat(segment_id, NULL, 0);//casts segment id as char*, so process finds shared memory

        for (int i = 0; i < 1000); i++)
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
               sprintf(pBuff, test);
            }
            
        }

    cout << "Child " << getpid() << " exiting" << endl;

    return 0;
}

    //     for (int i = (num * 10000); i < ((num+1) * 10000); i++)
    //     {

    //         bool prime = true;

    //         for(int j = i-1; j > 1; j--)
    //         {
    //             int test = i%j;
    //             if(test == 0)
    //             {
    //                 prime = false;
    //                 break;
    //             }
    //         }

    //         if(prime)
    //         {
    //             output << i << endl;
    //         }
            
    //     }
    // }

    