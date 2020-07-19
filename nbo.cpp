#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <cstdio>

int main(int argc, char *argv[]){
    FILE *fd, *fd2;
    fd = fopen(argv[1],"r");
    fd2 = fopen(argv[2], "r");

    uint32_t n1 = 0;
    while(feof(fd) == 0){
        fread(&n1, 4, 1, fd);
    }

    uint32_t n2 = 0;
    while(feof(fd2) == 0){
        fread(&n2, 4, 1, fd2);
    }

    n1 = ((n1&0xFF000000)>>24 |(n1&0x00FF0000)>>8| (n1&0x0000FF00)<<8| (n1&0x000000FF)<<24);
    n2 = ((n2&0xFF000000)>>24 |(n2&0x00FF0000)>>8| (n2&0x0000FF00)<<8| (n2&0x000000FF)<<24);

    uint32_t n3;
    n3 = n1 + n2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1,n1,n2,n2,n3,n3);


    fclose(fd);
    fclose(fd2);
}