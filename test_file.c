#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

void testLink()
{
    //int ret = symlink("/home/root", "/work/root");
    const char* file = "/tmp2/test";
    int ret = access(file, F_OK);
    int en = errno;
    if(!ret) 
    {
        printf("%s exist.\n", file);
    }
    else
    {
        printf("%s not exist. errno = %d\n", 
            file, en);
        const int mode = S_IRWXU | S_IRWXG | S_IROTH;
        ret = mkdir(file, mode);
        if(!ret)
        {
            printf("mkdir %s success.\n", file);
        }
        //return 0;
    }
    
    ret = symlink("/home/root", "/tmp2/root");
    en = errno;
    printf("link result = %d, errno = %d\n", 
        ret, en);
}

void testFopen()
{
   FILE *fp;
   fp = fopen("test.txt", "w"); // w, after open, only can write
   //fp = fopen("testt.txt", "w+"); // w+, after open, can write and read
   fprintf(fp, "1This is testing for fprintf...\n");
   fprintf(fp, "2This is testing for fprintf...\n");

   fseek(fp, 0, SEEK_END);
   long lSize = ftell(fp);
   rewind(fp);

   char* buf = (char*)malloc(sizeof(char) * lSize);
   size_t read_size = fread(buf, 1, lSize, fp);
   // if fopen with w, read_size is always 0
   printf("read_size = %ld\n", read_size); 
   if (read_size != lSize) {
    fputs("Reading Error\n", stderr);
    exit(3);
   }
   printf("Reading Result:\n%s\n", buf); 
   fclose(fp);
   free(buf);
}

int main(int argc, char *argv[])
{
    //testLink();
    testFopen();
    return 0;
}