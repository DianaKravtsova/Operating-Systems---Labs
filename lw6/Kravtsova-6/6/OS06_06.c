#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main()
{
pid_t pid = getpid();
time_t startTime = clock();
for (int i = 1; i < 1000; i++)
{
sleep(1);
time_t iterationTime = clock() - startTime;
printf("%d - %d time: %ld\n", i, pid, iterationTime);
}
}
