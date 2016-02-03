#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    time_t start = time(NULL);
    printf("time = %s\n", ctime(&start));
    return 0;
}
