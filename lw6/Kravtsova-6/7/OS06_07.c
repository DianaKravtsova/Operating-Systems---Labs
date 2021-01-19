#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
printf("%d\n", getpid());
int *block;
int n = 100000;
int size = 1024*1024*256;

block = malloc(size);

printf("%p\n", block);

for(int i = 0; i < size / 4; i++)
{
block[i] = i;
}
sleep(1000);
}
