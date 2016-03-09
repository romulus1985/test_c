#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define elementIdLength 6	
char videoFilePrefix[30] = "/resource/ADV/DVB/panda_vid_";

void PAD_AD_GetVideoFileName(const unsigned short element_id,
    char *fileName)
{
    char eleIdStr[elementIdLength] = {0};
    sprintf(eleIdStr, "%d", element_id);
    strcpy(fileName, videoFilePrefix);
    strcat(fileName, eleIdStr);
    printf("%s, fileName = %s\n",
        __func__, fileName);
}

void charArrayTest(char *p)
{
    printf("%s, p = %p\n",
        __func__, p);
}

//void charArrayTest2(char p[][4])
void charArrayTest2(char (*p)[5])
//void charArrayTest2(char *p[])
{
    printf("%s, p[0] = %p, p[1] = %p\n", 
        __func__, p[0], p[1]);
}

void pointTest()
{
    char test[20] = {0};
    const char *a = "123";
    int b = 4567;
    char bStr[4] = {0};
    //sprintf(test, "123");
    //sprintf(test, "4567");
    sprintf(bStr, "%d", b);
    strcpy(test, a);
    strcat(test, bStr);
    printf("test = %s\n", test);

    char videoFile[sizeof(videoFilePrefix) + sizeof(elementIdLength)] = {0};
    PAD_AD_GetVideoFileName(444,
        videoFile);

    char c[3] = {0};
    printf("c = %s\n", c);
    if(NULL == c)
    {
        printf("c == NULL\n");
    }
    else
    {
        printf("c != NULL\n");
        if('\0' == *c)
        {
            printf("*c == NULL\n");
        }
        else
        {
            printf("*c != NULL\n");
        }
    }

    char d[3][5] = {0};
    printf("sizeof(c) = %ld\n", sizeof(d));
    charArrayTest(d[0]);
    printf("d[0] = %p\n", d[0]);
    printf("d[1] = %p\n", d[1]);
    charArrayTest2(d);
    char *p[3];
    char (*p2)[5];
    char (*p3)[];
    printf("d = %p, d[0] = %p\n", d, d[0]);
    //p = d; // error
    printf("p[0] = %p, p[1] = %p\n", p[0], p[1]);
    p2 = d;
    printf("p2[0] = %p, p2[1] = %p\n", p2[0], p2[1]);
    //p3 = d;
    //printf("p3[0] = %p, p3[1] = %p\n", p3[0], p3[1]);
    char e[5][6];
    char (*f)[6];
    f = e;
}

// use g++ to compile
void referTest(int & n)
{
    n = 2;
}

int main(int argc, char *argv[])
{
    printf("i=%11d\n", 1);
    printf("i=%011d\n", 1);
    pointTest();

    const char *a = "abc";
    printf("a[0] = %c, a[1] = %c, a[2] = %c, a[3] = %c, a[4] = %c\n", 
        a[0], a[1], a[2], a[3], a[4]);
    printf("sizeof(a) = %ld, strlen(a) = %ld, sizeof(int) = %ld, sizeof(int*) = %ld\n",
        sizeof(a), strlen(a), sizeof(int), sizeof(int*));
    if('\0' == 0)
    {
        printf("\'\\0\' == 0\n");
    }
    else
    {
        printf("\'\\0\' != 0\n");
    }
    printf("int 0 = %d, char 0 =%cbb\n",
        0, 0);

    printf("sizeof(char) = %ld\n", sizeof(char));
    char *p = (char*)malloc(3 * sizeof(char));
    strcpy(p, "abcd");
    printf("p = %s\n", p);
    free(p);

    int b = 3;
    printf("a = %d\n", b);
    referTest(b);
    printf("after referTest, a = %d\n", b);
    return 0;
}
