#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <cstdio>

uint32_t my_ntohs2(uint32_t n) {
    return (n&0xFF000000)>>24 |(n&0x00FF0000)>>8| (n&0x0000FF00)<<8| (n&0x000000FF)<<24;
}

int main(int argc, char *argv[]){
    FILE *fd, *fd2;
    fd = fopen(argv[1],"r");
    fd2 = fopen(argv[2], "r");

    char bytes[4];
    uint32_t n1;
    fgets(bytes, 4, fd);
    n1 = ((n1&0xFF000000)>>24 |(n1&0x00FF0000)>>8| (n1&0x0000FF00)<<8| (n1&0x000000FF)<<24);

    char bytes2[4];
    uint32_t n2;
    fgets(bytes2, 4, fd2);
    n2 = ((n2&0xFF000000)>>24 |(n2&0x00FF0000)>>8| (n2&0x0000FF00)<<8| (n2&0x000000FF)<<24);

    uint32_t n3;
    n3 = n1 + n2;
    printf("32bit sum = 0x%x", n3);


    fclose(fd);
    fclose(fd2);

}
