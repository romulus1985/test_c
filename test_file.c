#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

void mymkdir(const char* path)
{
    int ret = access(path, F_OK);
    int err = errno;
    if(err)
    {
        const int mode = S_IRWXU | S_IRWXG | S_IRWXO;
        ret = mkdir(path, mode);
        err = errno;
        if(ret)
        {
            printf("mkdir failed path = %s, errno = %d\n",
                path, err);
        }
        else 
        {
            printf("mkdir %s success.\n", path);
            ret = chmod(path, mode);
            if(ret)
            {
                printf("chmod failed, path = %s\n", path);
            }
            else
            {
                printf("chmod success, path = %s\n", path);
            }
        }
    }
    else
    {
        printf("path = %s access ok\n", path);
    }
}

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
        const int mode = S_IRWXU | S_IRWXG | S_IRWXO;
        ret = mkdir(file, mode);
        en = errno;
        if(!ret)
        {
            printf("mkdir %s success.\n", file);
        }
        else 
        {
            printf("mkdir failed file = %s, errno = %d\n",
                file, en);
        }
        //return 0;
    }
    
    ret = symlink("/home/root", "/tmp2/root");
    if(-1 == ret)
    {
        en = errno;
        printf("link result = %d, errno = %d\n", 
            ret, en);
    } 
    else
    {
        printf("link success\n");
    }
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
    mymkdir("/tmp2");
    mymkdir("/tmp2/test");
    testLink();
    //testFopen();
    return 0;
}