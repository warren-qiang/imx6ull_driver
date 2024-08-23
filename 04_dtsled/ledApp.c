#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"

#define LEDOFF 0 
#define LED_ON 1

int main(int argc, int **argv)
{
    int fd = 0;
    int retvalue = 0;
    char *filename = NULL;
    unsigned char databuf[1];

    if(argc != 3){
        printf("Error Usage!\r\n");
        return -1;
    }
    filename = argv[1];
    fd = open(filename, O_RDWR);
    if(fd < 0){
        printf("faile %s open failed!\r\n", filename);
        return -1;
    }
    databuf[0] = atoi(argv[2]);
    retvalue = write(fd, databuf, sizeof(databuf));
    if(retvalue < 0){
        printf("LED Control Failed!\r\n");
        close(fd);
        return -1;
    }
    retvalue = close(fd);
    if(retvalue < 0){
        printf("file %s close failed!\r\n", filename);
        return -1;
    }
    return 0;
}