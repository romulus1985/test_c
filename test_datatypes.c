#include <stdio.h>
int main(int argc, char** argv)
{
    printf("%s enter.\n", __func__);
    unsigned short year = 2016;
    printf("year = %u\n", year);
    unsigned short year2 = year * 10000;
    printf("year2 = %u\n", year2);
    int year3 = year * 10000;
    printf("year3 = %d\n", year3);
    short year4 = year * 10000;
    printf("year4 = %d\n", year4);
    printf("sizeof(short) = %lu\n", sizeof(short));
    return 0;
}