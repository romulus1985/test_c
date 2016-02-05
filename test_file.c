#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
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
        return 0;
    }
    
    ret = symlink("/home/root", "/tmp2/root");
    en = errno;
    printf("link result = %d, errno = %d\n", 
        ret, en);
    return 0;
}