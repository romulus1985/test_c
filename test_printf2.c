#include <stdio.h>
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

int main(int argc, char *argv[])
{
    printf("i=%11d\n", 1);
    printf("i=%011d\n", 1);

    char test[20] = {0};
    char *a = "123";
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

    char d[3][4] = {0};
    printf("sizeof(c) = %ld\n", sizeof(d));
    return 0;
}
