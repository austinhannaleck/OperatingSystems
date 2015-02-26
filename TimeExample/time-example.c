#include <stdio.h>
#include <sys/time.h>

double timedif(struct timeval start, struct timeval end);

int main()
{
    struct timeval start;
    struct timeval end;
    
    gettimeofday(&start, NULL);

	// do lengthy operation here...
	
    gettimeofday(&end, NULL);
    printf("running time = %f\n", timedif(start, end));
}

double timedif(struct timeval start, struct timeval end)
{
    float time1 = start.tv_sec * 1000000 + start.tv_usec;
    float time2 = end.tv_sec * 1000000 + end.tv_usec;
    return (time2 - time1) / 1000000;
}